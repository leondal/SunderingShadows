//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for061",
	"north":"/d/laerad/parnelli/forest/for071",
	"south":"/d/laerad/parnelli/forest/for073"
    ]) );
}

void reset() {
   ::reset();
}