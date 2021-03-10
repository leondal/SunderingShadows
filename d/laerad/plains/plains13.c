//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains6",
	"east":"/d/laerad/plains/plains23",
	"south":"/d/laerad/plains/plains14",
	"north":"/d/laerad/plains/plains12"
    ]) );
}
