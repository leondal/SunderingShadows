#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/wasteland/waste62",
	"east":"/d/laerad/wasteland/waste89",
	"north":"/d/laerad/wasteland/waste75",
	"south":"/d/laerad/wasteland/waste77"
    ]) );
}

/*
void reset(){
    ::reset();
    if(!present("rhino")){
	new("/d/laerad/mon/wrhino")->move(this_object());
    }
}
*/