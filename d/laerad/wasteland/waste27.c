#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste17",
	"east":"/d/laerad/wasteland/waste36",
	"north":"/d/laerad/wasteland/waste26",
	"south":"/d/laerad/wasteland/waste28"
    ]) );
}
