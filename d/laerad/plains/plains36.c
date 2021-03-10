//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains23",
	"east":"/d/laerad/plains/plains49",
	"south":"/d/laerad/plains/plains37",
	"north":"/d/laerad/plains/plains35"
    ]) );
}
