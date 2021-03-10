//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/parnelli/forest/for058",
	"southeast":"/d/laerad/parnelli/forest/for080",
	"north":"/d/laerad/parnelli/forest/for067",
	"south":"/d/laerad/parnelli/forest/for069"
    ]) );
}


void reset() {
   ::reset();
}