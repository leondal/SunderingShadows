//Titania 10/21/2019
//Shadow Sewers, Room 42

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_long(::query_long()+"\n%^BOLD%^%^BLACK%^A small metal ladder leads up to a grate far above your head.\n");
   set_items(([
	({"tunnel","sewer","walls","bricks"}) : "%^RESET%^%^GREEN%^Layer upon layer of %^BOLD%^filth%^RESET%^%^GREEN%^ "+
	"and %^BOLD%^slime%^RESET%^%^GREEN%^ cover the walls, the scent of it "+ 
	"purely putrid and nauseating.",
	({"culvert","wastewater","water"}) : "%^BOLD%^%^BLACK%^You are in the bowels of sewer tunnels beneath a bustling city. "+
	"It smells like crap, literally. The %^RESET%^%^ORANGE%^'water'%^BOLD%^%^BLACK%^ is everything you imagined it would be.%^RESET%^",
	({"bridges","bridge","wooden boards","boards"}) : "%^RESET%^%^ORANGE%^Caution is advised if you plan on trying to cross this precarious planking.%^RESET%^",
	({"walkway","walkways"}) : "%^RESET%^%^GREEN%^The walkways are terribly slick and every step is a step closer to finding yourself carried away in decades worth of sewerage.%^RESET%^",
	({"ladder"}) : "%^GREEN%^An access ladder here leads up to a grate in the ceiling. Hazy slivers of light manage to cut through the dark and dreary tunnel.%^RESET%^",
	({"grate"}) : "%^BOLD%^%^BLACK%^It might be possible to move the grate in order to open or close it.%^RESET%^",
	]));
	set_exits(([
	"east" : ROOMS"sewer36",
	"northwest" : ROOMS"sewer41",
	]));
}

void init() {
  	::init();
  	add_action("open","open");
	add_action("close","close");
}
int close(string str) {
 	if(!str) {
   	tell_object(TP,"Open what?");
      return 1;
   }
  	if(str == "grate"){
  		if(member_array("up",TO->query_exits()) != -1) {
     		tell_object(TP,"You slide the grate back into place.\n");
			tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" slides the heavy grate back into place.%^RESET%^",TP);
			remove_exit("up");
			if(member_array("down",ROOMS"westwall5"->query_exits()) != -1) {
     		tell_room(ROOMS"westwall5","Someone closes the grate from down below.\n",TP);
     		ROOMS"westwall5"->remove_exit("down");
     		return 1;
     	}
     	tell_object(TP,"The grate is as closed as it can possibly be.");
		return 1;
	}
}
}

int open(string str) {
 	if(!str) {
   	tell_object(TP,"What are you trying to open?");
      return 1;
   }
  	if(str == "grate"){
    tell_object(TP,"%^BOLD%^%^WHITE%^You slowly move aside the heavy grate and feel grateful for the fresh air from above.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^WHITE%^Merciful fresh air rushes in as "+TPQCN+" slides open the grate leading out of the sewers.%^RESET%^",TP);
     add_exit(ROOMS"westwall5","up");
       tell_room(ROOMS"westwall5","BOLD%^%^WHITE%^The grate in the street slowly slides open, filling the room with the putried stench of the sewers.RESET%^");
       ROOMS"westwall5"->add_exit(ROOMS"sewer42","down");
	   return 1;
     }
   }