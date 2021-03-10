#include <std.h>
#include "../keep.h"

inherit JAIL;

void create()
{
	int i;
 	::create();
	set_name("sandstone chamber");
	set_short("%^YELLOW%^Sandstone Chamber%^RESET%^");
 	set_long("%^YELLOW%^You find yourself in a chamber made of "+
	"%^RESET%^sandstone%^YELLOW%^, the walls do not look very secure.  "+
	"The floor of this chamber has broken over the "+
	"course of time, leaving only deep layers of %^RESET%^sand"+
	"%^YELLOW%^.  Corridors branch off from this chamber to the north, "+
	"west, and south, leading further into darkness.  An out of "+
	"place %^BOLD%^%^BLACK%^marble door%^YELLOW%^ has been inset "+
	"directly into the center of the eastern wall.%^RESET%^\n");

 	set_exits(([
		"east": KEEPR + "blacktonguelair6", 
		"north" : KEEPR + "jail2","west" : KEEPR + "jail4",
		"south" : KEEPR + "jail6"
    	] ));
	set_items(([
		({"sand","sandstone"}) : "This chamber is made out of "+
		"%^YELLOW%^sandstone%^RESET%^, the floor has broken over the "+
		"course of time leaving only deep layers of %^YELLOW%^sand%^RESET%^.  "+
		"This chamber does not appear to be very secure.",
		({"floor","Floor"}) : "More shifting than solid, the %^YELLOW%^"+
		"sandstone%^RESET%^ that once created the floor of this chamber "+
		"has broken into %^YELLOW%^sand%^RESET%^ over the course of time.",
		({"walls","wall"}) : "The walls of this chamber do not appear to "+
		"be very sturdy, as they are constructed entirely from "+
		"%^YELLOW%^sandstone%^RESET%^.  There is an out of place "+
		"%^BOLD%^%^BLACK%^marble door%^RESET%^ inset directly into the "+
		"center of the eastern wall.%^RESET%^",
	]));
	
	set_door("marble door",KEEPR + "blacktonguelair6","east","odd skull","lock");
	set_string("marble door", "open", "%^BOLD%^%^BLACK%^The door opens with "+
	"suprising ease.%^RESET%^");
	set_locked("marble door",1,"lock");
	set_lock_description("marble door","lock","This is a very large lock.  "+
	"The keyhole is in the shape of some type of oddly shaped "+
	"%^BOLD%^%^WHITE%^skull%^RESET%^.");
	lock_difficulty("marble door",250,"lock");
	set_door_description("marble door","%^BOLD%^%^BLACK%^This heavy "+
	"marble door is inset directly in the center of the eastern wall.  "+
	"A formation in the marble serves as an effecient handle "+
	"to help ease the process of opening it.  The keyhole for the "+
	"door is directly in the center of it, in the shape of an oddly "+
	"shaped skull.  It is impossible to tell how thick it is.%^RESET%^");
}

void reset() 
{
	int x, y, flag;
	object myob;
  	::reset();
	if(!present("massive werewolf")) 
	{
		for(x = 0;x < (random(2) + 1);x++) 
		{
			new(KEEPM + "massivewerewolf")->move(TO);
		}
	}
	if(sizeof(children(KEEPM+"telair"))) 
		{
			myob = children(KEEPM+"telair")[0];
		}
	else myob = find_object(KEEPM+"telair");
	if(!objectp(myob)) flag = 1;		
	if(objectp(myob))
	{
		if(!objectp(environment(myob))) flag = 1;		
	}
	if(random(4) < 3)
	{
		if(flag)
		{
			if(!objectp(myob)) myob = new(KEEPM+"telair");
			myob->move(TO);
		}
	}
	return;			
}
