//Coded by Diego//
// alterations by Styx when Stefano and Saradin had to burn the evidence of their smuggling


#include <std.h>
#include "../secrets.h"

inherit VAULT;
int BRICK;

void create(){
	::create();
	set_name("cellar");
   set_short("cellar");
   set_long( (: TO, "ldesc1" :));
   set_property("indoors",1);
   set_property("light",1);
//   set_smell("default","The air has a dusty, earthy smell nearly masked by the acrid smell of smoke.");
   set_smell("default","You smell an acrid stench from the soot and burned items.");
   set_listen("default","Faint noises of the city filter down from above.");
   set_items(([
   	"ceiling" : "You see that the lines are the outline of a trapdoor.",
   	"floor" : "The floor is made of dirt and is fairly dry.  "+
   		"There are numerous footprints in the dirt and drag "+
   		"marks beside some of the crates.",
   	({"footprints","footprint"}) : "The markings seem to mill "+
   		"about the room with no definite destination.",
   	({"crates","boxes","crate","box"}) : "The boxes and crates "+
   		"appear to have been stacked carefully."
  	]));
  	set_search("crates","The crates and boxes are empty although it "+
  		"appears they once contained items.  Marks can be "+
  		"seen on the floor at the base of the crates.\n");
/*  	set_search("crates","The crates and boxes are filled with "+
  		"assorted contraband and other smuggled goods.  Marks can be "+
  		"seen on the floor at the base of the crates.\n");
  	set_search("crate","The crates and boxes are filled with "+
  		"assorted contraband and other smuggled goods.  Marks can be "+
  		"seen on the floor at the base of the crates.\n");
  	set_search("boxes","The crates and boxes are filled with "+
  		"assorted contraband and other smuggled goods.  Marks can be "+
  		"seen on the floor at the base of the crates.\n");
  	set_search("box","The crates and boxes are filled with "+
  		"assorted contraband and other smuggled goods.  Marks can be "+
  		"seen on the floor at the base of the crates.\n");
*/
  	set_search("floor","The floor is made of dirt and shows distinctly "+
  		"that the crates have been dragged to one side then put "+
  		"back in the same place.\n");
  	set_search("ceiling","You easily trace the outlines of a trapdoor "+
  		"in the ceiling, opening it should be no problem.\n");
  	set_search("lines","These markings appear to be the outline of a "+
  		"trapdoor in the ceiling.  Opening the door should pose no problem.\n");
   set_exits(([
	]));
	BRICK = 0;
}
void init() {
  	::init();
  	add_action("close_em","close");
  	add_action("open_em","open");
  	add_action("drag_em","drag");
  	add_action("press_em","press");
  	add_action("stamp_em","stamp");
  	add_action("cover_em","cover");
	add_action("stamp_em", "stomp");
}

int cover_em(string str) {
 	if(!str) {
   	tell_object(TP,"Cover what?");
      return 1;
   }
   if(BRICK == 0){
   	tell_object(TP,"Cover what brick?\n");
   	return 1;
   }
  	if(str == "brick"){
     	tell_object(TP,"You drag the crates back into place covering the embedded brick.");
     	tell_room(ETP,""+TPQCN+" drags the crates back over the brick.",TP);
   	set_long( (: TO, "ldesc1" :) );
/*   		"%^RESET%^%^ORANGE%^"+
   		"This is a roughly circular space about twenty feet "+
   		"in diameter with rough brick walls and a dirt floor.  "+
   		"You see lines in the ceiling.  Boxes and crates are "+
   		"neatly stacked at the center of the room."+
   		"%^RESET%^"
   	);
*/
   	add_item("brick","What brick do you wish to look at?");
   	BRICK = 0;
     	return 1;
	}
}

int stamp_em(string str) {
	if(!str) {
   	tell_object(TP,"%^BOLD%^Are you just throwing a fit "+
   		"or are you stamping on anything in particular?");
      return 1;
   }
   if(BRICK == 0){
   	tell_object(TP,"%^BOLD%^What brick?  Are we getting the "+
   		"cart before the horse?\n");
   	return 1;
   }
   if(str == "brick" || str == "on brick"){
  	if(member_array("tunnel",TO->query_exits()) != -1) {
      	tell_object(TP,"You have already done that!.");
         return 1;
   }
   tell_object(TP,"You stamp on the brick and a secret door "+
  		"opens to a tunnel.\n");
   tell_room(ETP,""+TPQCN+" stamps on the floor and a secret door opens.\n",TP);
   tell_room(STEFANO+"tunnel","The secret door in the south wall opens.\n",TP);
   add_exit(STEFANO+"tunnel","door");
   (STEFANO+"tunnel")->add_exit(STEFANO+"cellar","door");
   return 1;
   }
}

int press_em(string str) {
 	if(!str) {
   	tell_object(TP,"Press what?");
      return 1;
   }
  	if(str == "brick"){
     	tell_object(TP,"%^BOLD%^You press the brick. "+
     		"%^YELLOW%^BRILLIANT!  %^RESET%^%^BOLD%^I bet "+
     		"your parents are really proud of you.  You do "
		"notice that it seems to have footprints on it.");
     	tell_room(ETP,""+TPQCN+" bends down and presses the brick.",TP);
     	return 1;
	}
}
int drag_em(string str) {
 	if(!str) {
   	tell_object(TP,"Drag what?");
      return 1;
   }
  	if(str == "crate" || str == "crates"){
     	tell_object(TP,"You drag the crates to the side and see "+
     		"only a single brick embedded into the floor doubtless "+
     		"left here by the builders.\n");
     	tell_room(ETP,""+TPQCN+" drags the crates to the side.\n",TP);
   	set_long( (: TO, "ldesc2" :) );
/* I think the crates were meant to be at the side at this point too.
   		"%^RESET%^%^ORANGE%^"+
   		"This is a roughly circular space about twenty feet "+
   		"in diameter with rough brick walls and a dirt floor.  "+
   		"Boxes and crates are neatly stacked at the center of the "+
   		"room.  There is a brick in the floor"+
   		"%^RESET%^"
   	);
*/
   	add_item("brick","There is a brick in the floor here that was "+
   		"once covered by crates.  It was probably left here by the "+
   		"builders and has become embedded in the dirt floor.  You "
		"notice it has dusty footprints on it.");
   	BRICK = 1;
     	return 1;
	}
}

int close_em(string str) {
 	if(!str) {
   	tell_object(TP,"close what?");
      return 1;
   }
  	if(str == "trapdoor" || str == "trap door"){
  		if(member_array("trapdoor",TO->query_exits()) != -1) {
     		tell_object(TP,"You close the trapdoor with a barely audible click.\n");
     		tell_room(ETP,""+TPQCN+" pushes the trapdoor in the ceiling closed.\n",TP);
     		tell_room("/d/shadow/city/room/moffice","%^BOLD%^You hear a barely audible click.\n",TP);
     		("/d/shadow/city/room/moffice")->remove_exit("down");
     		remove_exit("trapdoor");
     		return 1;
     	}
     	tell_object(TP,"You have already done that and there seems "+
     		"to be no way to undo it!");
		return 1;
	}
	if(str == "secret door" || str == "door"){
  		if(member_array("door",TO->query_exits()) != -1) {
     		tell_object(TP,"You close the secret door.");
     		tell_room(ETP,""+TPQCN+" closes the secret door.",TP);
     		tell_room(STEFANO+"tunnel","%^BOLD%^The secret door is closed "+
     			"from the other side.",TP);
     		(STEFANO+"tunnel")->remove_exit("door");
     		remove_exit("door");
     		return 1;
     	}
     	tell_object(TP,"You have already done that.");
		return 1;
	}
}
int open_em(string str) {
 	if(!str) {
   	tell_object(TP,"Open what?");
      return 1;
   }
  	if(str == "trapdoor" || str == "trap door"){
  		if(member_array("trapdoor",TO->query_exits()) != -1) {
     		tell_object(TP,"You have already opened that door!");
			return 1;
		}
  		tell_object(TP,"You open the trapdoor.\n");
     	tell_room(ETP,""+TPQCN+" opens a trapdoor in the ceiling.",TP);
     	tell_room("/d/shadow/city/room/moffice","%^BOLD%^You hear a barely audible click.",TP);
     	("/d/shadow/city/room/moffice")->add_exit(STEFANO+"cellar","down");
     	add_exit("/d/shadow/city/room/moffice","trapdoor");
     	return 1;
	}
}

string ldesc1() {
    return("%^RESET%^%^ORANGE%^"+
   	"This is a roughly circular space about twenty feet "+
   	"in diameter with rough brick walls and a dirt floor.  "+
   	"You see faint lines on the ceiling.  Boxes and crates are "+
   	"neatly stacked at the center of the room.  There is a "+
        "%^BOLD%^%^BLACK%^dense black soot %^RESET%^%^ORANGE%^covering "
	"nearly everything except the boxes and crates in the center.  "
	"The ashes and remnants of what must have been a large pile of "
	"various things now melted or burned to ash are in one corner.  "
	"The walls and ceiling are also singed as though the apparently "
	"intense fire flashed through most of the room."
   	"%^RESET%^"
   );
}

string ldesc2() {
   return("%^RESET%^%^ORANGE%^"+
   	"This is a roughly circular space about twenty feet "+
   	"in diameter with rough brick walls and a dirt floor.  "+
   	"You see faint lines on the ceiling.  Boxes and crates are "+
   	"sitting to one side of the room.  There is a "+
        "%^BOLD%^%^BLACK%^dense black soot %^RESET%^%^ORANGE%^covering "
	"nearly everything except the boxes and crates.  "
	"The ashes and remnants of what must have been a large pile of "
	"various things now melted or burned to ash are in one corner.  "
	"The walls and ceiling are also singed as though the apparently "
	"intense fire flashed through most of the room.  There is a loose "
	"brick near the center of the floor."
   	"%^RESET%^"
   );
}
