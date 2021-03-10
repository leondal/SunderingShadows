//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for142",
	"north":"/d/laerad/parnelli/forest/for130",
	"south":"/d/laerad/parnelli/forest/for132"
    ]) );
}
void reset(){
    ::reset();
    if(!present("leprachaun")){
	new("/d/laerad/mon/lepra")->move(this_object());
    }
}
