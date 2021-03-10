//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
        set_exits( ([
	"west":"/d/laerad/wasteland/waste98",
	"east":"/d/laerad/plains/plains30",
	"south":"/d/laerad/plains/plains18",
	"north":"/d/laerad/plains/plains16"
    ]) );
}
