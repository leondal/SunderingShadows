#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste43",
	"east":"/d/laerad/wasteland/waste66",
	"north":"/d/laerad/wasteland/waste53",
	"south":"/d/laerad/wasteland/waste55"
    ]) );
}
