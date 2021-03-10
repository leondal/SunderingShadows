
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
    You stumble and fall down a muddy incline. 
 *%^BOLD%^%^BLUE%^SPLASH!!%^RESET%^
    You stand within a shallow puddle of muddy water.  After carefully considering your possibilities, you grap a nearby palm frawn and pull yourself out.
    Something about the mood of the jungle around you makes you uneasy.  You can almost feel the spirits of the dead watching you.
");
       set_exits(([
          "west":"/d/attaya/jun38",
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
