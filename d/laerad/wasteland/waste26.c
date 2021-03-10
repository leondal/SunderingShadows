#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste16",
	"east":"/d/laerad/wasteland/waste35",
	"north":"/d/laerad/wasteland/waste25",
	"south":"/d/laerad/wasteland/waste27"
    ]) );
}
