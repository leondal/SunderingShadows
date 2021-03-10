#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste46",
	"east":"/d/laerad/wasteland/waste69",
	"north":"/d/laerad/wasteland/waste56",
	"south":"/d/laerad/wasteland/waste58"
    ]) );
}
