//Titania 10/21/2019
//Shadow Sewers, Room 14

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
   "haphazardly out of wooden boards. A small knob jutting out of the eastern wall catches your eye.%^WHITE%^\n");
   set_smell("default","You smell the disgusting confluence of refuse "+
      "and excrement wafting all about you.");
   set_listen("default","You hear flowing water echoing throughout "+
      "the tunnel.");
   set_items(([
      ({"tunnel","sewer","walls","bricks"}) : "%^RESET%^%^GREEN%^Layer upon layer of %^BOLD%^filth%^RESET%^%^GREEN%^ "+
	  "and %^BOLD%^slime%^RESET%^%^GREEN%^ cover the walls, the scent of it "+ 
	  "purely putrid and nauseating.",
      ({"culvert","wastewater","water"}) : "%^BOLD%^%^BLACK%^You are in the bowels of sewer tunnels beneath a bustling city. "+
	  "It smells like crap, literally. The %^RESET%^%^ORANGE%^'water'%^BOLD%^%^BLACK%^ is everything you imagined it would be.%^RESET%^",
      ({"bridges","bridge","wooden boards","boards"}) : "%^RESET%^%^ORANGE%^Caution is advised if you plan on trying to cross this precarious planking.%^RESET%^",
      ({"walkway","walkways"}) : "%^RESET%^%^GREEN%^The walkways are terribly slick and every step is a step closer to finding yourself carried away in decades worth of sewerage.%^RESET%^",
	  ({"knob"}) : "Half hidden behind some pipes, this little knob is distinctly inconspicuous. Somebody definitely didn't want you to turn it.",
   ]));
   set_exits(([
      "south" : ROOMS"sewer13",
      "west" : ROOMS"sewer15",
	  "north" : ROOMS"sewer21",
   ]));
}

void init() {
   ::init();
   add_action("turn","turn");
}

void reset() {
   ::reset();
   if(member_array("tunnel",TO->query_exits()) != -1) {
     tell_room(TO,"%^ORANGE%^A section of the wall slides closed.%^RESET%^");
     remove_exit("tunnel");
     if(member_array("sewer",ROOMS"tunnel1"->query_exits()) != -1) {
       tell_room(ROOMS"tunnel1","%^ORANGE%^The wall slides "
"back into place, closing off the secret passage.%^RESET%^");
       ROOMS"tunnel1"->remove_exit("sewer");
     }
   }
}

int turn(string str) {
   if(!str) return notify_fail("Turn what?\n");
   if(str != "knob") return notify_fail("Turn what?\n");
   if(member_array("tunnel",ETP->query_exits()) != -1) {
     tell_object(TP,"%^BOLD%^%^WHITE%^You turn the tiny knob and the small "
"opening in the wall slides shut.%^RESET%^");
     tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" turns the knob and the wall "
"slides soundlessly shut.%^RESET%^",TP);
     remove_exit("tunnel");
     if(member_array("sewer",ROOMS"tunnel1"->query_exits()) != -1) {
       tell_room(ROOMS"tunnel1","%^BOLD%^%^WHITE%^The opening in the wall slides "
"soundlessly closed.%^RESET%^");
       ROOMS"tunnel1"->remove_exit("sewer");
     }
   }
   else {
     tell_object(TP,"%^BOLD%^%^WHITE%^You turn the knob and a section of the wall "
"slides to the side, revealing a narrow tunnel.%^RESET%^");
     tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" turns the knob and a section of the "
"wall slides to the side to reveal a narrow tunnel.%^RESET%^",TP);
     add_exit(ROOMS"tunnel1","tunnel");
     if(member_array("sewer",ROOMS"tunnel1"->query_exits()) == -1) {
       tell_room(ROOMS"tunnel1","%^BOLD%^%^BLACK%^A section of the wall slides "
"to the side, and the stench of fetid sewerage nearly blinds you.%^RESET%^");
       ROOMS"tunnel1"->add_exit(ROOMS"sewer14","sewer");
     }
   }
   return 1;
}
