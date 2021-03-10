#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste69",
	"east":"/d/laerad/wasteland/waste91",
	"north":"/d/laerad/wasteland/waste80",
	"south":"/d/laerad/wasteland/waste82"
    ]) );
}
