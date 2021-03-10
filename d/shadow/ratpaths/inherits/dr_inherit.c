#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_light(1);
    set_short("%^BOLD%^%^BLACK%^The Deep Roads%^RESET%^");
    set_property("no teleport", 1);
    set_long(query_short() + "\n" + "%^CYAN%^This tunnel is enormous, with pristine ancient %^WHITE%^masonry%^CYAN%^ forming all of its surfaces. Faded %^ORANGE%^basreliefs%^CYAN%^ on the walls depict undecipherable stories visually telling history of dwarven people. Being ancient it is nearly impossible to tell what they say nowdays. Although abandoned, worn and unmaintained, these tunnels did not crumble over the ages. Wide roads still can host an army marching through. The path is lit with glowing stone %^ORANGE%^lamps%^CYAN%^ on the ceiling.");
    set_listen("default", "%^BLUE%^Rumble of the earth resonates of the stone.");
    set_items(([
                   "masonry":"Simple but masterful masonry features stones of various shapes fit together to form regular shapes of roads, walls, ceiling and columns in this tunnel.",
                   "tunnels":"You're on the deep roads, basreliefs hint you these paths were constucted by ancient dwarves.",
                   "road":"This road still can host many people marching in the same direction, so wide it is.",
                   "ceiling":"Ceiling so far above these tunnels can host a dragon or two.",
                   "basreliefs":"These no doubt would puzzle historians, if only they were a couple of thousand years not so faded.",
                   "lamps":"These bright lamps are made of glowing stone. It is hard to say what craft powers them.",
                   ]));


}
