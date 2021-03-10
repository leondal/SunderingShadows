//Titania 10/21/2019
//Shadow Sewers, Room 16

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_long(::query_long()+"\n%^BOLD%^%^BLACK%^There's an interesting %^RESET%^sigil%^BOLD%^%^BLACK%^ carved into the wall here.\n");
   set_items(([
	({"tunnel","sewer","walls","bricks"}) : "%^RESET%^%^GREEN%^Layer upon layer of %^BOLD%^filth%^RESET%^%^GREEN%^ "+
	"and %^BOLD%^slime%^RESET%^%^GREEN%^ cover the walls, the scent of it "+ 
	"purely putrid and nauseating.",
	({"culvert","wastewater","water"}) : "%^BOLD%^%^BLACK%^You are in the bowels of sewer tunnels beneath a bustling city. "+
	"It smells like crap, literally. The %^RESET%^%^ORANGE%^'water'%^BOLD%^%^BLACK%^ is everything you imagined it would be.%^RESET%^",
	({"bridges","bridge","wooden boards","boards"}) : "%^RESET%^%^ORANGE%^Caution is advised if you plan on trying to cross this precarious planking.%^RESET%^",
	({"walkway","walkways"}) : "%^RESET%^%^GREEN%^The walkways are terribly slick and every step is a step closer to finding yourself carried away in decades worth of sewerage.%^RESET%^",
	({"sigil"}) : "%^GREEN%^It appears to be in the shape of a thin feather. There's a small plaque beneath it. Maybe you can read it?%^RESET%^",
	]));
   set_exits(([
      "north" : ROOMS"sewer15",
   ]));
}

void init(){
    ::init();
	add_action("make","make");
	add_action("read","read");
}

int make(string str){
	if(str != "thief sign") return notify_fail("Make what?\n");
	if(TP->query_invis()){
	tell_object(TP, "You sign to the room that you are a thief.");
	return 1;
}
	if(!TP->is_class("thief") && !TP->is_class("assassin") &&
	!TP->is_class("bard")) {
	tell_object(TP, "%^BOLD%^%^RED%^The sigil abruptly flares a dim red and you find yourself moved.%^RESET%^");
	tell_room(ETP, "%^BOLD%^%^RED%^A sigil on the wall flashes dim red as "+TPQCN+" makes a subtle hand gesture toward it.%^RESET%^", TP);
	TP->move_player(ROOMS"thieflounge");
} else {
	tell_object(TP, "%^BOLD%^%^WHITE%^The sigil briefly flashes with a white light and you find yourself moved.%^RESET%^");
	if(random(40) > (TP->query_stats("dexterity") +
	TP->query_stats("intelligence")))
	tell_room(ETP, "%^BOLD%^%^WHITE%^A sigil on the wall flares as "+TPQCN+" makes a subtle hand gesture.%^RESET%^", TP);
	TP->move(ROOMS"thieflounge");
	TP->describe_current_room(1);
}
return 1;
}

int read(string str) {
   if(str != "plaque") {
   return 0;
   }
   if(TP->is_class("thief") || TP->is_class("bard") || TP->is_class("assassin")) {
      tell_object(TP,"%^BOLD%^%^BLUE%^To gain entrance to the guild, sign that you belong.");
      return 1;
   }
   else{
      tell_object(TP,"You can decipher no meaning from the scratches on the plaque!");
      tell_room(ETP,""+TPQCN+" glances at the plaque and looks confused.",TP);
      return 1;
      }
}