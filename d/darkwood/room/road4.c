//	The Royal Southern Road
//	Thorn@Shadowgate
//	9/28/94
//	Darkwood forest
//	road4
/*updated 10/4/03 by Circe.  Added room name and updated code to current standards.  Changed road to use inherits*/

#include <std.h>

inherit "/d/darkwood/room/road2";

void create() {
    ::create();
    set_exits(
              (["north" : "/d/darkwood/room/road3",
                "south" : "/d/darkwood/room/road17",]) );
}
