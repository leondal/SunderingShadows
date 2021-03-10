#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste38",
	"east":"/d/laerad/wasteland/waste59",
	"north":"/d/laerad/wasteland/waste47",
	"south":"/d/laerad/wasteland/waste49"
    ]) );
}
