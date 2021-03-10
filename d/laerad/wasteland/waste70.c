#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste58",
	"east":"/d/laerad/wasteland/waste82",
	"north":"/d/laerad/wasteland/waste69",
	"south":"/d/laerad/wasteland/waste71"
    ]) );
}

/*
void reset(){
    ::reset();
    if(!present("chimera")){
	new("/d/laerad/mon/chimera")->move(this_object());
    }
    if(!present("scarecrow")){
	new("/d/laerad/mon/scarecrow")->move(this_object());
    }
}
*/