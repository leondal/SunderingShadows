//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for091",
	"northwest":"/d/laerad/parnelli/forest/for068",
	"north":"/d/laerad/parnelli/forest/for079",
	"south":"/d/laerad/parnelli/forest/for081"
    ]) );
}

void reset() {
   ::reset();
}