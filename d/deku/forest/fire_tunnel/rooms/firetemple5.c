#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FIRE_TEMPI;

void create() {
    ::create();
    set_long(TO->query_long()+"%^RED%^  In the direct center of "+
    "the chamber rests a large %^RESET%^dull stone%^RED%^ pillar "+
    "with an opening in the side of it.  The chamber sprawls out in "+
    "every direction here.  %^RESET%^");
    add_items(({"pillar","dull stone pillar","stone pillar"}), "This "+
    "stone pillar stands in stark contract with rest of this entire "+
    "chamber.  It is made simply from a dull stone, it towers "+
    "higher than the rest of the pillars here and an opening "+
    "is one side of it.  You think that there might be a room "+
    "hidden within.");
    set_exits(([
       "pillar" : FTUN_ROOMS"kinordas_chamber",
       "north" : FTUN_ROOMS"firetemple8",
       "west" : FTUN_ROOMS"firetemple6",
       "east" : FTUN_ROOMS"firetemple4",
       "northeast" : FTUN_ROOMS"firetemple7",
       "northwest" : FTUN_ROOMS"firetemple9",
       "south" : FTUN_ROOMS"firetemple2",
       "southwest" : FTUN_ROOMS"firetemple3",
       "southeast" : FTUN_ROOMS"firetemple1",
    ] ));
    
}
