//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for031",
	"north":"/d/laerad/parnelli/forest/for021",
	"south":"/d/laerad/parnelli/forest/for023"
    ]) );
}
void reset(){
    ::reset();
    if(!present("panther")){
	new("/d/laerad/mon/panther")->move(this_object());
    }
}
