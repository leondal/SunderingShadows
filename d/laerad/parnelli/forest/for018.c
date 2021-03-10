//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for010",
	"east":"/d/laerad/parnelli/forest/for027",
	"north":"/d/laerad/parnelli/forest/for017",
	"south":"/d/laerad/parnelli/forest/for019"
    ]) );
}
void reset(){
    ::reset();
    if(!present("wolf")){
	new("/d/laerad/mon/dwolf")->move(this_object());
    }
}
