// Coded by Bane
// castle01.c
#include <std.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit ROOM;
void create(){
    ::create();
    set_short("Asgard Castle");
    set_long(
	"You are just inside the gates of Asgard Castle.  There is a "+
	"receptionist and a few guards on the other side of the room "+
	"waiting for guests to sign in for a tour or perhaps a walk "+
	"around the lower level.  The room is warm and well lit, "+
	"a few paintings and tapestries decorate the stone walls."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is clean and refreshing.");
    set_listen("default","You can hear the chatter of the guards.");
    set_exits( ([
	"west":"/d/laerad/parnelli/asgard/as89",
	"east":CAS+"castle02",
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
