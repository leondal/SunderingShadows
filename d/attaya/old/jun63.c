
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
    You are at the gate to an ancient forgotten graveyard of warriors, hidden for centuries beneath the jungle foliage.  A soft mist coats the ground, and the crumbling grave markers stand at varying angles to the north.  An old stone wall stands on either side of you.
    Something about the mood of the jungle around you makes you uneasy.  You can almost feel the spirits of the dead watching you.
");
       set_exits(([
          "south":"/d/attaya/jun18",
          "north":"/d/attaya/jun67",
]));
	
      set_smell("default", "The air smells of rain and humidity");
      set_listen("default", "Around you everywhere, come the various sounds of the jungle fauna");
	}

void reset(){
	int num, i;
	::reset();
	
	if(!present("nightstalker")){
		num = random(4)+1;
		for(i=0;i<num;i++)
			new("/d/attaya/mon/nightstalker")->move(TO);
	}
	
}
