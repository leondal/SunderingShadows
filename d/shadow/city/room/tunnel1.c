//Titania 10/21/2019
//Shadow Sewers, Rat Tunnel, Room 1

#include <std.h>
#include "../defs.h"
inherit INH"tunnel";

void create(){
   ::create();
   set_long("%^BOLD%^%^ORANGE%^The walls of this narrow tunnel are shaped of heavy "+ 
	"%^RESET%^%^RED%^red clay %^BOLD%^%^ORANGE%^and %^RESET%^%^WHITE%^stone%^BOLD%^%^ORANGE%^. The roof is high "+ 
	"enough that most creatures could pass unimpeded. The entire structure is "+ 
	"sturdy and smooth, as if carefully shaped by mortal hands. The passage is "+ 
	"narrow, however, and a bit claustrophobic. Otherwise, the walls are so "+ 
	"remarkably smooth, and the floor so carefully kept, that travel is "+ 
	"not difficult. The tunnel proceeds at a bit of a downward slope.\n%^WHITE%^");
	set_smell("default","There is a rich, earthy smell of old stones and dirt.");
	set_listen("default","It's very quiet here.");
	set_items(([
	({"walls","wall","floor","roof"}) : "%^MAGENTA%^Despite being narrow, this tunnel is so carefully "+ 
	"crafted, and the walls and roof are so sturdy, and the ground so flat and clean, "+ 
	"you walk easily and without any fear of being crushed "+ 
	"by the weight of the ground above you. There is a easily missed knob in the western wall.%^WHITE%^",
	({"knob"}) : "It is the sort of knob that's meant for turning.",
	]));
   set_exits(([
      "east" : ROOMS"tunnel2",
   ]));
}

void init() {
   ::init();
   add_action("turn","turn");
}

void reset() {
   ::reset();
   if(member_array("sewer",TO->query_exits()) != -1) {
     tell_room(TO,"%^ORANGE%^A section of the wall slides shut.%^RESET%^");
     remove_exit("sewer");
     if(member_array("tunnel",ROOMS"sewer14"->query_exits()) != -1) {
       tell_room(ROOMS"sewer14","%^ORANGE%^The wall slides shut.%^RESET%^");
       ROOMS"sewer14"->remove_exit("tunnel");
     }
   }
}

int turn(string str) {
   if(!str) return notify_fail("Turn what?\n");
   if(str != "knob") return notify_fail("Turn what?\n");
   if(member_array("sewer",ETP->query_exits()) != -1) {
     tell_object(TP,"%^BOLD%^%^BLACK%^The stench of the sewers dissipates as the western wall slides shut.%^RESET%^");
     tell_room(ETP,"%^BOLD%^%^BLACK%^The stench of the sewers dissipates as "+TPQCN+" turns the knob and the western wall "
"slides soundlessly shut.%^RESET%^",TP);
     remove_exit("sewer");
     if(member_array("tunnel",ROOMS"sewer14"->query_exits()) != -1) {
       tell_room(ROOMS"sewer14","%^BOLD%^%^WHITE%^The wall slides "
"soundlessly closed.%^RESET%^");
       ROOMS"sewer14"->remove_exit("tunnel");
     }
   }
   else {
     tell_object(TP,"%^BOLD%^%^BLACK%^The disgusting scent of sewer nearly blinds you as the wall slides away.%^RESET%^");
     tell_room(ETP,"%^BOLD%^%^BLACK%^The disgusting scent of sewer nearly blinds you as "+TPQCN+" turns a knob and a section of the "
"wall slides to the side.%^RESET%^",TP);
     add_exit(ROOMS"sewer14","sewer");
     if(member_array("tunnel",ROOMS"sewer14"->query_exits()) == -1) {
       tell_room(ROOMS"sewer14","%^BOLD%^%^WHITE%^The wall slides aside, revealing a narrow tunnel.%^RESET%^");
       ROOMS"sewer14"->add_exit(ROOMS"tunnel1","tunnel");
     }
   }
   return 1;
}
