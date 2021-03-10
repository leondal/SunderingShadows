//Coded by Bane//
#include <std.h>
inherit "/d/laerad/parnelli/forest/for001i";
void create(){
    ::create();
    set_exits( ([
	"east":"/d/laerad/parnelli/forest/for092",
	"west":"/d/laerad/parnelli/forest/for070",
	"north":"/d/laerad/parnelli/forest/for080",
	"south":"/d/laerad/parnelli/forest/for082"
    ]) );
   set_pre_exit_functions( ({"west"}),({"no_forestmons"}) );
}

int no_forestmons() {
   if(TP->id("forestmon"))     return 0;
   return 1;
}
