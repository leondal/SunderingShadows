//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains21",
	"east":"/d/laerad/plains/plains47",
	"south":"/d/laerad/plains/plains35",
	"north":"/d/laerad/plains/plains33"
    ]) );
}
