//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for119",
	"west":"/d/laerad/parnelli/forest/for095",
	"north":"/d/laerad/parnelli/forest/for106",
	"south":"/d/laerad/parnelli/forest/for108"
    ]) );
}

void reset() {
   ::reset();
}