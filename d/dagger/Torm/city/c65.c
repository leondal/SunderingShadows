#include <std.h>
#include "../tormdefs.h"
inherit MARKET;
void create()
{
    ::create();
   set_long(TO->query_long()+" There is a large fountain to the northwest.");
    set_exits(([
	"north":TCITY+"c57",
	"east":TCITY+"c66",
	"west":TCITY+"c64",
      ]));
}
void reset(){
    ::reset();
    if(query_night()) return;
	if(!present("petire",TO)){
	    new(MON+"weaponer2.c")->move(TO);
	    new(MON+"citizen.c")->move(TO);
	}
}
