//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains43",
	"east":"/d/laerad/plains/plains67",
	"south":"/d/laerad/plains/plains57",
	"north":"/d/laerad/plains/plains55"
    ]) );
}
