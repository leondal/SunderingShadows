//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"northeast":"/d/laerad/parnelli/forest/for137",
	"west":"/d/laerad/parnelli/forest/for116",
	"north":"/d/laerad/parnelli/forest/for126",
	"south":"/d/laerad/parnelli/forest/for128"
    ]) );
}
void reset(){
    ::reset();
    if(!present("stag")){
	new("/d/laerad/mon/stag")->move(this_object());
    }
}
