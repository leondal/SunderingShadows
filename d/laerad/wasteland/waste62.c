#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste50",
	"east":"/d/laerad/wasteland/waste76",
	"north":"/d/laerad/wasteland/waste61",
	"south":"/d/laerad/wasteland/waste63"
    ]) );
}
