#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste12",
	"east":"/d/laerad/wasteland/waste24",
	"north":"/d/laerad/wasteland/waste19",
	"south":"/d/laerad/wasteland/waste14"
    ]) );
}
