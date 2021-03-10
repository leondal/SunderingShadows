// Coded by Bane
// castle02.c
#include <std.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit ROOM;
void create(){
    ::create();
    set_short("Asgard Castle");
    set_long(
	"You have walked into a huge hall.  Massive stone pillars "+
	"reach upwards supporting the ceiling.  A brilliant chandelier "+
	"dominates the center of the room bathing the room in a "+
	"golden light.  A small fountain rests on the northern "+
	"wall spraying water from its spout.  Priceless antiques "+
	"stand on small stone pillars, tapesties and paintings "+
	"decorate the walls of this gorgeous room."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is clean and refreshing.");
    set_listen("default","You can hear the chatter of the guards.");
    set_exits( ([
	"west":CAS+"castle01",
	"east":CAS+"castle03",
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
