#include "std.h"
inherit ROOM;

void search_shadows(string str);

int wolf_wait;

void create(){
  	::create();
   set_travel(DIRT_ROAD);
   set_terrain(GRASSLANDS);
  	set_property("light",1);
  	set_short("The road that leads past Muileann to the ocean");
  	set("day long","%^GREEN%^You are walking along a quiet deserted "+
  		"road. There are trees and open country to either side of the "+
  		"road. The area back behind the trees appears to be rocky making "+
  		"travel difficult.  Back behind you lie a long stretch of corn fields.");
  	set("night long","%^BOLD%^%^BLUE%^This deserted road gives you the "+
  		"creeps with all the shadows that seem to dance and spin across "+
  		"the road and along side it. When you try to look to deeply into "+
  		"them it seems like something is trying to peer back at you.");
  	set_items( ([
         	"trees" : "There is wild hemp all over and you notice one willow tree.",
          	"rocks" : "They are just rocks with an aqua colored moss growing all "+
          		"over them.",
          	({"willow","tree","willow tree"}) : "It is old, HUGE, and very beautiful.",
           	"shadows" : "You could swear something is lurking in them...maybe "+
           		"if you DARE to search them!"
    	]) );
  	set_smell("default","Clear crisp air with a taint of something unclean.");
  	set_listen("default","Insects buzz and an occassional branch snaps.");
  	set_exits( ([
     		"south" : "/d/koenig/fields/room/field16",
     		"north" : "/d/koenig/road/room2"
    	]) );
  	wolf_wait = 0;
}


void init(){
  	::init();
  	add_action("search_shadows", "search");
}


int search_shadows(string str){
  	if(str != "shadows" || wolf_wait != 0)return 0;
  	if(present("wolf") || present("shewolf")){
      	tell_object(TP,"Havent you found enough already?  \n");
      	tell_room(ETP,""+TPQCN+" must be INSANE, they are searching the "+
      		"shadows for more, RUNNING is a good idea about NOW!",TP);
      	return 1;
    	}
  	wolf_wait = 1;
  	new("/d/koenig/road/mon/wolf.c")->move(TO);
  	new("/d/koenig/road/mon/fwolf.c")->move(TO);
  	tell_object(TP, "A pair of wolves pad silently from the shadows.");
  	tell_room(ETP,""+TPQCN+" searches the shifting shadows and finds a pair "+
  		"of wolves.",TP);
  	return 1;
}

void reset(){
  	::reset();
  	if(wolf_wait != 0)wolf_wait--;
}
