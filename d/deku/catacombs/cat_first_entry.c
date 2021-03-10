#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
inherit ROOM;
void create() 
{
    	::create();
    	set_short("%^CYAN%^A strange glowing room%^RESET%^");
    	set_name("A strange glowing room");
    	set_property("light",1);
    	set_property("indoors",1);
    	set_terrain(ROCKY);
    	set_travel(PAVED_ROAD);
    	set_property("no teleport",1);
	set_property("no sticks", 1);
	set_long("%^BOLD%^%^WHITE%^The room that you find yourself in "+
	"is massive, easily spanning several dozen feet in each direction.  "+
	"It is made of an unknown %^RESET%^%^BLUE%^dark blue%^RESET%^"+
	"%^BOLD%^%^WHITE%^ substance that gives off a constant, "+
	"eerie %^CYAN%^glow%^RESET%^%^BOLD%^%^WHITE%^.  It looks "+
	"totally uninhabited, "+
	"in fact, though it looks as if it were recently built, "+
	"it doesn't show any sign at all of ever being used.  "+
	"The %^RESET%^%^BLUE%^substance%^RESET%^%^BOLD%^%^WHITE%^ "+
	"that composes it gives away to the north, south, east and "+
	"west, opening into what appears to be much older and definately "+
	"more unstable %^RESET%^%^RED%^brick%^RESET%^%^BOLD%^"+
	"%^WHITE%^ tunnels.%^RESET%^");

     	set_listen("default","%^BOLD%^%^GREEN%^Eerie howls and moans "+
	"float about down here constantly, lowering from a defeaning roar "+
	"to barely audible.%^RESET%^");
    	set_smell("default","The air is heavy with dusty and decay, making "+
	"it hard to breath.");    

    	set_items(( [
		({"substance", "dark blue substance", "walls", "floor", 
		"ceiling"}) : "%^BLUE%^"+
		"This strange dark blue substance composes the walls, floor, "+
		"and ceiling of this room.  It gives off a constant, "+
		"eerie %^CYAN%^glow%^RESET%^%^BLUE%^.  It begins "+
		"to give away to the north, south, east, and west "+
		"opening into much older and definately more unstable "+
		"%^RESET%^%^RED%^brick tunnels%^RESET%^%^BLUE%^.%^RESET%^",
		({"glow", "eerie glow"}) : "%^CYAN%^This eerie glow "+
		"is being constantly given off by the "+
		"%^RESET%^%^BLUE%^dark blue%^RESET%^%^CYAN%^ substance "+
		"that composes this room.%^RESET%^", 
		({"brick", "tunnels", "brick tunnels"}) : "%^RED%^"+
		"These older and more unstable tunnels collide with this "+
		"room from the north, south, east, and west.  From "+
		"what you can tell they are in a very obvious state of "+
		"disarray and travel through them would be unreliable.%^RESET%^",
     	] ));

	set_exits(([
	"north" : CAT_ROOMS"cat_hw_first_4",
	"south" : CAT_ROOMS"cat_hw_first_1",
	"east" : CAT_ROOMS"cat_hw_first_7",
	"west" : CAT_ROOMS"cat_hw_first_10"
	] ));

      set_search("default", "%^CYAN%^There is nothing here at all to conceal "+
	"anything.%^RESET%^");
}
