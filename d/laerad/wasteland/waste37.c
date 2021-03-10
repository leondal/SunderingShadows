#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste28",
	"east":"/d/laerad/wasteland/waste47",
	"north":"/d/laerad/wasteland/waste36",
	"south":"/d/laerad/wasteland/waste38"
    ]) );
}
