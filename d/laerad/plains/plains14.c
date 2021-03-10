//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains7",
	"east":"/d/laerad/plains/plains24",
	"south":"/d/laerad/plains/plains15",
	"north":"/d/laerad/plains/plains13"
    ]) );
}
