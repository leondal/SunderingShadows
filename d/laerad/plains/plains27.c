//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste100",
	"east":"/d/laerad/plains/plains40",
	"south":"/d/laerad/plains/plains28",
	"north":"/d/laerad/plains/plains26"
    ]) );
}
