//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains3",
	"east":"/d/laerad/plains/plains20",
	"south":"/d/laerad/plains/plains11",
	"north":"/d/laerad/plains/plains9"
    ]) );
}
