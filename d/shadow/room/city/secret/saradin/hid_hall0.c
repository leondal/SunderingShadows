//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit VAULT;

void create(){
	::create();
	set_name("hidden hallway");
   set_short("hidden hallway");
   set_long(
   	"%^RESET%^%^ORANGE%^"+
   	"This is a secret passageway that branches off the "+
   	"main tunnel.  The room is relatively well kept for "+
   	"having been dug primatively out of the ground.  There "+
   	"is a small lever on the east wall."+
   	"%^RESET%^\n"
   );
   set_property("indoors",1);
   set_property("light",1);
   set_smell("default","You smell old sweat.");
   set_listen("default","The room is quiet save for the sounds you make.");
   set_items(([
   	({"wall","walls","floor","ceiling"}) : "The walls are made of dirt and "+
   		"stone and seem to have been dug quickly, but "+
   		"efficiently.  Little work was done to make them "+
   		"look prettier after the tunneling was complete.\n"
  	]));
   set_exits(([
		"north" : SARADIN+"hid_hall"
	]));
}
void init() {
  	::init();
  	add_action("pull_em","pull");
  	add_action("close_em","close");
}
int pull_em(string str) {
 	if(!str) {
   	tell_object(TP,"Pull what?");
      return 1;
   }
  	if(str == "lever"){
  		if(member_array("door",TO->query_exits()) != -1) {
  			tell_object(TP,"You pull the lever, but nothing happens.\n");
  			return 1;
  		}
     	tell_object(TP,"You pull the lever and a secret door opens "+
     		"in the east wall.\n");
     	tell_room(ETP,""+TPQCN+" pull a lever and the secret door "+
     		"in the east wall opens up.\n",TP);
     	tell_room(STEFANO+"tunnel7","The secret door swings open.",TP);
     	(STEFANO+"tunnel7")->add_exit(SARADIN+"hid_hall0","door");
     	add_exit(STEFANO+"tunnel7","door");
     	return 1;
   }
	return 1;
}
int close_em(string str) {
 	if(!str) {
   	tell_object(TP,"Close what?");
      return 1;
   }
	if(str == "secret door" || str == "door"){
  		if(member_array("door",TO->query_exits()) != -1) {
     		tell_object(TP,"You close the secret door.\n");
     		tell_room(ETP,""+TPQCN+" closes the secret door.\n",TP);
     		tell_room(STEFANO+"tunnel7","%^BOLD%^The door is closed "+
     			"from the other side.\n",TP);
     		(STEFANO+"tunnel7")->remove_exit("door");
     		remove_exit("door");
     		return 1;
     	}
     	tell_object(TP,"You have already done that.");
		return 1;
	}
	return 1;
}
