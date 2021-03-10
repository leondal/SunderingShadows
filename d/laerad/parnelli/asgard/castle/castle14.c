// Coded by Bane
// castle14.c
#include <std.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit ROOM;
void create(){
    ::create();
    set_short("Asgard Castle");
    set_long(
	"You are in a more secluded hallway. The hall extends to the "+
	"south into the dining area, and further to the east. The "+
	"walls are decorated with beautiful paintings and tapestries and "+
	"the area is well lit with torches and candles."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is clean and refreshing.");
    set_listen("default","You can hear the chatter of the guards.");
    set_exits( ([
	"south":CAS+"castle13",
	"east":CAS+"castle16",
    ]) );
    set_property("continue heartbeat",1);
    set_heart_beat(1);
}
void reset(){
    ::reset();
    if(!present("guard")) OVER->make_stuff(TO);
}
void heart_beat(){
    ::heart_beat();
    OVER->do_orders(TO);
}
