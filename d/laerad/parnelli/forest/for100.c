//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for112",
	"west":"/d/laerad/parnelli/forest/for088",
	"north":"/d/laerad/parnelli/forest/for099",
	"south":"/d/laerad/parnelli/forest/for101"
    ]) );
}

void reset() {
   ::reset();
}