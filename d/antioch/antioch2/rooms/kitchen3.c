#include <std.h>
#include "../antioch.h"
inherit VAULT;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_property("no sticks",1);
	set_short("A lovely kitchen");
	set_long(
	"You have entered a lovely kitchen. There is a window on the west wall"+
   " that over looks the the back yard. %^BOLD%^White%^RESET%^ curtains frame"+
   " it rather prettily. The sink is directly below the window. The counters"+
   " here have all been wiped clean, they are made of rather expensive"+
   " marble. A spice rack is found in the far corner of the kitchen, with the"+
   " stove across from it. A lingering smell of cookies hangs in the air. The"+
   " cabinets and drawers have been painted %^BOLD%^white%^RESET%^ with"+
   " %^YELLOW%^yellow%^RESET%^ handles, they hold the dishes and silver ware."
	);
	set_smell("default","The kitchen smells faintly of cookies.");
	set_listen("default","The kitchen is quiet.");
	set_items(([
   "floor" : "The floor has been tiled and it is very clean.",
   ({"cabinets","drawers"}) : "%^BOLD%^The cabinets and drawers have been"+
   " painted white and have %^YELLOW%^yellow%^WHITE%^ handles. They hold"+
   " the silver wear and dishes.",
   ({"curtains","white curtains"}) : "%^BOLD%^Pretty lacey white curtains"+
   " frame the window that overlooks the back yard.",
   "window" : "A little window in the center of the west wall overlooks the"+
   " backyard, though there isn't much of one, it's mostly trees.",
   ({"counters","counter","marble counter","marble counters"}) : "%^BOLD%^The"+
   " counters are made from marble. They are relatively unscratched and have"+
   " been kept very clean.",
   "spice rack" : "A wooden spice rack sits in the far right hand corner of"+
   " the room, it holds a variety of spices in it.",
   "spices" : "Spices of all sorts are kept in bottles in the spice rack.",
   "stove" : "A stone stove is against the far left hand wall. It is fairly"+
   " clean and has been used to bake cookies recently, their scent still"+
   " lingers in the air.",
	"kitchen door" : "%^BOLD%^A white door leads back into the rest of the"+
   " house.",
	]));
	set_exits(([
	"house" : ROOMS+"house9",
	]));
	set_door("kitchen door",ROOMS+"house9","house",0);
}
