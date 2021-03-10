//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for107",
	"north":"/d/laerad/parnelli/forest/for094",
	"south":"/d/laerad/parnelli/forest/for096"
    ]) );
}
void reset(){
    ::reset();
    if(!present("panther")){
	new("/d/laerad/mon/panther")->move(this_object());
    }
    if(!present("jaguar")){
	new("/d/laerad/mon/jaguar")->move(this_object());
	new("/d/laerad/mon/jaguar")->move(this_object());
    }
}
