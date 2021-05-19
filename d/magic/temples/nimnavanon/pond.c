#include <std.h>

inherit ROOM;
int berrycount;

void create()
{
    ::create();

    berrycount = 5;

    set_property("indoors", 0);
    set_property("light", 1);
    set_travel(FRESH_BLAZE);
    set_terrain(LIGHT_FOREST);

    set_climate("temperate");
    set_short("A Quiet Pond");
    set("day long", "%^CYAN%^A quiet pond%^RESET%^\n" +
        "%^CYAN%^Tall %^ORANGE%^reeds %^CYAN%^and %^ORANGE%^morass %^CYAN%^harbor a quiet %^BOLD%^pond %^RESET%^%^CYAN%^in the center of a sheltered clearing. A natural pier of %^WHITE%^boulders %^CYAN%^allows one to walk out to where the water is clear. Giant %^GREEN%^firs %^CYAN%^allows a few strands of %^YELLOW%^sunlight %^RESET%^%^CYAN%^through the canopy, otherwise the area lies in %^BLUE%^shade%^CYAN%^. The lowest tree branches hover high above you, but a plenitude of the huge dark trunks is enough to block out the view. A well trodden %^BOLD%^%^BLACK%^path %^RESET%^%^CYAN%^winds northwards through the woods.%^RESET%^\n");
    set("night long", "%^BLUE%^A quiet pond%^RESET%^\n" +
        "%^BLUE%^Tall %^ORANGE%^reeds %^BLUE%^and %^ORANGE%^morass %^BLUE%^harbor a quiet %^BOLD%^%^CYAN%^pond %^RESET%^%^BLUE%^in the center of a sheltered clearing. A natural pier of %^WHITE%^boulders %^BLUE%^allows one to walk out to where the water is clear. Giant %^GREEN%^firs %^BLUE%^allows a glimpse of the %^YELLOW%^stars %^RESET%^%^BLUE%^through the canopy, otherwise the area is shrouded in darkness. The lowest tree branches hover high above you, but a plenitude of the huge dark trunks is enough to block out the view. A well trodden %^BOLD%^%^BLACK%^path %^RESET%^%^BLUE%^winds northwards through the woods.%^RESET%^\n");
    set_smell("default", "%^BOLD%^%^CYAN%^The fresh fragrance of pine mixes with a whiff of murky water.%^RESET%^");
    set_listen("default", "%^ORANGE%^You hear an occasional call of a bluejay, a rustling of a squirrel, and a barely audible howl in the wind.%^RESET%^");
    set_items(([
                   "path" : "%^GREEN%^The path is well defined, leading from the sacred grove to the natural pier in the pond.%^RESET%^",
                   "pier" : "%^WHITE%^The pier of boulders looks natural, unless it has been placed there by giants. The %^BLUE%^dark water %^WHITE%^makes it impossible to see how deep down it goes. The stones are dry and flat, making it easy to walk on them or kneel down by the water.%^RESET%^",
                   "forest" : "%^GREEN%^Large dark trunks blocks out the view. Evergreen firs create a thick canopy above you with little light reaching the needle-covered forest floor.%^RESET%^",
                   "bushes" : "%^RED%^Sa%^BOLD%^lm%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^%^RED%^berr%^BOLD%^y %^GREEN%^bushes grow close to the bond. Perhaps you can %^RED%^pick %^GREEN%^some.%^RESET%^",

                   ]));
    set_property("fill waterskin", 1);

    set_exits(([
                   "north" : "/d/magic/temples/nimnavanon/nimnavanon",
                   ]));
}

void init()
{
    ::init();
    add_action("drink_func", "drink");
}

int drink_func(string str)
{
    if (!str) {
        return 0;
    }
    if (str != "water from pond" && str != "from pond") {
        return 0;
    }
    if (!TP->add_quenched(20)) {
        return notify_fail("Your stomach is sloshing already!\n");
    }
    tell_object(TP, "The cool water tastes surprisingly fresh and you feel refreshed and rejuvenated.");
    tell_room(TO, TPQCN + " drinks water from the pond.", TP);
    return 1;
}

void reset()
{
    string season;
    season = season(time());

    ::reset();

    switch (season) {
    case "winter":
        add_item("pond",
                 "%^CYAN%^The edges of the pond have %^BOLD%^%^WHITE%^frozen%^RESET%^%^CYAN%^, capturing the reeds in %^BOLD%^%^WHITE%^ice%^RESET%^%^CYAN%^. But in the center the water is clear, its surface calm and dark. %^BOLD%^Your face %^RESET%^%^CYAN%^looks back at you, framed by the shady canopy of the firs.%^RESET%^");
        break;
    default:
        add_item("pond",
                 "%^CYAN%^The quiet pond seems %^ORANGE%^murky %^CYAN%^along the edges where %^ORANGE%^reeds %^CYAN%^grow in abundance. But in the center the water is clear as %^BOLD%^crystal%^RESET%^%^CYAN%^, its surface calm and dark. %^YELLOW%^Your face %^RESET%^%^CYAN%^looks back at you, framed by the shady canopy of the firs.%^RESET%^");
        break;
    }
}

int pick(string str)
{

    string season;
    season = season(time());

    switch (season) {
    case "winter":
        tell_object(TP, "You don't find anything worth picking. Try again in a different season.");
        return 1;
    case "spring":
        if (str != "berries") {
            tell_object(TP, "The only thing that appears worth picking here is some berries.");
            return 1;
        }
        tell_object(TP, "The berries are not ripe.");
        return 1;

    default:
        if (str != "berries") {
            tell_object(TP, "The only thing that appears worth picking here is some berries.");
            return 1;
        }

        if (berrycount < 1) {
            tell_object(TP, "All the berries have been picked already.");
            return 1;
        }else {
            tell_object(TP, "You pick a handful of ripe salmonberries.");
            tell_room(ETP, "" + TP->query_cap_name() + " picks a handful of ripe salmonberries.", TP);
            berrycount -= 1;
            new("/d/magic/temples/nimnavanon/strawberries.c")->move(TP);
            if (berrycount < 1) {
                add_item("bushes", "%^RED%^Sa%^BOLD%^lm%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^%^RED%^berr%^BOLD%^y %^GREEN%^bushes grow close to the pond, but they have been picked clean.%^RESET%^");
            }
            return 1;
        }
    }
}
