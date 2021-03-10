//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for021",
	"north":"/d/laerad/parnelli/forest/for029",
	"south":"/d/laerad/parnelli/forest/for031"
    ]) );
}
void reset(){
    ::reset();
    if(!present("wolverine")){
	new("/d/laerad/mon/wolverine")->move(this_object());
    }
}
