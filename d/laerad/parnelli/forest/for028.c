//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for019",
	"east":"/d/laerad/parnelli/forest/for037",
	"north":"/d/laerad/parnelli/forest/for027",
	"south":"/d/laerad/parnelli/forest/for029"
    ]) );
}

void reset() {
   ::reset();
}