//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains5",
	"east":"/d/laerad/plains/plains22",
	"south":"/d/laerad/plains/plains13",
	"north":"/d/laerad/plains/plains11"
    ]) );
}
