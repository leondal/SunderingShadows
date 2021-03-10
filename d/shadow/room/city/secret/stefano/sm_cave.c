//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit ROOM;

int HOLE;

void set_rope(int rope);

int rope_present;

void create(){
	::create();
	set_name("small cave");
   set_short("small cave");
   set_long(
   	"%^RESET%^%^ORANGE%^"+
   	"This is a small dark cave.  The floor if made of "+
   	"dirt and stone and it dry.  There is some debris "+
   	"piled up in the back of the cave."+
   	"%^RESET%^"
   );
   set_property("indoors",1);
   set_property("light",1);
   set_smell("default","The smell of green growing things reaches you.");
   set_listen("default","You can hear the sounds of birds chirping.");
   set_items(([
   	"floor" : "The floor is made of loose dirt and stone.  "+
   		"The dirt is dry and has various tracks imprinted everywhere.",
   	"tracks" : "You can see tracks of assorted sizes of boots and "+
   		"bare feet.  You can also see tracks from small forest animals.",
   	"cave" : "This is a typical dry cave.  There does nto seem to "+
   		"be anything special about it.",
   	"debris" : "The debris is piled haphazardly in the back "+
   		"corner of the cave.  Some of the pieces are to big to "+
   		"have blown in here so your guess is as good as any as "+
   		"to how they got here."
  	]));
   set_exits(([
   	"out" : STEFANO+"path1"
   ]));

        set_climb_exits((["descend":({STEFANO+"tunnel20",20,6,100})]));
   set_fall_desc("%^BOLD%^%^RED%^You fall a long way tumbling into the "+
		"darkness bouncing off the sides of the tunnel until you come to a sudden "+
		"and painful stop at the bottom!%^RESET%^\n");
      
   set_search("debris","Good thing you took a closer look at "+
   	"this pile.  It is not here naturally and appears to "+
   	"have been stacked here purposefully.  Maybe it is "+
   	"hiding something?  The only way to find out would be "+
   	"to move the pile I suppose, I hope there is nothing "+
   	"dangerous lurking in the pile.\n");
   set_search("cave","Nothing really here to search except for the debris.\n");
   
   HOLE = 0;
}
void init() {
  	::init();
  	add_action("move_em","move");
  	add_action("cover_em","cover");
  	add_action("descend_em","descend");
}
int descend_em() {
 	if(HOLE == 0){
   	tell_object(TP,"Descend into what?");
      return 1;
   }
}
int cover_em(string str) {
 	if(!str) {
   	tell_object(TP,"Cover what?");
      return 1;
   }
  	if(str == "hole" || str == "the hole"){
     	tell_object(TP,"You cover the hole with debris concealing it.\n");
     	tell_room(ETP,""+TPQCN+" carefully places the debris over the hole.\n",TP);
   	set_long(
   		"%^RESET%^%^ORANGE%^"+
   		"This is a small dark cave.  The floor if made of "+
   		"dirt and stone and it dry.  There is some debris "+
   		"piled up in the back of the cave."+
   		"%^RESET%^"
   	);
   	HOLE = 0;
     	return 1;
	}
}
int move_em(string str) {
 	if(!str) {
   	tell_object(TP,"Move what?");
      return 1;
   }
  	if(str == "debris" || str == "the debris" || str == "the pile of debris"){
     	tell_object(TP,"You move the debris and find a hole leading "+
     		"downward into the darkness.\n");
     	tell_room(ETP,""+TPQCN+" moves the debris to one side.\n",TP);
   	set_long(
   		"%^RESET%^%^ORANGE%^"+
   		"This is a small dark cave.  The floor if made of "+
   		"dirt and stone and it dry.  There is some debris "+
   		"piled up in the back of the cave.  There is "+
   		"a hole near the debris."+
   		"%^RESET%^"
   	);
   	HOLE = 1;
     	return 1;
	}
}
