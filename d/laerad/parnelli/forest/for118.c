//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for129",
	"north":"/d/laerad/parnelli/forest/for117",
	"south":"/d/laerad/parnelli/forest/for119"
    ]) );
}
void reset(){
    ::reset();
    if(!present("pixie")&& !random(4)){
	new("/d/laerad/mon/pixie")->move(TO);
    }
}
