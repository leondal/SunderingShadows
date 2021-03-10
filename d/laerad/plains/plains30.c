//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains17",
	"east":"/d/laerad/plains/plains43",
	"south":"/d/laerad/plains/plains31",
	"north":"/d/laerad/plains/plains29"
    ]) );
}
