/*Added 10/4/03 by Circe.  Added room name and updated code to current standards.  Changed road to use inherits.  Four rooms were added to make the desert connect correctly.*/

#include <std.h>

inherit "/d/darkwood/room/road2";

void create() {
    ::create();
    set_exits(
              (["north" : "/d/darkwood/room/road19",
                "south" : "/d/darkwood/room/road5",]) );
}
