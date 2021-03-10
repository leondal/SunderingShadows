#include <daemons.h>
#include <clock.h>
#include <astronomy.h>

#define DEFAULT_MSG "You do not see that here.\n"

/**
 * @file
 * @brief Functions that handle astronomy calculations
 */

nosave mapping moons;
nosave mapping moonstate, moonphase, moonorbit;
nosave string* moonphases;
int in_eclipse;

/**
 * Map with moons
 * name:description
 */
moons = (["sera" : "%^BOLD%^%^WHITE%^silvery moon",
          "tyrannos" : "%^BOLD%^%^BLACK%^pitch black moon%^RESET%^"]);

/**
 * Argument is time()
 * 0 new moon, 7 is full moon
 */
moonphase = ([
                 "sera" : (: to_int((-abs(CURRENT_DAY($1) - 12) / 12.0 + 1) * 7) :),
             "tyrannos" : (: 4 :),
    ]);

/**
 * Argument is time()
 */
moonvisibility = (["sera" : (: (CURRENT_HOUR($1) < 5 || CURRENT_HOUR($1) > 15) :),
                   "tyrannos" : (: (!(CURRENT_DAY($1) % 3)) :)]);

moonillumination = (["sera":1, "tyrannos":0]);

/**
 * Moon phases indexed by [0:7]. If you want custom moon phases for specific moon, well, good luck.
 */
moonphases = ({ "new",
            "waxing crescent",
            "first quarter",
            "waxing gibbous",
            "full",
            "waning gibbous",
            "last quarter",
            "waning crescent",
            "new" });

void create()
{
    seteuid(getuid());
}

/**
 * Returns numeric moon phase for the moon on a scale [0:7]
 *
 * @param moon Moon name
 * @return Moonphase ∈ [0:7]
 */
int query_moon_phase(string moon)
{
    return evaluate(moonphase[moon],
                    time());
}

/**
 * Returns moon visibility assuming horizon is at h=0 rad (which makes
 * orbital inclination irrelevant)
 *
 * @param moon Moon name
 * @return 0|1
 */
int is_moon_visible(string moon)
{
    return evaluate(moonvisibility[moon], time());
}

/**
 *
 *
 */
int query_moon_illumination(moon){
    return is_moon_visible(moon) ? moonillumination[moon] : 0;
}

/**
 * Return moon phase string for the moon
 *
 * @param moon Moon name
 * @return Phase name
 */
string query_moon_phase_string(string moon)
{
    return moonphases[query_moon_phase(moon)];
}

/**
 * This function returns total moonlight.
 * It is used in calculating outside room illumination during the night.
 *
 * @return Moon light value in mud illumination units.
 */
int query_moon_light()
{
    string moon;
    float light;
    int night;

    night = query_night() || query_eclipse();

    if (!night) {
        return 0;
    }

    light = 0;

    foreach(moon in keys(moons))
    {
        light += query_moon_illumination(moon);
    }

    return to_int(round(light));
}

/**
 * This function sets eclipse flag. Anything can be a cause.
 */
void set_eclipse()
{
    in_eclipse = 1;
    call_out("remove_eclipse", 900);//cap if causer forgets cleanup
}

/**
 * This function removes eclipse flag
 */
void remove_eclipse()
{
    in_eclipse = 0;
    message("info", "%^BOLD%^%^BLACK%^The %^WHITE%^eclipse%^BLACK%^ is over!%^BOLD%^%^BLACK%^\n", users());
}

/**
 * This function checks whether eclipse is on
 */
int query_eclipse()
{
    return in_eclipse;
}

/**
 * This function is called from room object default items, /std/room/items
 *
 * @param str Argument of the look command.
 * @return Sky description
 */
string la_sky(string str)
{
    string tod;
    string* phase;
    int ansi, i;

    if (environment(this_player())->query_property("indoors")) {
        return DEFAULT_MSG;
    }
    return basicsky(str);
}

/**
 * Primitive sky description function
 *
 * @param str Argument fo the look command.
 * @return Sky description
 */
string basicsky(string str)
{
    string borg;
    int night, tmp;

    night = query_night() || query_eclipse();

    if (WEATHER_D->query_clouds(TP) > 3) {
        borg = (night?"%^BLUE%^":"%^BLUE%^%^BOLD%^") + "The sky is covered with dense clouds.%^RESET%^";
    }else {
        switch (str) {
        case "sky":
            if (night) {
                string moon;
                borg = "%^BLUE%^You see a dark night sky.\n";
                if (in_eclipse) {
                        borg = "%^BOLD%^%^BLACK%^The sky is dark, Tyrannos shades the Sun in %^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^clips%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^.\n";
                }
                foreach(moon in keys(moons))
                    if (is_moon_visible(moon)) {
                        borg += "%^RESET%^%^BLUE%^You see a " + query_moon_phase_string(moon) + " " + moons[moon] + ".\n";
                    }
            }else {
                borg = "%^ORANGE%^You see the s%^BOLD%^u%^RESET%^%^ORANGE%^n up in the sky.%^RESET%^";
            }
            break;
        case "stars":
            if (night) {
                if (TP->query_race() == "satyr") {
                    borg = "%^BOLD%^%^WHITE%^The stars wink playfully at you.%^RESET%^";
                }else {
                    borg = "%^BOLD%^%^WHITE%^You see some stars, and they shine.%^RESET%^";
                }
            }else {
                borg = "What stars, baka? It is daytime.";
            }
            break;
        case "sun":
            if (!night) {
                tmp = (int)EVENTS_D->query_hour(time());
                if (tmp < 10) {
                    borg = "%^RED%^The sun hangs low in the eastern sky.%^RESET%^";
                }else if (tmp < 10) {
                    borg = "%^ORANGE%^The sun is midway up in the eastern sky.%^RESET%^";
                }else if (tmp < 14) {
                    borg = "%^WHITE%^The sun is high up in the noon sky.%^RESET%^";
                }else if (tmp < 16) {
                    borg = "%^ORANGE%^The sun is midway up in the western sky.%^RESET%^";
                }else {
                    borg = "%^RED%^The sun hangs low in the western sky.%^RESET%^";
                }
            }else {
                borg = "What sun?";
            }
            break;
        case "moon": case "moons":
        {
            string moon, skycolor;
            borg = "";
            skycolor = night?"%^BLUE%^":"%^WHITE%^";
            foreach(moon in keys(moons))
                if (is_moon_visible(moon)) {
                    borg += "%^RESET%^" + skycolor + "You see a " + query_moon_phase_string(moon) + " " + moons[moon] + "%^RESET%^" + skycolor + ", known as " + capitalize(moon) + ".%^RESET%^\n";
                }
            if (borg == "") {
                borg += "No moon is seen";
            }
        };
            break;
        case "sera":
            if (is_moon_visible("sera")) {
                borg = "%^BOLD%^%^WHITE%^Sera shines " + query_moon_phase_string("sera") + ".%^RESET%^";
            }else {
                borg = DEFAULT_MSG;
            }
            break;
        case "tyrannos":
            if (is_moon_visible("tyrannos")) {
                borg = "%^BOLD%^%^BLACK%^Tyrannos glooms over in the sky.%^RESET%^.";
            }else {
                borg = DEFAULT_MSG;
            }
            break;
        }
    }
    return borg;
    say(TPQCN + " looks at the " + str + ".");
}

int clean_up()
{
    return 0;
}
