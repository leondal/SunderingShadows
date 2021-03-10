//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains9",
	"east":"/d/laerad/plains/plains32",
	"south":"/d/laerad/plains/plains20",
	"north":"/d/laerad/plains/plains18"
    ]) );
}
