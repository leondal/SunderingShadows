#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste53",
	"east":"/d/laerad/wasteland/waste79",
	"north":"/d/laerad/wasteland/waste64",
	"south":"/d/laerad/wasteland/waste66"
    ]) );
}
