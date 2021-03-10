#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste7",
	"east":"/d/laerad/wasteland/waste22",
	"north":"/d/laerad/wasteland/waste8",
	"south":"/d/laerad/wasteland/waste19"
    ]) );
}
