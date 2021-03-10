//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit VAULT;
int CODE;

void create(){
	::create();
	set_name("tunnel");
   set_short("tunnel");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"You are in a tunnel leading north and south."+
   	" The tunnel itself looks to be of "+
   	"recent construction and is made very well.  The walls, "+
   	"ceiling, and floor are made of native stone cut, "+
   	"and mortared, to fit perfectly.  The stonework is "+
   	"of such high quality it can only be of dwarven construction.  "+
   	"There are no sconces, or other devices, to hold torches, or "+
   	"lanterns.  Chisel marks can be seen in various places and "+
   	"look deliberate."+
   	"%^RESET%^"
   );
   set_property("indoors",1);
   set_property("light",1);
   set_smell("default","Dust tickles your nose making you almost sneeze.");
   set_listen("default","You can hear muffled unidentified noises.");
   set_items(([
   	({"floor","walls","wall","ceiling"}) : "The entire tunnel "+
   		"is made of native stone that has been cut, and mortared, "+
   		"to fit together perfectly.  The construction has made the "+
   		"tunnel extremely stable and is of very high quality.  "+
   		"Chisel marks have been deliberately placed on the walls "+
   		"near the floor at regular intervals.",
   	({"chisel marks", "chisel mark", "marks", "mark"}) : "The marks "+
   		"are not easily seen and are no doubt a code placed by the "+
   		"builders for a purpose that only they can say.  Knowing "+
   		"dwarves it is probably the amount of minutes since their "+
   		"last ale.  This section of wall has thirteen marks.",
   	"stones" : "The stones here are much the same as the rest "+
   		"of the tunnel except for the interesting shapes of three "+
   		"of them on the west wall."
  	]));
   set_exits(([
   	"north" : STEFANO+"tunnel6",
   	"south" : STEFANO+"tunnel8"
	]));
	
	set_search("stones","The stones here are interesting.  You see a "+
		"perfectly round, square, and triangle stone.  "+
		"Are these stones coincidental or too coincidental.\n");
	
	CODE = 0;
}
void init() {
  	::init();
  	add_action("close_em","close");
  	add_action("press_em","press");
}

// press round, triangle, triangle, square, round will open the secret door//

int press_em(string str) {
 	if(!str) {
   	tell_object(TP,"Press what?");
      return 1;
   }
	if(member_array("door",TO->query_exits()) != -1) {
   	tell_object(TP,"The stone you want to press is on the door that is "+
   		"already opened!");
		return 1;
	}
  	if(str == "round" && CODE == 0){
     	tell_object(TP,"%^BOLD%^You press the round stone and hear a click.\n");
     	tell_room(ETP,""+TPQCN+" presses the round stone and you hear a click.\n",TP);
     	CODE = 1;
     	return 1;
	}else if(str == "triangle" && CODE == 1){
     	tell_object(TP,"%^BOLD%^You press the triangular stone and hear a click.\n");
     	tell_room(ETP,""+TPQCN+" presses the triangular stone and you hear a click.\n",TP);
     	CODE = 2;
     	return 1;
 	}else if(str == "square" && CODE == 2){
     	tell_object(TP,"%^BOLD%^You press the square stone and hear a click.\n");
     	tell_room(ETP,""+TPQCN+" presses the square stone and you hear a click.\n",TP);
     	CODE = 3;
     	return 1;
   }else if(str == "round" && CODE == 3){
     	tell_object(TP,"%^BOLD%^You press the round stone and hear a click.\n");
     	tell_room(ETP,""+TPQCN+" presses the round stone and you hear a click.\n",TP);
     	CODE = 4;
     	return 1;
 	}else if(str == "triangle" && CODE == 4){
     	tell_object(TP,"%^BOLD%^You press the triangular stone "+
     		"again and hear a click.\n");
     	tell_room(ETP,""+TPQCN+" presses the triangular stone "+
     		"again and you hear a click.\n",TP);
     	(SARADIN+"hid_hall0")->add_exit(STEFANO+"tunnel7","door");
     	add_exit(SARADIN+"hid_hall0","door");
     	tell_room(ETP,"You hear a grating sound as a section of "+
     		"the wall in the west slides back a bit then swings "+
     		"away revealing a hidden hallway.\n");
     	tell_room(STEFANO+"tunnel6","You hear a grating sound to the north.\n",({TP,ETP}));
     	tell_room(STEFANO+"tunnel8","You hear a grating sound to the south.\n",({TP,ETP}));  	
     	CODE = 0;
     	return 1;
 	}else{
 		tell_object(TP,"You press the stone and you hear several clicks as "+
 			"the lock resets itself.\n");
 		tell_room(ETP,""+TPQCN+" presses the stone and you hear several clicks.\n",TP);
 		CODE = 0;
 		return 1;
 	}
}
int close_em(string str) {
 	if(!str) {
   	tell_object(TP,"Close what?");
      return 1;
   }
  	if(str == "door" || str == "secret door"){
  		if(member_array("door",TO->query_exits()) != -1) {
     		tell_object(TP,"You pull the door closed.\n");
     		tell_room(ETP,""+TPQCN+" pulls the door closed.\n",TP);
     		remove_exit("door");
     		(SARADIN+"hid_hall0")->remove_exit("door");
     		tell_room(SARADIN+"hid_hall0","Someone closes the door "+
     			"from the other side.\n",TP);
     		return 1;
     	}
     	tell_object(TP,"What door?");
		return 1;
	}
}
