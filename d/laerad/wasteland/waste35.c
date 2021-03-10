#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste26",
	"east":"/d/laerad/wasteland/waste45",
	"north":"/d/laerad/wasteland/waste34",
	"south":"/d/laerad/wasteland/waste36"
    ]) );
}
