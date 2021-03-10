//Titania 2/2/2020
//Shadow Sewers : Dirt Tunnel Inherit

#include <std.h>
#include "../defs.h"
inherit INH"dirttunnel";

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_terrain(NAT_CAVE);
   set_travel(PAVED_ROAD);
   set_name("A dirt tunnel");
   set_short("%^RESET%^%^ORANGE%^A dirt tunnel%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^A dirt tunnel%^RESET%^\n%^RESET%^This is a narrow, poorly hewn "+
   "%^ORANGE%^dirt tunnel%^RESET%^. It looks as if someone came through with a shovel and "+ 
   "gouged out the passage in a hurry. %^ORANGE%^Rocks%^RESET%^ and %^ORANGE%^roots%^RESET%^ snag up your "+ 
   "steps, and the occasional bit of %^ORANGE%^dirt%^RESET%^ sprinkles down atop your "+ 
   "head. The occasional %^ORANGE%^rickety beam%^RESET%^ might be the only thing keeping the weight "+ 
   "of the earth overhead from collapsing down all "+ 
   "around you.\n\n%^RESET%^%^BLUE%^The tunnel ends abruptly at a crumbling, ancient brick wall.\n%^WHITE%^");
	set_smell("default","The filthy scent of sewerage is overpowering.");
	set_listen("default","Things scurry about....");
	set_items(([
	({"rocks","roots"}) : "%^ORANGE%^Stabbing outward, upward, and "+ 
	"downward, snagging at your every limb, these obstacles make "+ 
	"treading this tunnel very irritating, at best.%^WHITE%^",
	({"beam","beams"}) : "%^ORANGE%^Some are wooden, others metal, and "+ 
	"there's even the occasional bone. Whomever built this tunnel did "+
	"not do so with safety or strategy in mind.%^WHITE%^",
	({"wall","brick wall"}) : "%^RESET%^%^GREEN%^Layer upon layer of %^BOLD%^filth%^RESET%^%^GREEN%^ "+
	  "and %^BOLD%^slime%^RESET%^%^GREEN%^ cover the walls, the scent of it "+ 
	  "purely putrid and nauseating. The wall is in such a crumbling state of decay that some of the bricks have fallen, making a hole that you might be able to climb through.",
	"hole" : "%^RESET%^It might be possible to %^BOLD%^climb%^RESET%^ through the hole.",
	]));
	set_exits(([
      "north" : ROOMS"dirttunnel17",
   ]));
}

void init() {
  	::init();
  	add_action("climb","climb");
}

int climb(string str){
  	if(str == "hole" || str == "through hole"){
	tell_object(TP,"%^RESET%^%^ORANGE%^You manage to climb over the broken bricks and into a wretched sewer on the other side.%^RESET%^\n");
	tell_room(ETP,"%^RESET%^%^ORANGE%^"+TPQCN+" climbs over the broken bricks, disappearing to the other side of the wall.%^RESET%^",TP);
	TP->move_player(ROOMS"sewer28");
	}
}
