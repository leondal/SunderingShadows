#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste24",
	"east":"/d/laerad/wasteland/waste43",
	"north":"/d/laerad/wasteland/waste32",
	"south":"/d/laerad/wasteland/waste34"
    ]) );
}
