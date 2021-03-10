#include "std.h"
inherit ROOM;

void create(){
  	::create();
   set_travel(DIRT_ROAD);
   set_terrain(GRASSLANDS);
  	set_property("light", 1);
  	set_short("The road that leads past Muileann and onto the ocean.");
  	set("day long","%^GREEN%^You still travel along the deserted road "+
  		"and up ahead you can see the road split off and lead up to "+
  		"the gates of Muileann. Maybe you can catch some rest and "+
  		"get supplies there.");
  	set("night long","%^BOLD%^%^BLUE%^While traveling this road late "+
  		"at night your mind begins to recall stories of other such "+
  		"fools who did and were never seen again. Shivers begin to "+
  		"run the length of your spine and the hairs on the back of "+
  		"your neck begin to stand on end. Luckily you can see some "+
  		"light up ahead, like maybe a town or something.");
  	set_smell("default","Crisp air and a taint of something unclean.");
  	set_listen("default","Insects buzz around and in the distance you "+
  		"can hear cackling laughter.");
  	set_items(([
     		"road" : "Looks rather dusty and untraveled. It makes you wonder "+
     			"what the devil your doing out here.",
     		"town" : "You can see the town off to the northeast and the tip "+
     			"of a dark and ominous tower that sits within it."
	]));
  	set_exits(([
     		"north" : "/d/koenig/road/room3",
     		"south" : "/d/koenig/road/room1"
	]));
}
