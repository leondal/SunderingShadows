//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for136",
	"north":"/d/laerad/parnelli/forest/for124",
	"south":"/d/laerad/parnelli/forest/for126"
    ]) );
}
void reset(){
    ::reset();
    if(!present("wolf")){
	new("/d/laerad/mon/dwolf")->move(this_object());
	new("/d/laerad/mon/dwolf")->move(this_object());
	new("/d/laerad/mon/dwolf")->move(this_object());
	new("/d/laerad/mon/dwolf")->move(this_object());
    }
}
