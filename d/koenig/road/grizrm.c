#include "std.h"
inherit ROOM;

void look_cliffs(string str);

int grizzly_wait;

void create(){
  	::create();
  	set_property("light", 1);
  	set_short("The road towards the ocean and back.");
  	set("day long", "%^GREEN%^Well you have made it past the town of "+
  		"Muileann and are continuing your journey in the general direction "+
  		"towards the sea (north). The road is a bit rough and in the distance "+
  		"you can see that it bends a little to the east. There are no trees "+
  		"to speak of really and only a few bushes, however there are rocks "+
  		"and small cliffs that run along the road.\n");
  	set("night long", "%^BLUE%^Some would think you a fool for passing up "+
  		"the town of Muileann at night...you can't see much, but shadows and "+
  		"the rough shapes of rocks and cliffs running along the roads side, a "+
  		"few bushes, and maybe a tree or two. The eerieness of the place makes "+
  		"you pick up your pace and hurry on to your next destination.\n");
  	set_items(([
		"rocks" : "Rocks is rocks you've seen quite a few this trip.",
		"cliffs" : "The cliffs glitter here and there as it catches the rays "+
			"of the sun.",
		"bushes" : "They are aqua in color and some are a rich green.",
		"road" : "Not well used and a bit rocky.",
		"trees" : "I take it you like the scenery."
	]));
  	set_smell("default", "You can faintly smell the salt of the ocean and "+
  		"the faint tang of fear.");
  	set_listen("default", "You can hear insects and the scraping of claws across rock.");
  	set_exits(([
     		"north" : "/d/koenig/road/room5",
     		"south" : "/d/koenig/road/room3"
	]));
  	grizzly_wait = 0;
}
void init(){
  	::init();
  	add_action("look_cliffs", "look");
}
int look_cliffs(string str){
  	if(str != "cliffs" || grizzly_wait != 0)return 0;
    	if(present("grizzly")){
     		tell_object(TP,"Dont you think one was enough? \n");
  		tell_room(ETP,""+TPQCN+" has lost their mind, they are searching the "+
  			"cliffs for more Grizzlies! RUNNNNNN!!",TP);
     		return 1;
	}
  	grizzly_wait = 1;
  	new("/d/koenig/road/mon/grizzly1.c")->move(TO);
  	tell_object(TP, "A Grizzly charges towards you, claws and teeth to rend!");
  	tell_room(ETP,""+TPQCN+" looks up at the cliffs and finds one pissed "+
  		"off GRIZZLY!",TP);
  	return 1;
}

void reset(){
  	::reset();
  	if(grizzly_wait != 0)grizzly_wait--;
}

