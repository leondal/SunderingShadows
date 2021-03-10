#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste61",
	"east":"/d/laerad/wasteland/waste88",
	"north":"/d/laerad/wasteland/waste74",
	"south":"/d/laerad/wasteland/waste76"
    ]) );
}
