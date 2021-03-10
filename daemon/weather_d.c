// restored copy from 14 Aug 2011, as the new version was not functioning.
// I will replace the new version again if/when I can get it to work. N, 12/12.
#include <daemons.h>
#include <security.h>
#include <std.h>

inherit DAEMON;

#define SAVE_WEATHER "/daemon/save/weather"
#define WEATHER ({ "clear", "partly cloudy", \
                   "mostly cloudy", "very cloudy", \
                   "lightly", "moderately", "heavily" })
// correcting spelling of arctic (was "artic" several places) *Styx* 1/16/04, last change 8/9/01
#define CLIMATES ({ "arctic", "temperate", "tropical", "mountain", "desert" })
#define TOD "daemon/events_d"->query_time_of_day()
mapping __CLIMATE;
mapping __WEATHER;
int max_weather;

void Do_Weather();
void Check_Weather(object ob);
void adjust_weather(string temp);
void set_climate(string str, object ob);
string query_weather();
string get_zone(object ob);
void setup();

void create()
{
    seteuid(UID_DAEMONSAVE);
    __CLIMATE = ([]);
    restore_object(SAVE_WEATHER);
    if (!__WEATHER) {
        setup();
    }
    save_object(SAVE_WEATHER);
    call_out("Do_Weather", 200);
}

void setup()
{
    string names;
    int inc;

    __WEATHER = ([]);
    names = keys(__CLIMATE);
    for (inc = 0; inc < sizeof(names); inc++) {
        __WEATHER[names[inc]] = 0;
    }
}

void weather()
{
    //string tempcondition;
    //tempcondition = "\n %^BOLD%^%^BLACK%^A chaotic elemental storm of %^RESET%^%^ORANGE%^Earth%^BOLD%^%^BLACK%^, %^BOLD%^%^WHITE%^Wind%^BOLD%^%^BLACK%^, %^BOLD%^%^RED%^Fire%^BOLD%^%^%^BLACK%^, and %^BOLD%^%^BLUE%^Water %^BOLD%^%^BLACK%^%^scorches the sky!%^RESET%^\n\n %^BOLD%^%^BLACK%^The world is plunged into eternal night!%^RESET%^";
    restore_object(SAVE_WEATHER);

    write("%^BOLD%^%^GREEN%^ Time of Day    %^RESET%^%^GREEN%^: %^YELLOW%^" + capitalize(TOD));
    write("%^BOLD%^%^GREEN%^ Climate        %^RESET%^%^GREEN%^: %^YELLOW%^" + capitalize(get_climate(TP)));
    write("%^BOLD%^%^GREEN%^ Season         %^RESET%^%^GREEN%^: %^YELLOW%^" + capitalize(season(time())));
    write("%^BOLD%^%^GREEN%^ Weather        %^RESET%^%^GREEN%^: " + get_weather(TP));
    write("%^BOLD%^%^GREEN%^ Temperature    %^RESET%^%^GREEN%^: %^RED%^" + get_temp(TP));
    //write(tempcondition); //added for Kismet's climate change plot - Odin 4/1/2020

    return;
}

string get_climate(object obj)
{
    string temp;
    temp = get_zone(obj);
    return __CLIMATE[temp];
}

string get_weather(object obj)
{
    string weather;
    weather = Check_Weather(obj);
    if (!weather) {
        weather = "You are indoors";
    }
    return weather;
}

int get_temp(object obj)
{
    string temp;
    int temperature;
    int modifier;     //adjustable for plots
    modifier = 0;     //set at 10 for Kismet's climate change plot

    temp = get_zone(obj);
    if (!__CLIMATE) {
        return 0;
    }
    if (!__WEATHER) {
        return 0;
    }

    if (member_array(temp, keys(__CLIMATE)) == -1) {
        temp = "STANDARD";
    }

    switch (__CLIMATE[temp]) {
    case "temperate": temperature = 70 + modifier; break;

    case "tropical": temperature = 85 + modifier; break;

    case "desert": temperature = 100 + modifier; break;

    case "arctic": temperature = 20 + modifier; break;

    case "mountain": temperature = 50 + modifier; break;

    default: break;
    }
    switch (season(time())) {
    case "summer": temperature += 5; break;

    case "autumn": temperature -= 20; break;

    case "winter": temperature -= 35; break;

    case "spring": temperature -= 15; break;

    default: break;
    }

    return temperature;
}

string get_zone(object ob)
{
    string files, * temp, path;
    int number, inc;
    path = "";
    inc = -1;
    if (ob->is_room()) {
        files = file_name(ob);
    }else {
        files = file_name(environment(ob));
    }
    temp = explode(files, "/");
    number = sizeof(temp) - 2;
    while (inc++ < number) {
        path += temp[inc] + "/";
    }
    return path;
}

void saveit()
{
    save_object(SAVE_WEATHER, 1);
}

void set_climate(string str, object ob)
{
    string temp;
    restore_object(SAVE_WEATHER);
    if (!__CLIMATE) {
        __CLIMATE = ([]);
    }
    if (member_array(str, CLIMATES) == -1) {
        return;
    }
    temp = get_zone(ob);
    if (temp == "d/standard/") {
        return;
    }
    __CLIMATE[temp] = str;
    __WEATHER[temp] = 0;
    save_object(SAVE_WEATHER);
    return;
}

mixed query_climate()
{
    return __CLIMATE;
}

mixed Check_Weather(object ob)
{
    string temp;
    restore_object(SAVE_WEATHER);
    temp = get_zone(ob);
    if (member_array(temp, keys(__CLIMATE)) == -1) {
        set_climate("temperate", ob);
    }
    if (environment(ob)->query_property("indoors")) {
        return 0;
    }
    if (environment(ob)->query_weather()) {
        return environment(ob)->query_weather();
    }
// adding special weather for deserts, seldom getting anything but dry *Styx* 1/16/04
    if (__CLIMATE[temp] == "desert") {
        if (random(20)) {
            return "%^BOLD%^%^WHITE%^It is oppressively hot and dry.";
        }else
        if (__WEATHER[temp] > 3) {
            return "%^BOLD%^%^BLUE%^It is raining " + WEATHER[__WEATHER[temp]] + ".%^RESET%^";
        }else {
            return "%^BOLD%^%^CYAN%^It is " + WEATHER[__WEATHER[temp]] + ".";
        }
    }
    if (__WEATHER[temp] > 3) {
        if ((season(time()) == "winter") || (__CLIMATE[temp] == "arctic") || (season(time()) == "autumn" && __CLIMATE[temp] == "mountain")) {
            return "%^BOLD%^%^WHITE%^It is snowing " + WEATHER[__WEATHER[temp]] + ".%^RESET%^";
        }else {
            return "%^BOLD%^%^BLUE%^It is raining " + WEATHER[__WEATHER[temp]] + ".%^RESET%^";
        }
    } else {
// fixed to correct spelling from "artic" 1/16/04
        if (__CLIMATE[temp] == "arctic") {
            return "%^BOLD%^%^CYAN%^It is very cold and " + WEATHER[__WEATHER[temp]] + ".";
        }else {
            return "%^BOLD%^%^CYAN%^It is " + WEATHER[__WEATHER[temp]] + ".";
        }
    }
}

int query_clouds(object ob)
{
    string temp;
    if (!objectp(ob)) {
        return 0;
    }
    temp = get_zone(ENV(ob));
    return __WEATHER[temp];
}

void Do_Weather()
{
    string temp, * thekeys;
    mixed* pair;
    int inc;

    restore_object(SAVE_WEATHER);
    if (!__WEATHER) {
        return;
    }
    if (TO->query_weather()) {
        return;
    }
    thekeys = keys(__CLIMATE);
    for (inc = 0; inc < sizeof(thekeys); inc++) {
        switch (__CLIMATE[thekeys[inc]]) {
        case "temperate": {
            max_weather = 6;
            if (random(100) < 101) {
                adjust_weather(thekeys[inc]);
            }
            break;
        }

        case "arctic": {
            max_weather = 6;
            if (random(100) < 40) {
                adjust_weather(thekeys[inc]);
            }
            break;
        }

        case "mountain": {
            max_weather = 6;
            if (random(100) < 60) {
                adjust_weather(thekeys[inc]);
            }
            break;
        }

        case "tropical": {
            max_weather = 6;
            if (random(100) < 80) {
                adjust_weather(thekeys[inc]);
            }
            break;
        }

        case "desert": {
            max_weather = 2;
            if (random(100) < 10) {
                adjust_weather(thekeys[inc]);
            }
            break;
        }

        default: break;
        }
    }

    save_object(SAVE_WEATHER);
    call_out("Do_Weather", 60);
}

void adjust_weather(string temp)
{
    int tmp;
    switch (season(time())) {
    case "summer": tmp = 3; break;

    case "autumn": tmp = 5; break;

    case "winter": tmp = 4; break;

    case "spring": tmp = 5; break;

    default: return;
    }
    if (random(10) < tmp) {
        if (__WEATHER[temp] == max_weather) {
            __WEATHER[temp]--; return;
        }
        __WEATHER[temp]++;
    }else {
        if (__WEATHER[temp] == 0) {
            return;
        }
        __WEATHER[temp]--;
    }
}

int clean_up()
{
    return 0;
}
