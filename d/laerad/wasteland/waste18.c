#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste10",
	"east":"/d/laerad/wasteland/waste28",
	"north":"/d/laerad/wasteland/waste17",
	"south":"/d/laerad/wasteland/waste11"
    ]) );
}

/*
void reset(){
    ::reset();
    if(!present("runner")){
	new("/d/laerad/mon/runner")->move(this_object());
    }
}
*/