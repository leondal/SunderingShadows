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
                   "north" : "/d/azha/town/market5",
                   "east" : "/d/azha/town/market3",
                   "west" : "/d/azha/town/market1",
                   "northeast" : "/d/azha/town/market6",
                   "northwest" : "/d/azha/town/market4",
                   ]));
    set_items(([
                   "booths" : "The booths are of many shapes: tents, wooden stalls, or sometimes just piles of goods, marked by a sign.\n",
               ]));
}

void init()
{
    ::init();
    if (!present("ginaratha", TO)) {
        find_object_or_load("/d/npc/ginaratha")->move(TO);
    }
}
