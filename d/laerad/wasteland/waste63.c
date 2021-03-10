#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste51",
	"east":"/d/laerad/wasteland/waste77",
	"north":"/d/laerad/wasteland/waste62",
	"south":"/d/laerad/wasteland/waste64"
    ]) );
}
