#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste70",
	"east":"/d/laerad/wasteland/waste92",
	"north":"/d/laerad/wasteland/waste81",
	"south":"/d/laerad/wasteland/waste83"
    ]) );
}
