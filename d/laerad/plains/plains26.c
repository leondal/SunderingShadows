//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste99",
	"east":"/d/laerad/plains/plains39",
	"south":"/d/laerad/plains/plains27",
	"north":"/d/laerad/plains/plains25"
    ]) );
}
