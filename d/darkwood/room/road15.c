//	The Royal Southern Road
//	Thorn@Shadowgate
//	10/9/94
//	Darkwood forest
//	road15
/*Updated by Circe 10/4/03 to include room name, smell, listen and to use inherits to save on memory. Also, a few rooms were added to fix the way the area looks when mapped.*/

#include <std.h>

inherit "/d/darkwood/room/road2";

void create() {
    ::create();
    set_long(
"%^GREEN%^You are on the Royal Southern Road. The road seems to beskirting the southern edge of a dark forest. To the southof you appears to be some hills and a wide plain stretchingto the horizon. The road continues to the east-west.
"
    );
    set_exits(
              (["west" : "/d/darkwood/room/road14",
				"east" : "/d/darkwood/room/road16"]) );
    set_smell("default","The scent of pine lingers in the air.");
}
