//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains27",
	"east":"/d/laerad/plains/plains53",
	"south":"/d/laerad/plains/plains41",
	"north":"/d/laerad/plains/plains39"
    ]) );
}
