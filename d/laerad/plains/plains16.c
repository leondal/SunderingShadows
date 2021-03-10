//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste97",
	"east":"/d/laerad/plains/plains29",
	"south":"/d/laerad/plains/plains17"
    ]) );
}
