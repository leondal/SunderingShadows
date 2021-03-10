//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for117",
	"west":"/d/laerad/parnelli/forest/for093",
	"north":"/d/laerad/parnelli/forest/for104",
	"south":"/d/laerad/parnelli/forest/for106"
    ]) );
}

void reset() {
   ::reset();
}