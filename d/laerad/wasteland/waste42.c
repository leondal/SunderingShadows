#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste32",
	"east":"/d/laerad/wasteland/waste53",
	"north":"/d/laerad/wasteland/waste41",
	"south":"/d/laerad/wasteland/waste43"
    ]) );
}
