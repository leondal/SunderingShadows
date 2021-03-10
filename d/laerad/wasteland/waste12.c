#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste4",
	"east":"/d/laerad/wasteland/waste15",
	"north":"/d/laerad/wasteland/waste6",
	"south":"/d/laerad/wasteland/waste3"
    ]) );
}
