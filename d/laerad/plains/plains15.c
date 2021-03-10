//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste91",
	"east":"/d/laerad/plains/plains25",
	"south":"/d/laerad/wasteland/waste99",
	"north":"/d/laerad/plains/plains14"
    ]) );
}
