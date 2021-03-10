// Coded by Bane
// castle06.c
#include <std.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit ROOM;
void create(){
    ::create();
    set_short("Asgard Castle");
    set_long(
	"You are standing in a guards barracks. There are a number of "+
	"crude looking bunk beds all around the room. A small table "+
	"sits in the center with a stack of playing cards scattered "+
	"across it. A few chairs are sprawled across the room."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is clean and refreshing.");
    set_listen("default","You can hear the chatter of the guards.");
    set_exits( ([
	"west":CAS+"castle04",
    ]) );
    set_property("continue heartbeat",1);
    set_heart_beat(1);
}
void reset(){
    ::reset();
    OVER->make_stuff(TO);
}
void heart_beat(){
    ::heart_beat();
    if(!present("guard")) OVER->make_stuff(TO);
}
