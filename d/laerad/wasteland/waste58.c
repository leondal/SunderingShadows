#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste47",
	"east":"/d/laerad/wasteland/waste70",
	"north":"/d/laerad/wasteland/waste57",
	"south":"/d/laerad/wasteland/waste59"
    ]) );
}
