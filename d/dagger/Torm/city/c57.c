#include <std.h>
#include "../tormdefs.h"
inherit MARKET;
void create()
{
    ::create();
   set_long(TO->query_long()+" You see a large fountain to the west.");
    set_exits(([
	"north":TCITY+"c46",
	"east":TCITY+"c58",
	"west":TCITY+"c56",
	"south":TCITY+"c65",
      ]));
}
void reset(){
    ::reset();
    if(query_night()) return;
	if(!present("furtrader",TO)){
	    new(MON+"furtrader")->move(TO);
	}
}
