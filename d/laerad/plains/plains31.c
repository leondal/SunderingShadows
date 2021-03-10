//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains18",
	"east":"/d/laerad/plains/plains44",
	"south":"/d/laerad/plains/plains32",
	"north":"/d/laerad/plains/plains30"
    ]) );
}
