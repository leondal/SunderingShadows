#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste42",
	"east":"/d/laerad/wasteland/waste65",
	"north":"/d/laerad/wasteland/waste52",
	"south":"/d/laerad/wasteland/waste54"
    ]) );
}
