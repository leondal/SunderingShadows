//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste79",
	"east":"/d/laerad/plains/plains11",
	"south":"/d/laerad/plains/plains5",
	"north":"/d/laerad/plains/plains3"
    ]) );
}
