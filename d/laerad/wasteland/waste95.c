#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste85",
	"east":"/d/laerad/wasteland/waste102",
	"north":"/d/laerad/wasteland/waste94",
	"south":"/d/laerad/wasteland/waste96"
    ]) );
}
