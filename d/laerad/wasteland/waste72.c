#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste60",
	"east":"/d/laerad/wasteland/waste84",
	"north":"/d/laerad/wasteland/waste71",
	"south":"/d/laerad/wasteland/waste73"
    ]) );
}
