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
    set_long(query_short() + "\n" + "%^CYAN%^This tunnel is enormous, with wide roads that could easily host an "+
"entire army marching through. Basreliefs on the walls once depicted the history "+ 
"of the dwarven people, but they are so old and worn now, that it is nearly impossible "+
"to decipher any meaning from them. Although the tunnels have long since been abandoned, "+ 
"they still provide safe passage, and stand as a true testament to the "+ 
"mastery of the masons who built them, so many ages ago. The path is lit with %^BOLD%^glowing "+
"stone lamps%^CYAN%^ hanging from the ceiling.");set_listen("default", "%^BLUE%^Rumble of the earth resonates of the stone.");
    set_items(([
                   "masonry":"Simple but masterful masonry features stones of various shapes fit together to form the roads, walls, ceiling and columns in this tunnel.",
                   "tunnels":"You're on the deep roads. Basreliefs hint that these paths were constucted by ancient dwarves.",
                   "road":"This road is so wide, it can host many people marching in the same direction.",
                   "ceiling":"The ceiling is so far overhead, that these tunnels could host a dragon or two.",
                   "basreliefs":"These no doubt would puzzle historians. If only they were a couple of thousand years less faded.",
                   "lamps":"These bright lamps are made of glowing stones. It is hard to say what craft powers them.",
                   ]));


}
