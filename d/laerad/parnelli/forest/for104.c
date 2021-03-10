//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for116",
	"north":"/d/laerad/parnelli/forest/for103",
	"south":"/d/laerad/parnelli/forest/for105"
    ]) );
}
void reset(){
    ::reset();
    if( !present("quickling") && !random(2) &&
    sizeof(children("/d/laerad/mon/quickling")) < 10 ){
	     new("/d/laerad/mon/quickling")->move(TO);
        new("/d/laerad/mon/quickling")->move(TO); 
        new("/d/laerad/mon/quickling")->move(TO); 
    }
}
