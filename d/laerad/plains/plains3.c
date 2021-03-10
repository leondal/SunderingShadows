//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste78",
	"east":"/d/laerad/plains/plains10",
	"south":"/d/laerad/plains/plains4",
	"north":"/d/laerad/wasteland/waste90"
    ]) );
}
