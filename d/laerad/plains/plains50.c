//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains37",
	"east":"/d/laerad/plains/plains61",
	"south":"/d/laerad/plains/plains51",
	"north":"/d/laerad/plains/plains49"
    ]) );
}
