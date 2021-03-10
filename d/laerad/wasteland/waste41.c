#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste31",
	"east":"/d/laerad/wasteland/waste52",
	"north":"/d/laerad/wasteland/waste40",
	"south":"/d/laerad/wasteland/waste42"
    ]) );
}
