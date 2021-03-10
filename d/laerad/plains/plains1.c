//Coded by Bane//
#include <std.h>

inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste66",
	"east":"/d/laerad/plains/plains5",
	"south":"/d/laerad/plains/plains2",
	"north":"/d/laerad/wasteland/waste79"
    ]) );
}
