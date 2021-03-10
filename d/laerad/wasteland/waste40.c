#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste30",
	"east":"/d/laerad/wasteland/waste51",
	"north":"/d/laerad/wasteland/waste39",
	"south":"/d/laerad/wasteland/waste41"
    ]) );
}
