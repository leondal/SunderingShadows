#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste63",
	"east":"/d/laerad/wasteland/waste90",
	"north":"/d/laerad/wasteland/waste76",
	"south":"/d/laerad/wasteland/waste78"
    ]) );
}
