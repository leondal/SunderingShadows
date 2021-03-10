#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste84",
	"east":"/d/laerad/wasteland/waste101",
	"north":"/d/laerad/wasteland/waste93",
	"south":"/d/laerad/wasteland/waste95"
    ]) );
}
