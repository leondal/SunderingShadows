//	The Royal Southern Road
//	Thorn@Shadowgate
//	10/9/94
//	Darkwood forest
//	road13
/*Updated by Circe 10/4/03 to include room name, smell, listen and to use inherits to save on memory. Also, a few rooms were added to fix the way the area looks when mapped.*/

#include <std.h>

inherit "/d/darkwood/room/road8.c";

void create() {
    ::create();
    set_light(2);
    set_long(
"%^GREEN%^You are on the Royal Southern Road. To the northwest, the road takes a path straight through the heart of the forest, while eastward the trees lighten. From what you can tell, the forest is filled with a mixture ofconiferous and deciduous trees that seem to form a perfect canopy. The forest looks unusually dark inside thanks to the cover of the trees.
"
    );
    set_exits(
              (["northwest" : "/d/darkwood/room/road12",
                "east" : "/d/darkwood/room/road14"]) );

}
