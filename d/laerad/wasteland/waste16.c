#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste13",
	"east":"/d/laerad/wasteland/waste26",
	"north":"/d/laerad/wasteland/waste14",
	"south":"/d/laerad/wasteland/waste17"
    ]) );
}

/*
void reset(){
    ::reset();
    if(!present("mara")){
	new("/d/laerad/mon/mara")->move(this_object());
    }
}
*/