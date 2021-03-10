//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains34",
	"east":"/d/laerad/plains/plains60",
	"south":"/d/laerad/plains/plains48",
	"north":"/d/laerad/plains/plains46"
    ]) );
}
