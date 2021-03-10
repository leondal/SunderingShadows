//	The Royal Southern Road
//	Thorn@Shadowgate
//	10/2/94
//	Darkwood forest
//	road9
/*Updated by Circe 10/4/03 to include room name, smell, listen and to use inherits to save on memory. Also, a few rooms were added to fix the way the area looks when mapped.*/

#include <std.h>

inherit "/d/darkwood/room/road8";

void create() {
    ::create();
    set_exits(
              (["north" : "/d/darkwood/room/road21",
                "south" : "/d/darkwood/room/road10",]) );
}

