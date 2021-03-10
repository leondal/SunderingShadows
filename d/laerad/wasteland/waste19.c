#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste6",
	"east":"/d/laerad/wasteland/waste23",
	"north":"/d/laerad/wasteland/waste20",
	"south":"/d/laerad/wasteland/waste15"
    ]) );
}
