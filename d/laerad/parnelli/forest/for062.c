//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for052",
	"east":"/d/laerad/parnelli/forest/for073",
	"north":"/d/laerad/parnelli/forest/for061",
	"south":"/d/laerad/parnelli/forest/for063"
    ]) );
}

void reset() {
   ::reset();
}