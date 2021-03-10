//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste67",
	"east":"/d/laerad/plains/plains6",
	"south":"/d/laerad/wasteland/waste80",
	"north":"/d/laerad/plains/plains1"
    ]) );
}
