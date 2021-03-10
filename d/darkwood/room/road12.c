//	The Royal Southern Road
//	Thorn@Shadowgate
//	10/2/94
//	Darkwood forest
//	road12
/*Updated by Circe 10/4/03 to include room name, smell, listen and to use inherits to save on memory. Also, a few rooms were added to fix the way the area looks when mapped.*/

#include <std.h>

inherit "/d/darkwood/room/road8.c";

void create() {
    ::create();
    set_long(
"%^GREEN%^You are on the Royal Southern Road entering a dark forest. The lightof the sun is almost blotted out by the near-perfect shade of the treesall round you. The thick growth of bushes beneath the trees looks as thought it might be hiding any number of unsavory creatures. Just to the southeast, it seems that the road is heading out of the forest, and the light in that direction beckons you forward.

"
    );
    set_exits(
              (["north" : "/d/darkwood/room/road11",
		//"southwest" : "/d/stella/rooms/path6",
                "southeast" : "/d/darkwood/room/road13",]) );

}
