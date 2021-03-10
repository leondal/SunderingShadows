//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for126",
	"west":"/d/laerad/parnelli/forest/for103",
	"north":"/d/laerad/parnelli/forest/for114",
	"south":"/d/laerad/parnelli/forest/for116"
    ]) );
}

void reset() {
   ::reset();
}