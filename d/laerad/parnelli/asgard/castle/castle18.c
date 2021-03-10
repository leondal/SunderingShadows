// Coded by Bane
// castle18.c
#include <std.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit ROOM;
void create(){
    ::create();
    set_short("Asgard Castle");
    set_long(
	"You are standing in a small guard room that sits outside "+
	"the kings chambers. A post is always set up here to ensure "+
	"that no harm comes to the king. A large desk sits outside "+
	"a pair of large double doors that lead to the east."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is clean and refreshing.");
    set_listen("default","You can hear the chatter of the guards.");
    set_exits( ([
	"north":CAS+"castle16",
	"south":CAS+"castle17",
	"east":CAS+"castle19",
    ]) );
    set_pre_exit_functions( ({"east"}), ({"go_east"}) );
    set_property("continue heartbeat",1);
    set_heart_beat(1);
}
void reset(){
    ::reset();
    if(!present("guard")){
	new("/d/laerad/parnelli/asgard/castle/guards/guard3")->move(TO);
	new("/d/laerad/parnelli/asgard/castle/guards/guard3")->move(TO);
    }
}
void heart_beat(){
    ::heart_beat();
    OVER->do_orders(TO);
}
int go_east(){
    if(present("guard")){
	write("The guard steps in your way.");
	return 0;
    }
    return 1;
}
