#include <std.h>
#include "../antioch.h"
inherit CVAULT;

void create()
{
    set_monsters(({ "/d/antioch/antioch2/mons/royal_guard", }), ({ roll_dice(1, 4) + 1, }), );
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_short("Oak Street");
    set_long(
        "You are at the end of %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^.\n" +
        "%^WHITE%^Right in front of you is a large palace. It has been built from large dun bricks that are sealed together with some mortar to keep the wind out. The entrance of the palace is here, and a large archway has been built. You can see the sharp spikes of a metal grate sticking out from the bottom that can be lowered at a moments notice to keep intruders out and the palace secure. Back to the south you can see the %^BOLD%^%^CYAN%^b%^RESET%^%^CYAN%^ar%^WHITE%^ and inn, and a crossroads where %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^ joins with %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^ and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^. To the west is a large %^CYAN%^gate%^WHITE%^ that leads to Holly Lane and the residential section.
"
        );
    if (query_night() == 1) {
        set_listen("default", "The sounds of drunken laughter spill" +
                   " forth from the bar to the southwest.");
    }else {
        set_listen("default", "It is respectfully quiet outside the" +
                   " palace.");
    }
    set_smell("default", "You can still smell the delicious foods" +
              " from the inn.");
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^.",
                   "palace" : "You are standing just outside this mighty palace.",
                   "inn" : "The inn is the large two story building to the southeast.",
                   ({ "bar", "tavern" }) : "There is a rather small but clean bar back" +
                   " to the south.",
                   ({ "gate", "large gate" }) : "A large gate is on the west here," +
                   " leading to Holly Lane and the residential section.",
                   ]));
    set_exits(([
                   "north" : ROOMS + "pal1",
                   "south" : ROOMS + "street24",
                   "west" : ROOMS + "street26",
               ]));
    set_door("gate", ROOMS + "street26", "west", 0);
    set_string("gate", "open", "The large gate slowly creaks open.");
}

void reset()
{
    ::reset();
    if (!present("street_light")) {
        new(OBJ + "street_light")->move(TO);
    }
}
