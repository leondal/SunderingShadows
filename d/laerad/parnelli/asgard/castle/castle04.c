// Coded by Bane
// castle04.c
#include <std.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit ROOM;
void create(){
    ::create();
    set_short("Asgard Castle");
    set_long(
	"You are standing in one of the 4 main towers in Asgard castle. "+
	"To the north, east and west are the guards barracks. To "+
	"the south is the main hallway. A staircase spirals upwards into "+
	"the tower above."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is clean and refreshing.");
    set_listen("default","You can hear the chatter of the guards.");
    set_exits( ([
	"west":CAS+"castle05",
	"east":CAS+"castle06",
	"north":CAS+"castle07",
	"south":CAS+"castle03",
	"up":CAS+"castle22",
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
