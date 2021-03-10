//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for147",
	"west":"/d/laerad/parnelli/forest/for128",
	"southeast":"/d/laerad/parnelli/forest/for148",
	"north":"/d/laerad/parnelli/forest/for138",
	"south":"/d/laerad/parnelli/forest/for140"
    ]) );
}
void reset(){
    ::reset();
    if(!present("spider")){
	new("/d/laerad/mon/wspider")->move(this_object());
	new("/d/laerad/mon/wspider")->move(this_object());
    }
}
