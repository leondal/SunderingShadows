
#include <std.h>

inherit ROOM;

void create(){
	::create();
	set_short("Meeting chamber.");
	set_property("indoors",1);
	set_property("light",2);
set_long("
    This is a meetingplace by the altar where ceremonies and sacrifices are witnessed.  A large circle of stones marks the boundries of the meetingplace as stepping outside the circle during the ritual could mean termination.  Black obelisks rise at the four corners of the room and surround the circle of stones.  At the center of the room is a pit of fire.
");
       set_exits(([
          "steps":"/d/attaya/cliff60",
]));
	
      set_listen("default", "Screams echo through this hall");
	}

void reset(){
	int num, i;
	::reset();
	
	if(!present("phalanx")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/phalanx")->move(TO);
                        new("/d/attaya/mon/guardian")->move(TO);
                        new("/d/attaya/mon/uwarrior")->move(TO);
	}
	
}
