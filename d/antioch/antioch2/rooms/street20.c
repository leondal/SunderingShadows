#include <std.h>
#include "../antioch.h"
inherit CVAULT;

void create()
{
    set_monsters(({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1, }), );
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors", 0);
    set_property("light", 2);
    set_short("%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ Street");
    set_long(
        "%^ORANGE%^You are on %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^\n" +
        "%^ORANGE%^This is the main street through town and there are lots of %^BOLD%^%^BLACK%^shop%^WHITE%^s%^RESET%^%^ORANGE%^ on it. There is even a little bank back to the west, just south of the large %^CYAN%^fo%^BOLD%^%^CYAN%^u%^CYAN%^n%^RESET%^%^CYAN%^t%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^in%^BOLD%^%^CYAN%^.%^RESET%^%^ORANGE%^ To the north there is a weapons shop, with a sign hanging over the doorway with a picture of a serrated mace on it. To south is the shop of an armorer with a sign declaring it the Silver Gauntlet. At the end of the street to the east there is a very large and beautiful %^BOLD%^%^ORANGE%^church.%^RESET%^%^ORANGE%^ Just in front of the church %^ORANGE%^Crescent%^RESET%^ and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^ intersect with %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^. %^BOLD%^%^ORANGE%^C%^RESET%^%^ORANGE%^re%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^c%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^ORANGE%^t%^RESET%^ %^ORANGE%^street%^WHITE%^ runs to the southwest towards the Antioch gates, and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^ runs to the northwest to meet with %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^. %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^ runs from the fountain straight north to the palace.
"
        );
    set_smell("default", "The smell of oil is thick in the air.");
    if (query_night() == 1) {
        set_listen("default", "The gentle gurgling of the fountain" +
                   " is all that can be heard.");
    }else {
        set_listen("default", "The sounds of shoppers haggling" +
                   " for better prices surrounds you.");
    }
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is %^MAGENTA%^%^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^ %^RESET%^",
                   "fountain" : "There is a large fountain to the west.",
                   "church" : "A very impressive stone church sits at the eastern" +
                   " end of this street.",
                   "shops" : "There are many shops on this street.",
                   ]));
    set_exits(([
                   "west" : ROOMS + "fountain",
                   "east" : ROOMS + "street21",
                   "north" : ROOMS + "weapon",
                   "south" : ROOMS + "armor",
                   ]));
    set_door("oak door", ROOMS + "weapon", "north", 0);
    set_door("cherry door", ROOMS + "armor", "south", 0);
    if (query_night() == 1) {
        set_open("cherry door", 0);
        set_open("oak door", 0);
        "/d/antioch/antioch2/rooms/armor"->set_open("cherry door", 0);
        "/d/antioch/antioch2/rooms/weapon"->set_open("oak door", 0);
    }else if (query_night() != 1) {
        set_open("cherry door", 1);
        set_open("oak door", 1);
        "/d/antioch/antioch2/rooms/armor"->set_open("cherry door", 1);
        "/d/antioch/antioch2/rooms/weapon"->set_open("oak door", 1);
    }
}

void reset()
{
    ::reset();
    if (!present("street_light")) {
        new(OBJ + "street_light")->move(TO);
    }
    if (query_night() == 1) {
        return;
    }else if (!present("citizen")) {
        switch (random(4)) {
        case 0:
            new(MONS + "citizen1")->move(TO);
            break;
        case 1:
            new(MONS + "citizen2")->move(TO);
            break;
        case 2:
            new(MONS + "citizen3")->move(TO);
            break;
        case 3:
            new(MONS + "citizen4")->move(TO);
            break;
        }
    }
}
