#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste34",
	"east":"/d/laerad/wasteland/waste55",
	"north":"/d/laerad/wasteland/waste43",
	"south":"/d/laerad/wasteland/waste45"
    ]) );
}

/*
void reset(){
    ::reset();
    if(!present("cockatrice")){
	new("/d/laerad/mon/cockatrice")->move(this_object());
    }
}
*/