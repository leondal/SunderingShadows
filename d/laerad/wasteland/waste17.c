#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste9",
	"east":"/d/laerad/wasteland/waste27",
	"north":"/d/laerad/wasteland/waste16",
	"south":"/d/laerad/wasteland/waste18"
    ]) );
}
