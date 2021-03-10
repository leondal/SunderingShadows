//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for022",
	"east":"/d/laerad/parnelli/forest/for040",
	"north":"/d/laerad/parnelli/forest/for030",
	"south":"/d/laerad/parnelli/forest/for032"
    ]) );
}

void reset() {
   ::reset();
}