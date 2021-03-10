//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for051",
	"east":"/d/laerad/parnelli/forest/for072",
	"north":"/d/laerad/parnelli/forest/for060",
	"south":"/d/laerad/parnelli/forest/for062",
    ]) );
}
void reset(){
    ::reset();
    if(!present("spider")){
	new("/d/laerad/mon/wspider")->move(TO);
    }
}
