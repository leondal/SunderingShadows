//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for128",
	"west":"/d/laerad/parnelli/forest/for105",
	"southwest":"/d/laerad/parnelli/forest/for106",
	"north":"/d/laerad/parnelli/forest/for116",
	"south":"/d/laerad/parnelli/forest/for118"
    ]) );
}

void reset() {
   ::reset();
}