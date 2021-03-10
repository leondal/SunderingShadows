//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains42",
	"east":"/d/laerad/plains/plains66",
	"south":"/d/laerad/plains/plains56"
    ]) );
}
