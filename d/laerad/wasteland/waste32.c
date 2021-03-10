#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste23",
	"east":"/d/laerad/wasteland/waste42",
	"north":"/d/laerad/wasteland/waste31",
	"south":"/d/laerad/wasteland/waste33"
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