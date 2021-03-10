//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains56",
	"east":"/d/laerad/plains/plains75",
	"south":"/d/laerad/plains/plains68",
	"north":"/d/laerad/plains/plains66"
    ]) );
}
