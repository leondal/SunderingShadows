//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for115",
	"southwest":"/d/laerad/parnelli/forest/for092",
	"north":"/d/laerad/parnelli/forest/for102",
	"south":"/d/laerad/parnelli/forest/for104"
    ]) );
}

void reset() {
   ::reset();
}