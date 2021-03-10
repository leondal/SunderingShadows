#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste48",
	"east":"/d/laerad/wasteland/waste71",
	"north":"/d/laerad/wasteland/waste58",
	"south":"/d/laerad/wasteland/waste60"
    ]) );
}
