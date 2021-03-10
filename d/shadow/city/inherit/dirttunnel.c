//Titania 2/2/2020
//Shadow Sewers : Dirt Tunnel Inherit

#include <std.h>
#include "../defs.h"
inherit CROOM;

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
   "around you.\n%^WHITE%^");
	set_smell("default","There is a cloying scent of old roots and earth.");
	set_listen("default","Things scurry about....");
	set_items(([
	({"rocks","roots"}) : "%^ORANGE%^Stabbing outward, upward, and "+ 
	"downward, snagging at your every limb, these obstacles make "+ 
	"treading this tunnel very irritating, at best.%^WHITE%^",
	({"beam","beams"}) : "%^ORANGE%^Some are wooden, others metal, and "+ 
	"there's even the occasional bone. Whomever built this tunnel did "+
	"not do so with safety or strategy in mind.%^WHITE%^",
	]));
}
