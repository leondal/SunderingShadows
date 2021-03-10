//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains63",
	"east":"/d/laerad/plains/plains76",
	"south":"/d/laerad/plains/plains72",
	"north":"/d/laerad/plains/plains70"
    ]) );
}
