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
    set_short("A crossroads");
    set_long(
        "%^WHITE%^You are standing at the intersection of Oak, %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^, and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^. %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e %^RED%^st%^GREEN%^r%^RED%^eet%^RESET%^ runs west and then southwest, there is a little jeweler's shop on the corner there. To the east is %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r %^ORANGE%^s%^BOLD%^%^BLACK%^tre%^RESET%^%^ORANGE%^e%^ORANGE%^t%^RESET%^, with a tailor's shop at the corner where it turns southeast. %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^ runs north and south. To the south you can see a large fountain where it joins with %^RED%^C%^RED%^h%^RED%^e%^BOLD%^%^RED%^rry%^RESET%^ %^RED%^stre%^RESET%^%^RED%^e%^BOLD%^%^RED%^t%^RESET%^  which runs east and west and has most of the shops on it. Along %^WHITE%^O%^WHITE%^a%^WHITE%^k %^WHITE%^s%^BOLD%^%^BLACK%^t%^RESET%^%^WHITE%^r%^BOLD%^%^BLACK%^eet%^RESET%^ to the north is the bar and the inn. Further north is the %^BOLD%^%^WHITE%^palace.%^RESET%^
"
        );
    set_smell("default", "The smell of alcohol mingles with the" +
              " aroma of freshly cooked food.");
    if (query_night() == 1) {
        set_listen("default", "You hear drunken laughter coming from" +
                   " the bar to the north.");
    }else {
        set_listen("default", "The clank and clatter of dishes" +
                   " comes from the inn.");
    }
    set_items(([
                   ({ "street", "cobblestones", "cobbles", "road", "path" }) : "The" +
                   " street is paved with cobblestones.",
                   "street sign" : "This is the intersection of Oak, %^GREEN%^A%^RED%^pp%^GREEN%^l%^RED%^e%^RESET%^," +
                   " and %^ORANGE%^C%^BOLD%^%^BLACK%^e%^BLACK%^d%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^.",
                   "fountain" : "There appears to be a fountain a little ways" +
                   " to the south.",
                   "palace" : "The palace is to the north.",
                   ]));
    set_exits(([
                   "west" : ROOMS + "street9",
                   "east" : ROOMS + "street11",
                   "north" : ROOMS + "street24",
                   "south" : ROOMS + "street23",
                   ]));
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
