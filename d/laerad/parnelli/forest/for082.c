//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for071",
	"east":"/d/laerad/parnelli/forest/for093",
	"north":"/d/laerad/parnelli/forest/for081",
	"south":"/d/laerad/parnelli/forest/for083"
    ]) );
}
void reset(){
    ::reset();
    if(!present("wisp")){
	new("/d/laerad/mon/wisp")->move(TO);
    }
    if(!present("pixie") && !random(3)){
	new("/d/laerad/mon/pixie")->move(TO);
    }
}
