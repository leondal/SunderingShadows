//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for004",
	"east":"/d/laerad/parnelli/forest/for012",
	"north":"/d/laerad/parnelli/forest/for001i",
	"south":"/d/laerad/parnelli/forest/for006"
    ]) );
}
void reset(){
    ::reset();
    if(!present("wolverine")){
	new("/d/laerad/mon/wolverine")->move(this_object());
    }
}
