//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for100",
	"north":"/d/laerad/parnelli/forest/for087",
	"south":"/d/laerad/parnelli/forest/for089"
    ]) );
}
void reset(){
    ::reset();
    if(!present("stag")){
	new("/d/laerad/mon/stag")->move(this_object());
    }
}
