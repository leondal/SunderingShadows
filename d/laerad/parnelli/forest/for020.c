//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for012",
	"north":"/d/laerad/parnelli/forest/for019",
	"south":"/d/laerad/parnelli/forest/for021"
    ]) );
}

void reset() {
   ::reset();
}