//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for060",
	"east":"/d/laerad/parnelli/forest/for082",
	"south":"/d/laerad/parnelli/forest/for072"
    ]) );
}

void reset() {
   ::reset();
}