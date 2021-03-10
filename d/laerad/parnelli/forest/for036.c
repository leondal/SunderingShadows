//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for047",
	"north":"/d/laerad/parnelli/forest/for035",
	"south":"/d/laerad/parnelli/forest/for037"
    ]) );
}

void reset() {
   ::reset();
}