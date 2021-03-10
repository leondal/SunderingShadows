#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste72",
	"east":"/d/laerad/wasteland/waste94",
	"north":"/d/laerad/wasteland/waste83",
	"south":"/d/laerad/wasteland/waste85"
    ]) );
}
