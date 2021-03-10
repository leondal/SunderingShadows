//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for050",
	"north":"/d/laerad/parnelli/forest/for038",
	"south":"/d/laerad/parnelli/forest/for040"
    ]) );
}

void reset() {
   ::reset();
}