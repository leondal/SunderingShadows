#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste33",
	"east":"/d/laerad/wasteland/waste54",
	"north":"/d/laerad/wasteland/waste42",
	"south":"/d/laerad/wasteland/waste44"
    ]) );
}
