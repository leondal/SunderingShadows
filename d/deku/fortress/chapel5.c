#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit ROOM;

int searched;

void create() {
 ::create();
 set_property("light",1);
 set_property("indoors",1);
	set_property("no sticks",1);
 set_terrain(STONE_BUILDING);
 set_travel(PAVED_ROAD);
	set_name("small room");
 set_short("%^BOLD%^%^BLACK%^Small room%^RESET%^");
 set_long("%^RED%^This small square room is made from a %^BOLD%^%^BLACK%^black stone%^RESET%^"+
		"%^RED%^ that has been kept in remarkably good condition, so much so that it actually "+
		"seems to %^RESET%^sparkle%^RED%^.  The eastern wall of this room is littered with %^BLUE%^"+
		"windows%^RED%^ that have been boarded up to prevent anyone from seeing into this room "+
		"from the outside.  Beneath the windows are three %^BLUE%^beds%^RED%^ that have been "+
		"lined up against the wall.  The beds are each neatly made and covered with %^BOLD%^"+
		"%^BLACK%^thick black covers%^RESET%^%^RED%^.  The floor of this room is made from the "+
		"same %^BOLD%^%^BLACK%^black stone%^RESET%^%^RED%^ and is completely free of %^BLUE%^"+
		"debris%^RED%^.  There is an %^BLUE%^open doorway%^RED%^ in the western wall of this room "+
		"that has been covered with a %^BOLD%^%^BLACK%^thick black curtain%^RESET%^%^RED%^."+
		"%^RESET%^\n");
 
	set_search("default","%^BOLD%^%^BLACK%^There is nothing here that could conceal anything, "+
		"except for maybe the beds?%^RESET%^");
	set_search("beds",(:TO,"bed_search":));
 set_search("beds",(:TO,"bed_search":));
	set_search("covers",(:TO,"bed_search":));
	set_search("cover",(:TO,"bed_search":));
 set_exits(([
  "west" : GY_ROOMS +"chapel4",
 ] ));
 
	set_smell("default","The air here reeks with a strong odor of death and decay.");
	set_listen("default","A loud chanting seems to echo from the very walls.");

 set_items(([
		({"stone","black stone"}) : "%^BOLD%^%^BLACK%^The room is made entirely out of this "+
		"strange black stone.  It seems to continually sparkle, even in pitch black.%^RESET%^",
			({"doorway","open doorway"}) : "%^BLUE%^This doorway is set into the western wall of the "+
			"room.  It is covered with a %^BOLD%^%^BLACK%^thick black curtain%^RESET%^%^BLUE%^"+
			".%^RESET%^",
		"sparkle" : "The %^BOLD%^%^BLACK%^black stone%^RESET%^ that constructs this room seems "+
		"to continually sparkle and glisten, even in pitch black.",			
		({"windows","boarded windows"}) : "%^MAGENTA%^These windows litter the eastern "+
		"wall of the room.  All of them have been boarded up to prevent anyone from seeing "+
		"into this room from the outside.%^RESET%^",
			({"floor"}) : "%^BOLD%^%^BLACK%^The floor here is made from a black stone, it looks like "+
		"it is constantly cleaned and suprisingly it has been kept in remarkably good "+
		"condition.%^RESET%^",
		({"ceiling"}) : "%^BOLD%^%^BLACK%^The ceiling here is made from a black stone that has "+
		"been kept in remarkably good condition.%^RESET%^",
		({"curtain","thick curtain","black curtain","thick black curtain"}) : "%^BOLD%^%^BLACK%^"+
		"This curtain is made from a thick black cloth.  It is covering the %^BLUE%^open doorway"+
		"%^BOLD%^%^BLACK%^ in the western wall of this room.%^RESET%^",
		({"beds","bed"}) : "%^BLUE%^These three beds have been lined up against the "+
		"eastern wall of this room.  They are neatly made with %^BOLD%^%^BLACK%^thick black "+
		"covers%^RESET%^%^BLUE%^.%^RESET%^",
		({"covers","thick covers","black covers","thick black covers"}) : "%^BOLD%^%^BLACK%^These "+
  "covers are made from a quilted black cloth.  Each of the three %^BLUE%^beds%^BOLD%^"+
		"%^BLACK%^ lining the eastern wall has been covered by a set of them.%^RESET%^",
		({"debris"}) : "%^BLUE%^The floor of this room is completely void of any debris.%^RESET%^",
		] ));
  
  set_pre_exit_functions(({"west"}),({"GoThroughDoor"}));
		set_post_exit_functions(({"west"}),({"covered"}));
}

int bed_search() {
	if(!TP->query_invis()) {
		tell_room(TO,TPQCN+"%^BOLD%^%^BLACK%^ searches carefully through each of the beds."+
			"%^RESET%^",TP);
	}

 if(searched == 1) {
		tell_object(TP,"%^BOLD%^%^BLACK%^You carefully search each of the beds, but find nothing."+
			"%^RESET%^");
		return 1;
	}
	 tell_object(TP,"%^BOLD%^%^BLACK%^You carefully search each of the beds and find a "+
			"small metal cylinder.%^RESET%^");
  new(GY_OBJS+"ancientchapelkey")->move(TO);
		searched = 1;
		return 1;
}

void covered() {
	tell_room(TO,"%^BOLD%^%^BLACK%^The curtain falls back into place over the %^BLUE%^open "+
		"doorway%^BOLD%^%^BLACK%^.");
}

int GoThroughDoor(){
	tell_object(TP,"%^BOLD%^%^BLACK%^You push the curtain out of the way and step through the "+
		"%^BLUE%^open doorway%^BOLD%^%^BLACK%^.%^RESET%^");
	tell_room(TO,TPQCN+"%^BOLD%^%^BLACK%^ pushes the curtain out of the way and steps through "+
		"the %^BLUE%^open doorway%^BOLD%^%^BLACK%^.%^RESET%^",TP);
 return 1;
}

void reset() {
 ::reset();

 if(!present("priest")) {
  if(random(4) >= 2) {
   new("/d/deku/monster/priest")->move(TO);
  }
 }

 if(!present("antipaladin")) {
  if(random(4) >= 2) {
   new("/d/deku/monster/antipaladin")->move(TO);
  }
 }
 if(random(5) == 3) {
		searched = 0;
	}
}