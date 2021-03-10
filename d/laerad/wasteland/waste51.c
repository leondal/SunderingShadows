#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste40",
	"east":"/d/laerad/wasteland/waste63",
	"north":"/d/laerad/wasteland/waste50",
	"south":"/d/laerad/wasteland/waste52"
    ]) );
}
