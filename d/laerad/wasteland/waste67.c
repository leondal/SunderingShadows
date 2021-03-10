#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
/*  set_long(
	"You are standing on a barren plain. The earth is cracked and dead. "+
	"No vegetation can be seen for miles. A wicked wind bites at your "+
	"face blowing sand into your eyes. The lifeless wasteland continues "+
        "to the west, the Gods Plains are to the east.  "
//   A large black 
//        "portal hovers a foot above the ground here, rising about 15 feet "+
//        "into the air."
    );
*/
    set_exits( ([
	"west":"/d/laerad/wasteland/waste55",
	"east":"/d/laerad/plains/plains2",
	"north":"/d/laerad/wasteland/waste66",
	"south":"/d/laerad/wasteland/waste68",
//	"portal":"/d/laerad/wasteland/wportal1"
    ]) );
}
