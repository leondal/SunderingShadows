//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains51",
	"east":"/d/laerad/plains/plains70",
	"south":"/d/laerad/plains/plains63",
	"north":"/d/laerad/plains/plains61"
    ]) );
}
