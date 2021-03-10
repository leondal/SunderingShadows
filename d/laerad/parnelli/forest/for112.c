//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for123",
	"west":"/d/laerad/parnelli/forest/for100",
	"north":"/d/laerad/parnelli/forest/for111",
	"south":"/d/laerad/parnelli/forest/for113"
    ]) );
}
void reset(){
    ::reset();
    if(!present("bandit")){
	new("/d/laerad/mon/bandit")->move(TO);
    }
}
