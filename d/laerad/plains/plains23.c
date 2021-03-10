//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains13",
	"east":"/d/laerad/plains/plains36",
	"south":"/d/laerad/plains/plains24",
	"north":"/d/laerad/plains/plains22"
    ]) );
}
