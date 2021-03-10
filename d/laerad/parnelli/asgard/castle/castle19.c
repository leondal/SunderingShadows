// Coded by Bane
// castle19.c
#include <std.h>
#include "/d/laerad/parnelli/asgard/castle/daemon/bane.h"
inherit ROOM;
void create(){
    ::create();
    set_short("Asgard Castle");
    set_long(
	"You are standing in the kings throne room. The room is quite "+
	"large and cluttered with priceless artifacts. A table sits "+
	"against the northern wall covered with papers. A small set "+
	"of stairs leads up to the kings massive throne. Huge pillars "+
	"rest to either side of the throne holding the ceiling up above. "+
	"The room has an aura of safety to it. The king is very well "+
	"protected by his men and you are positive that any aggression "+
	"shown towards him will be met with swift justice."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is clean and refreshing.");
    set_listen("default","You can hear the chatter of the guards.");
    set_exits( ([
	"west":CAS+"castle18",
    ]) );
    set_property("continue heartbeat",1);
    set_heart_beat(1);
    if(!present("king")){
	new("/d/laerad/parnelli/asgard/castle/guards/king")->move(TO);
	new("/d/laerad/parnelli/asgard/castle/guards/mage")->move(TO);
    }
}
void heart_beat(){
    ::heart_beat();
    OVER->do_orders(TO);
}
