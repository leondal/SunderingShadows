#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste25",
	"east":"/d/laerad/wasteland/waste44",
	"north":"/d/laerad/wasteland/waste33",
	"south":"/d/laerad/wasteland/waste35"
    ]) );
}
