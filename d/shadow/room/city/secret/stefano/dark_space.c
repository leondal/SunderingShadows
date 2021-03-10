//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit VAULT;

void create(){
	::create();
	set_name("dark space");
   set_short("dark space");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"You are in a dark space behind the shelves in the "+
   	"magistrate's office.  It is dusty, cramped, and "+
   	"empty with about two feet of clearance between "+
   	"the shelving and the back wall."+
   	"%^RESET%^"
   );
   set_property("indoors",1);
   set_property("light",1);
   set_smell("default","Dust tickles your nose making you almost sneeze.");
   set_listen("default","You can hear some sounds from the magistrate's "+
   	"office and your own breathing.");
   set_items(([
  	]));
   set_exits(([
      "out" : "/d/shadow/city/room/moffice",
   ]));
}
void init() {
  	::init();
  	add_action("pull_em","pull");
	add_action("push_em","push");
}
int pull_em(string str) {
 	if(!str) {
   	tell_object(TP,"Pull what?");
      return 1;
   }
  	if(str == "shelf closed" || str == "shelves closed"){
  		if(member_array("out",TO->query_exits()) != -1) {
     		tell_object(TP,"You pull the shelves closed behind you hiding the entrance "+
     			"once again.\n");
			remove_exit("out");
			if(member_array("east","/d/shadow/city/room/moffice"->query_exits()) != -1) {
     		tell_room("/d/shadow/city/room/moffice",""+TPQCN+" pulls the shelves closed, hiding the exit again.\n",TP);
     		"/d/shadow/city/room/moffice"->remove_exit("east");
     		return 1;
     	}
     	tell_object(TP,"You have already done that and there seems "+
     		"to be no way to undo it!.");
		return 1;
	}
}
}

int push_em(string str) {
 	if(!str) {
   	tell_object(TP,"Push the shelf?");
      return 1;
   }
  	if(str == "shelf" || str == "shelves"){
    tell_object(TP,"%^BOLD%^%^WHITE%^The door pushes out into the light of the office.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" pushes the door open allowing the light of the office to spill in.%^RESET%^",TP);
     add_exit("/d/shadow/city/room/moffice","out");
       tell_room("/d/shadow/city/room/moffice","%^BOLD%^%^WHITE%^The shelves suddenly swing open!%^RESET%^");
       "/d/shadow/city/room/moffice"->add_exit("/d/shadow/room/city/secret/stefano/dark_space","east");
	   return 1;
     }
   }
