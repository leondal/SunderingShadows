#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste5",
	"east":"/d/laerad/wasteland/waste16",
	"north":"/d/laerad/wasteland/waste3",
	"south":"/d/laerad/wasteland/waste9"
    ]) );
}
