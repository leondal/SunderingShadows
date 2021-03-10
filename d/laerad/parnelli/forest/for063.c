//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for053",
	"east":"/d/laerad/parnelli/forest/for074",
	"north":"/d/laerad/parnelli/forest/for062",
	"south":"/d/laerad/parnelli/forest/for064"
    ]) );
}

void reset() {
   ::reset();
}