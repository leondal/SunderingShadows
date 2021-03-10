//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains32",
	"east":"/d/laerad/plains/plains58",
	"south":"/d/laerad/plains/plains46",
	"north":"/d/laerad/plains/plains44"
    ]) );
}
