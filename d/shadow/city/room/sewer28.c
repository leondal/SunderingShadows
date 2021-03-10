//Titania 10/21/2019
//Shadow Sewers, Room 28

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
      set_long("%^BLUE%^Inside the f%^GREEN%^e%^BLUE%^t%^GREEN%^i"+
      "%^BLUE%^d sewers below %^BOLD%^%^BLACK%^Shadow%^RESET%^\n%^ORANGE%^This %^BOLD%^%^BLACK%^dank tunnel %^RESET%^%^ORANGE%^is "+ 
   "constructed out of ancient stout bricks that are covered in a patina of "+ 
   "%^BOLD%^%^GREEN%^f%^RESET%^%^GREEN%^i%^BOLD%^l%^BLACK%^t%^RESET%^%^GREEN%^h "+ 
   "%^ORANGE%^and %^BOLD%^%^GREEN%^sl%^BLACK%^i%^RESET%^%^GREEN%^m%^BOLD%^e%^RESET%^%^ORANGE%^. "+
   "The wall here seems to be in a terrible state of decay and disrepair, so much that it has started to crumble. "+
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
   set_exits(([
	  "south" : ROOMS"sewer27",
   ]));
   set_items(([
      ({"tunnel","sewer","walls","bricks"}) : "%^RESET%^%^GREEN%^Layer upon layer of %^BOLD%^filth%^RESET%^%^GREEN%^ "+
	  "and %^BOLD%^slime%^RESET%^%^GREEN%^ cover the walls, the scent of it "+ 
	  "purely putrid and nauseating. The wall is in such a crumbling state of decay that some of the bricks have fallen, making a hole that you might be able to climb through.",
      ({"culvert","wastewater","water"}) : "%^BOLD%^%^BLACK%^You are in the bowels of sewer tunnels beneath a bustling city. "+
	  "It smells like crap, literally. The %^RESET%^%^ORANGE%^'water'%^BOLD%^%^BLACK%^ is everything you imagined it would be.%^RESET%^",
      ({"bridges","bridge","wooden boards","boards"}) : "%^RESET%^%^ORANGE%^Caution is advised if you plan on trying to cross this precarious planking.%^RESET%^",
      ({"walkway","walkways"}) : "%^RESET%^%^GREEN%^The walkways are terribly slick and every step is a step closer to finding yourself carried away in decades worth of sewerage.%^RESET%^",
	  "hole" : "%^RESET%^It might be possible to %^BOLD%^climb%^RESET%^ through the hole.",
	  "wall" : "The wall is rotting away from top to bottom. It seems there's a bit of a hole near the top of the wall.",
   ])); 
}

void init() {
  	::init();
  	add_action("climb","climb");
}

int climb(string str){
  	if(str == "hole" || str == "through hole"){
	tell_object(TP,"%^RESET%^%^ORANGE%^You manage to climb over the broken bricks and into a narrow dirt tunnel.%^RESET%^\n");
	tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+" climbs over the broken bricks, disappearing to the other side of the wall.%^RESET%^",TP);
	TP->move_player(ROOMS"dirttunnel18");
	}
}
