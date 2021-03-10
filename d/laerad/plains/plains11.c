//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains4",
	"east":"/d/laerad/plains/plains21",
	"south":"/d/laerad/plains/plains12",
	"north":"/d/laerad/plains/plains10"
    ]) );
}
