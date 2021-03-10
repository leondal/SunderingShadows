#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste71",
	"east":"/d/laerad/wasteland/waste93",
	"north":"/d/laerad/wasteland/waste82",
	"south":"/d/laerad/wasteland/waste84"
    ]) );
}
