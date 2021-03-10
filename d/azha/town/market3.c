// Inside Market Square, Azha
// Thorn@ShadowGate
// 4/8/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit "//d/azha/town/market1";

void create()
{
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(0);
    set_exits(([
                   "north" : "/d/azha/town/market6",
                   "west" : "/d/azha/town/market2",
                   "northwest" : "/d/azha/town/market5",
                   "down":"/d/shadow/ratpaths/rooms/rp_n008_n015",
                   ]));
    set_invis_exits(({"down"}));
    set_search("default", "You notice a hatch leading down, hidden in the corner of the market.");
}

reset()
{
    ::reset();
    AOVER->setup_monsters(TO, "market");
}
