// Coded by Bane
// castle13.c
#include <std.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit ROOM;
void create(){
    ::create();
    set_short("Asgard Castle");
    set_long(
	"You have walked into the main dining area of the castle. "+
	"A grand oak table dominates the center of the room surrounded "+
	"by a number of beautifully carved wooden chairs. A massive "+
	"piano rests against the eastern wall. Huge stone pillars rise "+
	"upwards nearly 30 feet. The walls are covered in priceless "+
	"antique paintings and tapestries. Numerous chandeliers drop down "+
	"from above lighting the room completely."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is clean and refreshing.");
    set_listen("default","You can hear the chatter of the guards.");
    set_exits( ([
	"west":CAS+"castle12",
	"north":CAS+"castle14",
	"south":CAS+"castle15",
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
