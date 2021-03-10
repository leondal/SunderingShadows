//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"southeast":"/d/laerad/parnelli/forest/for132",
	"west":"/d/laerad/parnelli/forest/for108",
	"north":"/d/laerad/parnelli/forest/for119",
	"south":"/d/laerad/parnelli/forest/for121"
    ]) );
}

void reset() {
   ::reset();
}