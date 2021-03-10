//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains64",
	"east":"/d/laerad/plains/plains77",
	"south":"/d/laerad/plains/plains73",
	"north":"/d/laerad/plains/plains71"
    ]) );
}
