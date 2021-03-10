#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste44",
	"east":"/d/laerad/wasteland/waste67",
	"north":"/d/laerad/wasteland/waste54",
	"south":"/d/laerad/wasteland/waste56"
    ]) );
}
