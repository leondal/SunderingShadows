//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for121",
	"west":"/d/laerad/parnelli/forest/for097",
	"north":"/d/laerad/parnelli/forest/for108",
	"south":"/d/laerad/parnelli/forest/for110"
    ]) );
}

void reset() {
   ::reset();
}