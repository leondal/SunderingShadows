#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste59",
	"east":"/d/laerad/wasteland/waste83",
	"north":"/d/laerad/wasteland/waste70",
	"south":"/d/laerad/wasteland/waste72"
    ]) );
}
