//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for090",
	"north":"/d/laerad/parnelli/forest/for078",
	"south":"/d/laerad/parnelli/forest/for080"
    ]) );
}

void reset() {
   ::reset();
}