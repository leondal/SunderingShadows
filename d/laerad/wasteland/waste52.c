#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste41",
	"east":"/d/laerad/wasteland/waste64",
	"north":"/d/laerad/wasteland/waste51",
	"south":"/d/laerad/wasteland/waste53"
    ]) );
}
/*
void reset(){
    ::reset();
    if(!present("scarecrow")){
	new("/d/laerad/mon/scarecrow")->move(this_object());
    }
}
*/