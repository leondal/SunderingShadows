#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste45",
	"east":"/d/laerad/wasteland/waste68",
	"north":"/d/laerad/wasteland/waste55",
	"south":"/d/laerad/wasteland/waste57"
    ]) );
}
