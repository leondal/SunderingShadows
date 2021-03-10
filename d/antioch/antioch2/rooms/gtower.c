#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("A guard tower");
    set_long(
        "%^WHITE%^You are inside a large stone guard tower. %^ORANGE%^B%^ORANGE%^e%^ORANGE%^n%^ORANGE%^c%^ORANGE%^h%^ORANGE%^es%^WHITE%^ and %^ORANGE%^t%^ORANGE%^a%^ORANGE%^b%^ORANGE%^le%^ORANGE%^s%^WHITE%^ have been set up around the room and there is a locked rack of weapons and armor on the back wall. It is only filled with basic equipment, spare gear for any of the guards who lose theirs. There are large stone %^BOLD%^%^BLACK%^steps%^RESET%^%^WHITE%^ that wind up to the second floor of the guard tower, curving out of sight. %^BOLD%^%^ORANGE%^O%^RESET%^%^ORANGE%^i%^BOLD%^%^ORANGE%^l %^ORANGE%^lamps%^RESET%^%^WHITE%^ are kept lit around the room, keeping it bright at all times.
"
        );
    set_smell("default", "The sweat of soldiers permeats the room.");
    set_listen("default", "The guards are idly chatting.");
    set_items(([
                   ({ "table", "tables" }) : "There are wooden tables scattered around" +
                   " the room for the guards to eat at or play cards on.",
                   ({ "bench", "benches" }) : "Several wooden benches are placed here" +
                   " for the guards to sit down on and rest their tired legs.",
                   ({ "chair", "chairs" }) : "Comfortable looking wooden chairs are" +
                   " placed near the tables for the guards to sit on.",
                   ({ "lamp", "lamps", "oil lamp", "oil lamps" }) : "There are many oil" +
                   " lamps on the walls about the room, always kept lit in case of" +
                   " any emergency.",
                   ({ "steps", "stairs", "stone steps" }) : "Large stone steps lead up" +
                   " to the second floor, curving around and out of sight.",
               ]));
    set_exits(([
                   "west" : ROOMS + "street2",
                   "stairs" : ROOMS + "gtower2",
               ]));
}
