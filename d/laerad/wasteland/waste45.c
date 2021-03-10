#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste35",
	"east":"/d/laerad/wasteland/waste56",
	"north":"/d/laerad/wasteland/waste44",
	"south":"/d/laerad/wasteland/waste46"
    ]) );
}
