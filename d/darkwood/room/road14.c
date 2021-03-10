//	The Royal Southern Road
//	Thorn@Shadowgate
//	10/9/94
//	Darkwood forest
//	road14
/*Updated by Circe 10/4/03 to include room name, smell, listen and to use inherits to save on memory. Also, a few rooms were added to fix the way the area looks when mapped.*/

#include <std.h>

inherit "/d/darkwood/room/road2";

void create() {
    ::create();
set_long(
"%^GREEN%^You are on the Royal Southern Road. You appear to be in a clear area just outside of a dark forest. There are a few hills to the south of here. To the west, the road heads into a tall forest, while it continues into the hills further east.
"
);
    set_exits(
              ([
			    "east" : "/d/darkwood/room/road15",
                "west" : "/d/darkwood/room/road13",
		]) );

    set_smell("default","The scent of pine lingers in the air.");
}
