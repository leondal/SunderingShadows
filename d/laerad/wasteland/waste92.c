#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste82",
	"east":"/d/laerad/wasteland/waste99",
	"north":"/d/laerad/wasteland/waste91",
	"south":"/d/laerad/wasteland/waste93"
    ]) );
}
