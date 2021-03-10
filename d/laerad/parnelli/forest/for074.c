//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for063",
	"east":"/d/laerad/parnelli/forest/for085",
	"north":"/d/laerad/parnelli/forest/for073",
	"south":"/d/laerad/parnelli/forest/for075"
    ]) );
}

void reset() {
   ::reset();
}