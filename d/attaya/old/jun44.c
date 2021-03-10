
#include <std.h>

inherit ROOM;

void create(){
	::create();
      set_terrain(JUNGLE);
      set_travel(DIRT_ROAD);
	set_name("Trail carved through the jungle on Attaya Island.");
	set_short("Trail carved through the jungle on Attaya Island.");
	set_property("indoors",0);
	set_property("light",1);
set_long("
    You are pushing your way down a trail carved through the thicket of the jungle.  Tall tropical trees and palms form a canopy above you so thick that it blocks out nearly all the sunlight!  The ground beneath your feet sloshes with each step.
    Something about the mood of the jungle around you makes you uneasy.  You can almost feel the spirits of the dead watching you.
");
       set_exits(([
          "north":"/d/attaya/jun50",
          "south":"/d/attaya/jun41",
         "east":"/d/attaya/jun45"
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "Around you everywhere, come the various sounds of the jungle fauna");
	}

void reset(){
	int num, i;
	::reset();
	
	if(!present("warrior")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/uwarrior")->move(TO);
	}
	
}
