//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for124",
	"north":"/d/laerad/parnelli/forest/for112",
	"south":"/d/laerad/parnelli/forest/for114"
    ]) );
}

void reset() {
   ::reset();
}