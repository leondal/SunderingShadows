#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste73",
	"east":"/d/laerad/wasteland/waste95",
	"north":"/d/laerad/wasteland/waste84",
	"south":"/d/laerad/wasteland/waste86"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("cactus")){
	new("/d/laerad/mon/cactus")->move(this_object());
    }
}
*/