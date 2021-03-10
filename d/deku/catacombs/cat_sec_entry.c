#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
inherit ROOM;
void create() 
{
    	::create();
    	set_short("%^BOLD%^%^RED%^A cramped brick chamber%^RESET%^");
    	set_name("A cramped brick chamber");
    	set_property("light",2);
    	set_property("indoors",1);
    	set_terrain(ROCKY);
    	set_travel(PAVED_ROAD);
    	set_property("no teleport",1);
	if(!random(2)) 
	{
		set_property("no sticks", 1);
	}
		
	set_long("%^BOLD%^%^RED%^The chamber that you find yourself "+
	"in is very cramped.  The walls and floor of it are composed "+
	"entirely of %^RESET%^%^RED%^dark red bricks%^BOLD%^%^RED%^ "+
	"that have withstood the test of time quite remarkably.  "+
	"The ceiling, however, has been created from the same "+
	"strange %^RESET%^%^BLUE%^dark blue%^BOLD%^%^RED%^ "+
	"substance that you seen down here before.  It gives "+
	"off a constant, eerie %^BOLD%^%^CYAN%^glow%^BOLD%^"+
	"%^RED%^.  The floor has been, for some reason, "+
	"kept mostly free of debris.  The eastern "+
	"wall of the chamber has been lined with "+
	"numerous %^YELLOW%^torches%^BOLD%^%^RED%^, all of which are "+
	"currently burning, as if kept lit by some "+
	"unseen force.  You also notice a "+
	"%^YELLOW%^message%^BOLD%^%^RED%^ "+
	"carved just below the torches.  "+
	"Openings lead out of this room "+
	"to the north, south, and west.  You "+
	"can easily make out %^RESET%^%^RED%^"+
	"brick tunnels%^BOLD%^%^RED%^ "+
	"though each of them.%^RESET%^");

     	set_listen("default","%^BOLD%^%^GREEN%^Eerie howls and moans "+
	"float about down here constantly, lowering from a defeaning roar "+
	"to barely audible.%^RESET%^");
    	set_smell("default","The air is heavy with dusty and decay, making "+
	"it hard to breath.");    


set_items(( [
		({"substance", "dark blue substance", "ceiling"}) : "%^BLUE%^"+
		"This strange dark blue substance composes the ceiling "+
		"of this room.  It gives off a constant "+
		"eerie %^CYAN%^glow%^RESET%^%^BLUE%^.%^RESET%^",  
		({"glow", "eerie glow"}) : "%^CYAN%^This eerie glow "+
		"is being constantly given off by the "+
		"%^RESET%^%^BLUE%^dark blue%^RESET%^%^CYAN%^ substance "+
		"that composes the ceiling of this room.%^RESET%^", 
		({"brick", "tunnels", "brick tunnels"}) : "%^RED%^"+
		"These tunnels enter this room "+
		"from the north, south, and west.  They appear "+
		"old, but in good shape.%^RESET%^", 
		({"message"}) : ({"%^BOLD%^%^YELLOW%^A message "+
		"has been carved into the east wall of this "+
		"room.  It still appears legible, so you could "+
		"easily read it.%^RESET%^", "Let the light "+
		"guide your path, for without it, you are lost.",
		"common"}), 
		({"torches", "torch"}) : "%^BOLD%^%^YELLOW%^"+
		"A line of torches is extended from the "+
		"east wall of this room.  They are continually "+
		"burning, as if kept lit by some unseen force.  "+
		"You could %^RESET%^grab%^BOLD%^%^YELLOW%^ "+
		"one, if you wanted.%^RESET%^",
		({"dark red bricks", "bricks", "red bricks"}) :
		"%^RED%^These bricks look ancient, but they "+
		"have withstood the test of time quite "+
		"remarkably.%^RESET%^",
     	] ));

	set_exits(([
		"south" : CAT_ROOMS"cat_hw_sec_1",
		"west" : CAT_ROOMS"cat_hw_sec_7",
		"north" : CAT_ROOMS"cat_hw_sec_10",
	] ));

      set_search("default", "%^BOLD%^%^RED%^There is nothing here at all to conceal "+
	"anything.%^RESET%^");
}

void init()
{
	::init();
	add_action("grab_torch", "grab");	
}

int grab_torch(string str)
{
	if(!objectp(TP)) return 0;
	if(!str) return 0;
	if(str != "torch") return 0;
	tell_object(TP, "%^BOLD%^%^YELLOW%^You reach out and grab "+
	"one of the torches from the wall, letting its light "+
	"guide you.%^RESET%^");	
	tell_room(TO, TPQCN +"%^BOLD%^%^YELLOW%^ reaches out "+
	"and grabs one of the torches from the wall.%^RESET%^", TP);
	new(DEKU_MISC"catacombs_torch")->move(TP);
	return 1;
}
