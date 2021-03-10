#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste36",
	"east":"/d/laerad/wasteland/waste57",
	"north":"/d/laerad/wasteland/waste45",
	"south":"/d/laerad/wasteland/waste47"
    ]) );
}

/*
void reset(){
    ::reset();
    if(!present("hyena")){
	new("/d/laerad/mon/hyena")->move(this_object());
    }
}
*/