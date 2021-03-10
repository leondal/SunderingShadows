#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste37",
	"east":"/d/laerad/wasteland/waste58",
	"north":"/d/laerad/wasteland/waste46",
	"south":"/d/laerad/wasteland/waste48"
    ]) );
}
