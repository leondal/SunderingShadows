#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste52",
	"east":"/d/laerad/wasteland/waste78",
	"north":"/d/laerad/wasteland/waste63",
	"south":"/d/laerad/wasteland/waste65"
    ]) );
}
