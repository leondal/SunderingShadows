// Coded by Bane
// castle03.c
#include <std.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit ROOM;
void create(){
    ::create();
    set_short("Asgard Castle");
    set_long(
	"You are in a more secluded hallway. The hall extends to the "+
	"east further, to the west into a large reception area, to "+
	"the north and south into the barrack and tower area. The "+
	"walls are covered in beautiful tapestries and the area is "+
	"brightly lit with torches and candles."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is clean and refreshing.");
    set_listen("default","You can hear the chatter of the guards.");
    set_exits( ([
	"west":CAS+"castle02",
	"east":CAS+"castle12",
	"north":CAS+"castle04",
	"south":CAS+"castle08",
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
