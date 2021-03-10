//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for059",
	"north":"/d/laerad/parnelli/forest/for068"
    ]) );
}
void reset(){
    ::reset();
    if(!present("jaguar")){
	new("/d/laerad/mon/jaguar")->move(TO);
    }
}

