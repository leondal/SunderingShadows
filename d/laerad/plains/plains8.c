//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste89",
	"east":"/d/laerad/plains/plains18",
	"south":"/d/laerad/plains/plains9",
	"north":"/d/laerad/wasteland/waste98"
    ]) );
}
