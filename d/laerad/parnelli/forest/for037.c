//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for028",
	"east":"/d/laerad/parnelli/forest/for048",
	"north":"/d/laerad/parnelli/forest/for036",
	"south":"/d/laerad/parnelli/forest/for038"
    ]) );
}
void reset(){
    ::reset();
    if(!present("beetle")){
	new("/d/laerad/mon/dbeetle")->move(this_object());
    }
}
