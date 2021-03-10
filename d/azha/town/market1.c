// Inside Market Square, Azha
// Thorn@ShadowGate
// 4/8/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create()
{
    room::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_light(2);
    set_indoors(0);
    set_short("%^BOLD%^%^MAGENTA%^Inside Market Square, %^ORANGE%^Azha");
    set_long(
        query_short() + "
%^RESET%^%^ORANGE%^All around you are people haggling, trading and just admiring some of the things in the colorful %^MAGENTA%^booths%^ORANGE%^ sprawed all around you. Merchants are shouting to you and whoever else will listen, about thequality or the exquisiteness of their particular works. Its amiracle that you can hear yourself think in this strange place. The market wall prevents movement out of the market.\n"
        );
    set_exits(([
                   "north" : "/d/azha/town/market4",
                   "east" : "/d/azha/town/market2",
                   "northeast" : "/d/azha/town/market5",
                   ]));
    set_smell("default", "The smells here are so strong and varied that they overwhelm you.");
    set_items(([
                   "booths" : "The booths are of many shapes: tents, wooden stalls, or sometimes just piles of goods, marked by a sign.\n",
                   ]));
}

reset()
{
    ::reset();
    AOVER->setup_monsters(TO, "street");
}
