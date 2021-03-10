//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste90",
	"east":"/d/laerad/plains/plains19",
	"south":"/d/laerad/plains/plains10",
	"north":"/d/laerad/plains/plains8"
    ]) );
}
