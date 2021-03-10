//Coded by Diego//

#include <std.h>
#include "../secrets.h"

inherit ROOM;

void create(){
	::create();
	set_name("tunnel");
   set_short("tunnel");
   set_long(
   	"%^BOLD%^%^BLACK%^"+
   	"You are in a tunnel leading northeast and southwest."+
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
   set_smell("default","It smells like rotten sewerage here. Weird.");
   set_listen("default","You can hear muffled unidentified noises.");
   set_items(([
   	({"floor","walls","wall","ceiling"}) : "The entire tunnel "+
   		"is made of native stone that has been cut, and mortared, "+
   		"to fit together perfectly.  The construction has made the "+
   		"tunnel extremely stable and is of very high quality.  "+
   		"You notice a faint seam line along the southern wall.",
   	({"chisel marks", "chisel mark", "marks", "mark"}) : "The marks "+
   		"are not easily seen and are no doubt a code placed by the "+
   		"builders for a purpose that only they can say.  Knowing "+
   		"dwarves it is probably the amount of minutes since their "+
   		"last ale.  This section of wall has seven marks.",
   	"stones" : "The stones here are much the same as the rest "+
   		"of the tunnel except for the interesting shapes of three "+
   		"of them on the west wall."
  	]));
   set_exits(([
   	"northeast" : STEFANO+"tunnel1",
   	"southwest" : STEFANO+"tunnel3"
	]));
	set_search("wall","Upon further inspection you find a small handle at the base of the door. Perhaps you could try lifting it?");
}

void init() {
  	::init();
  	add_action("lift","lift");
	add_action("lower","lower");
}
int lower(string str) {
 	if(!str) {
   	tell_object(TP,"Are you trying to lower the door?");
      return 1;
   }
  	if(str == "handle" || str == "door"){
  		if(member_array("sewer",TO->query_exits()) != -1) {
     		tell_object(TP,"You give the handle a tug and the door slowly rolls down, sealing off the hidden passage.\n");
			tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" gives a tug on the door and it slowly rolls down, sealing off the hidden passage.%^RESET%^",TP);
			remove_exit("sewer");
			if(member_array("tunnel","/d/shadow/city/room/sewer41"->query_exits()) != -1) {
     		tell_room("/d/shadow/city/room/sewer41","The door slowly rolls down, sealing off the hidden passage.\n",TP);
     		"/d/shadow/city/room/sewer41"->remove_exit("tunnel");
     		return 1;
     	}
     	tell_object(TP,"The door is already shut.");
		return 1;
	}
}
}

int lift(string str) {
 	if(!str) {
   	tell_object(TP,"Maybe try lifting the door?");
      return 1;
   }
  	if(str == "handle" || str == "door"){
    tell_object(TP,"%^BOLD%^%^WHITE%^The scent of raw sewerage hits you in the face as you roll up the door.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^WHITE%^The scent of raw sewerage hits you in the face as "+TPQCN+" yanks open the door.%^RESET%^",TP);
     add_exit("/d/shadow/city/room/sewer41","sewer");
       tell_room("/d/shadow/city/room/sewer41","%^BOLD%^%^WHITE%^A door slowly raises, revealing the disgusting city sewer system. So that's where that stench was coming from.%^RESET%^");
       "/d/shadow/city/room/sewer41"->add_exit("/d/shadow/room/city/secret/stefano/tunnel2","tunnel");
	   return 1;
     }
   }