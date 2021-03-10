//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains44",
	"east":"/d/laerad/plains/plains68",
	"south":"/d/laerad/plains/plains58",
	"north":"/d/laerad/plains/plains56"
    ]) );
}
