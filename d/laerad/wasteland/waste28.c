#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste18",
	"east":"/d/laerad/wasteland/waste37",
	"north":"/d/laerad/wasteland/waste27",
	"south":"/d/laerad/wasteland/waste29"
    ]) );
}
