//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains29",
	"east":"/d/laerad/plains/plains55",
	"south":"/d/laerad/plains/plains43"
    ]) );
}
