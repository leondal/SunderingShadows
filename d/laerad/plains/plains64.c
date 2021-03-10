//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains53",
	"east":"/d/laerad/plains/plains72",
	"south":"/d/laerad/plains/plains65",
	"north":"/d/laerad/plains/plains63"
    ]) );
}
