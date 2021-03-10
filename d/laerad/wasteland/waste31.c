#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste22",
	"east":"/d/laerad/wasteland/waste41",
	"north":"/d/laerad/wasteland/waste30",
	"south":"/d/laerad/wasteland/waste32"
    ]) );
}
