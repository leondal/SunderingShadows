//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains26",
	"east":"/d/laerad/plains/plains52",
	"south":"/d/laerad/plains/plains40",
	"north":"/d/laerad/plains/plains38"
    ]) );
}
