//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains8",
	"east":"/d/laerad/plains/plains31",
	"south":"/d/laerad/plains/plains19",
	"north":"/d/laerad/plains/plains17"
    ]) );
}
