#include <std.h>
#include "../tharis.h"
inherit ROOM;

int flag;
object room;

void create(){
	::create();
      set_terrain(BUILT_TUNNEL);
      set_travel(SLICK_FLOOR);
      set_property("no sticks", 1);
	set_property("light",1);
	set_property("indoors",1);
	set_property("no teleport",1);
	set_short("A large cavern far below Tharis");
	set("long","%^BOLD%^%^YELLOW%^A huge cavern far below Tharis%^RESET%^\n"
"%^BLUE%^This cavern is huge, so much so that in the dim light you can barely see either end. "
"A very wet environment, this cave has almost two feet of %^ORANGE%^mud %^BLUE%^covering the "
"floor. You can see items protruding from the mud. You realize that this room has collected "
"the goods tossed away by the people of Tharis for the ages that the city has stood here. The "
"high roof has what looks like a trap door in it, possibly where things would get dumped from "
"the %^GREEN%^sewers %^BLUE%^above.\n%^RESET%^");
	set_smell("default","The odors of decomposition gag you.");
	set_listen("default","You hear the squoosh squoosh around you.");

	set_exits(([
            "tunnel":SEWERS"sewer1"
	]));
	set_items(([
		"mud":"This mud is about two feet deep. You wonder what the years have hidden in the mud.",
		"trap door":"Simply a trap door from which drops things from above down."
	]));
	set_invis_exits(({"tunnel"}));
	set_pre_exit_functions(({"tunnel"}),({"no_tunnel"}));
	flag = 0;
	set_search("default",(:TO,"exits":));
	set_search("mud",(:TO,"muds":));
}

int no_tunnel(){
	if(!flag) write("You cannot go that way.");
	return flag;
}

void exits(){
	if(flag) return;
	write("%^BOLD%^You manage to find a tunnel leading upward!");
	tell_room(TO,"%^BOLD%^"+TPQCN+" finds a tunnel leading upwards!",TP);
	remove_invis_exit("tunnel");
	flag = 1;
	return;
}

void reset(){
 	::reset();
 	if(!present("behir")) new(MOBS"behir")->move(TO);
 	flag = 0;
 	set_invis_exits(({"tunnel"}));
}
 	
void muds(){
	object *inven;
	int i;
      if(!room) room = new(STORAGE"mud");
 	
 	tell_room(TO,"%^BOLD%^"+TPQCN+" starts slogging through the mud looking for things!",TP);
 	write("%^BOLD%^You start slogging through the mud searching for things!");
 	inven = all_inventory(room);
 	i = sizeof(inven);
 	
 	if(i){
 		i = random(i);
 		write("%^BOLD%^You manage to find a "+inven[i]->query_name()+"!");
 		tell_room(TO,"%^BOLD%^"+TPQCN+" manages to find something!",TP);
 		inven[i]->move(TO);
 		return;
 	}
 	write("You find nothing odd");
 	return;
 }
