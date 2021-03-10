//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains52",
	"east":"/d/laerad/plains/plains71",
	"south":"/d/laerad/plains/plains64",
	"north":"/d/laerad/plains/plains62"
    ]) );
}
