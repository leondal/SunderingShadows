//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains30",
	"east":"/d/laerad/plains/plains56",
	"south":"/d/laerad/plains/plains44",
	"north":"/d/laerad/plains/plains42"
    ]) );
}
