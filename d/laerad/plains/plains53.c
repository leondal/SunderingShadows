//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains40",
	"east":"/d/laerad/plains/plains64",
	"south":"/d/laerad/plains/plains54",
	"north":"/d/laerad/plains/plains52"
    ]) );
}
