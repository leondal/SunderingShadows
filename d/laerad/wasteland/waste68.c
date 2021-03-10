#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste56",
	"east":"/d/laerad/wasteland/waste80",
	"north":"/d/laerad/wasteland/waste67",
	"south":"/d/laerad/wasteland/waste69"
    ]) );
}
