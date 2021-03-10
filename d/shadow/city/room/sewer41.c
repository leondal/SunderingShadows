//Titania 10/21/2019
//Shadow Sewers, Room 41

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_long("%^ORANGE%^This %^BOLD%^%^BLACK%^dank tunnel %^RESET%^%^ORANGE%^is "+ 
   "constructed out of ancient stout bricks that are covered in a patina of "+ 
   "%^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^i%^BOLD%^l%^BLACK%^t%^RESET%^%^GREEN%^h "+ 
   "%^ORANGE%^and %^BOLD%^%^GREEN%^sl%^BLACK%^i%^RESET%^%^GREEN%^m%^BOLD%^e%^RESET%^%^ORANGE%^. "+ 
   "The tunnel is roughly half-circular in shape, measuring twenty feet across, "+ 
   "and almost twenty feet high at its apex. There are five foot wide walkways "+ 
   "on either side, allowing access all the way down the tunnel. Running down "+ 
   "the middle of the tunnel in between the walkways, is a %^BOLD%^%^BLACK%^culvert "+ 
   "%^RESET%^%^ORANGE%^containing the city's "+ 
   "%^BOLD%^%^BLACK%^w%^RESET%^%^ORANGE%^a%^GREEN%^s%^BOLD%^%^BLACK%^tewa%^RESET%^%^GREEN%^t%^ORANGE%^e%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^, "+ 
   "and who knows what else. Periodically, small pipes jut out of the walls of the tunnel "+ 
   "and hang over the edge of the culvert, allowing wastewater to drain. Access over "+ 
   "the culvert is offered by %^WHITE%^bridges %^ORANGE%^constructed "+ 
   "haphazardly out of wooden boards.%^WHITE%^\n");
   set_items(([
      ({"tunnel","sewer","walls","bricks"}) : "%^RESET%^%^GREEN%^Layer upon layer of %^BOLD%^filth%^RESET%^%^GREEN%^ "+
	  "and %^BOLD%^slime%^RESET%^%^GREEN%^ cover the walls, the scent of it "+ 
	  "purely putrid and nauseating. You notice what seems to be a seam of a door on a wall.",
      ({"culvert","wastewater","water"}) : "%^BOLD%^%^BLACK%^You are in the bowels of sewer tunnels beneath a bustling city. "+
	  "It smells like crap, literally. The %^RESET%^%^ORANGE%^'water'%^BOLD%^%^BLACK%^ is everything you imagined it would be.%^RESET%^",
      ({"bridges","bridge","wooden boards","boards"}) : "%^RESET%^%^ORANGE%^Caution is advised if you plan on trying to cross this precarious planking.%^RESET%^",
      ({"walkway","walkways"}) : "%^RESET%^%^GREEN%^The walkways are terribly slick and every step is a step closer to finding yourself carried away in decades worth of sewerage.%^RESET%^",
   ]));
   set_search("wall","Upon further inspection you find a small handle at the base of the door. Perhaps you could try lifting it?");
   set_exits(([
	  "southeast" : ROOMS"sewer42",
   ]));
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
  	if(str == "door" || str == "handle"){
  		if(member_array("tunnel",TO->query_exits()) != -1) {
     		tell_object(TP,"You give the handle a tug and the door slowly rolls down, sealing off the hidden passage.\n");
			tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" gives a tug on the door and it slowly rolls down, sealing off the hidden passage.%^RESET%^",TP);
			remove_exit("tunnel");
			if(member_array("sewer","/d/shadow/room/city/secret/stefano/tunnel2"->query_exits()) != -1) {
     		tell_room("/d/shadow/room/city/secret/stefano/tunnel2","The door slowly rolls down, sealing off the hidden passage.\n",TP);
     		"/d/shadow/room/city/secret/stefano/tunnel2"->remove_exit("sewer");
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
    tell_object(TP,"%^BOLD%^%^WHITE%^You yank upwards on the handle and the door seamlessly rolls upwards.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" yanks upwards on the handle and the door seamlessly rolls open.%^RESET%^",TP);
     add_exit("/d/shadow/room/city/secret/stefano/tunnel2","tunnel");
       tell_room("/d/shadow/room/city/secret/stefano/tunnel2","%^BOLD%^%^WHITE%^A door slowly raises, revealing the disgusting city sewer system. So that's where that stench was coming from.%^RESET%^");
       "/d/shadow/room/city/secret/stefano/tunnel2"->add_exit("/d/shadow/city/room/sewer41","sewer");
	   return 1;
     }
   }
