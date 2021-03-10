#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
/*  set_long(
	"You are standing on a barren plain. The earth is cracked and dead. "+
	"No vegetation can be seen for miles. A wicked wind bites at your "+
	"face blowing sand into your eyes. The lifeless wasteland continues "+
	"to the west, the Gods Plains are to the east."
    );
*/
    set_exits( ([
	"west":"/d/laerad/wasteland/waste81",
	"east":"/d/laerad/plains/plains15",
	"north":"/d/laerad/plains/plains7",
	"south":"/d/laerad/wasteland/waste92"
    ]) );
}
