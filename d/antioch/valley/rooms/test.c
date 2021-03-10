#include <std.h>
#include "../valley.h"
inherit CROOM;
int FLAG;
object ob;

void create (){
set_monsters(({"/realms/crystal/diamond.c"}),({1}));
::create ();
FLAG = 0;
set_property ("light", 1);
set_short("Intersection");
set_long("%^RESET%^     This is the city center of Oakbural.  A lot of activity can "+
"be seen.  The gnomes of this village seem to wander around in a perfectly organized "+
"choas.  The %^GREEN%^walls%^RESET%^ and %^YELLOW%^buildings%^RESET%^ are packed closely "+
"together.  %^ORANGE%^Copper tubes%^RESET%^ join between each home and store.  A steam "+
"driven pump is in the center of town.  Farther north you can see great cogs at work.");

set_smell("default", "The heated air smells stail and none too refreshing.");
set_listen("default", "You hear the hissing and crashing.");
set_items(([
"tubes" : "   A good part of the wall is covered in this tubing.  It seems to extend to all parts of town.",
"steam" : "   Some of the copper tubing is leaking, the steam appears to be escaping from them.",
"gnomes" : "   Yep, they are gnomes alright.  Hey!  That one has a big nose!",
"walls" : "   The walls are mix of pipe, stone, and wood.  Very odd.",
"buildings" : "   The buildings are smaller versions of the ones you have seen in shadow.  Most are made of wood.",
"cogs" : "   The great gears of some machine can be seen to the north.",
]));
set_exits( ([
"north" : ROOMS+"oak8.c",
"southwest" : ROOMS+"oak3.c",
"southeast" : ROOMS+"oak4.c",
"south" : ROOMS+"oak1.c",
]) );
}

