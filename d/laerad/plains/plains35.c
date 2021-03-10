//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains22",
	"east":"/d/laerad/plains/plains48",
	"south":"/d/laerad/plains/plains36",
	"north":"/d/laerad/plains/plains34"
    ]) );
}
