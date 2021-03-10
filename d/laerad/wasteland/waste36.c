#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste27",
	"east":"/d/laerad/wasteland/waste46",
	"north":"/d/laerad/wasteland/waste35",
	"south":"/d/laerad/wasteland/waste37"
    ]) );
}
