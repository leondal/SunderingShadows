#include <std.h>
inherit ROOM;

void look_cliffs(string str);

int grizzly_wait;

void create(){
  	::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
  	set_property("light", 1);
  	set_short("The road leading to the ocean or back to Muileann.");
  	set("day long","%^GREEN%^You have passed the gates of Muileann and are "+
      	"now headed in the general direction of the ocean. The road has gotten "+
      	"a bit rough and in the distance you can see it bend a little to the "+
      	"northeast. The folliage has thinned out considerably here. There are "+
      	"no trees to speak of and just a few bushes, other then that it is "+
      	"nothing but small rock cliffs to either side of the deserted road.");
  	set("night long","%^BOLD%^%^BLUE%^You have passed the gates of Muileann "+
      	"and are now headed to the distant shores of the ocean. The shadows "+
      	"here play tricks with your eyes causing the area to have a rather "+
      	"eerie effect. Maybe rushing to your next destination isn't a bad "+
      	"idea.");
  	set_items(([
     		"rocks" : "Rocks is rocks you've seen quite a few this trip.",
     		"cliffs" : "The cliffs glitter here and there as it catches the rays "+
            	"of present light.",
     		"bushes" : "They are aqua in color and some are a rich green.",
     		"road" : "Not well used and a bit rocky now.",
     		"trees" : "I take it you like the scenery."
	]));
  	set_smell("default","The air is crisp with a hint of the ocean.");
  	set_listen("default","Insects buzz and claws scrape across the rock cliffs.");
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
  		tell_room(ETP,""+TPQCN+" has lost their mind, they are "+
  			"searching the cliffs for more Grizzlies! RUNNNNNN!!",TP);
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

