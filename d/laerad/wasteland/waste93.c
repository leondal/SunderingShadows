#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste83",
	"east":"/d/laerad/wasteland/waste100",
	"north":"/d/laerad/wasteland/waste92",
	"south":"/d/laerad/wasteland/waste94"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("leucrotta")){
	new("/d/laerad/mon/leucrotta")->move(this_object());
    }
}
*/