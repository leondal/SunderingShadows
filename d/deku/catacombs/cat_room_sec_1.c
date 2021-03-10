#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"
inherit ROOM;
int door_open, summoned;
void create() 
{
    	::create();
    	set_short("%^BOLD%^%^BLACK%^A massive chamber%^RESET%^");
    	set_name("A massive chamber");
    	set_property("light",0);
    	set_property("indoors",1);
    	set_terrain(ROCKY);
    	set_travel(PAVED_ROAD);
    	set_property("no teleport",1);
	set_property("no sticks", 1);
	summoned = 0;
	door_open = 0;
	set_long((:TO, "long_desc":));

     	set_listen("default","%^BOLD%^%^GREEN%^Eerie howls and moans "+
	"float about down here constantly, lowering from a defeaning roar "+
	"to barely audible.%^RESET%^");
    	set_smell("default","The air is heavy with dusty and decay, making "+
	"it hard to breath.");    

    	set_items(( [
		({"dimension", "another dimension"}) : "%^BOLD%^%^CYAN%^"+
		"The current state of this room almost makes it appear "+
		"to be something from another dimension.%^RESET%^", 
		({"walls", "floor", "ceiling", "wall"}) : "%^BOLD%^%^WHITE%^"+
		"The walls, floor, and ceiling of this room are now "+
		"entirely smooth.  They seem to have once been "+
		"made from the same %^RESET%^%^RED%^dark red "+
		"bricks%^BOLD%^%^WHITE%^ that you've seen down "+
		"in this place.  However, something "+
		"uncertain has left them perfectly smooth and "+
		"strangely dull.  There is nothing littering "+
		"the floor, nothing attached to the ceilings, "+
		"in fact, the only thing here is a "+
		"%^BOLD%^%^CYAN%^lever%^BOLD%^%^WHITE%^ "+
		"on the east wall.%^RESET%^", 
		({"lever"}) : "%^BOLD%^%^CYAN%^This lever "+
		"is small, less than half a foot in length, and "+
		"very narrow.  It portrudes from the eastern wall.  "+
		"You could %^RESET%^pull%^BOLD%^%^CYAN%^ it, "+
		"but there is no way to know what would happen.%^RESET%^",				
     	] ));

	set_exits(([
		"east" : CAT_ROOMS"cat_hw_sec_6"
	] )); 

}

void init()
{
	::init();
	add_action("pull_lever", "pull");
}

void close_door()
{
	if(door_open == 0) return;
	tell_room(TO, "%^BOLD%^%^RED%^A massive stone slides "+
	"into place on the east wall, blocking the opening "+
	"leaving this room!%^RESET%^");
	door_open = 0;
	CAT_ROOMS"cat_hw_sec_6"->original();
}

void open_door()
{
	if(door_open == 1) return;
	tell_room(TO, "%^BOLD%^%^RED%^A massive portion of "+
	"the east wall slides away, revealing an opening "+
	"leading out of this room!%^RESET%^");
	door_open = 1;
	CAT_ROOMS"cat_hw_sec_6"->open_door();
}

int pull_lever(string str)
{
	if(!objectp(TP)) return 0;
	if(!str) return 0;
	if(str == "lever")
	{
		tell_object(TP, "%^BOLD%^%^CYAN%^You take hold of the "+
		"%^BOLD%^%^WHITE%^lever%^BOLD%^%^CYAN%^ and easily "+
		"pull it!%^RESET%^");
		tell_room(TO, TPQCN+"%^BOLD%^%^CYAN%^ takes hold of the "+
		"%^BOLD%^%^WHITE%^lever%^BOLD%^%^CYAN%^ and pulls "+
		"it!%^RESET%^", TP);
		if(summoned == 0)
		{
			close_door();
			//summon_warlock(TP, 1);
			return 1;
		}
		if(summoned == 1)
		{
			if(door_open == 1)
			{
				close_door();
				door_open = 0;
			}
			if(door_open == 0)
			{
				open_door();
				door_open = 1;
			}
			return 1;
		}
	}
}
string long_desc()
{
	string tmp;
	tmp = "%^BOLD%^%^BLACK%^This massive chamber "+
		"looks like something from another %^BOLD%^%^CYAN%^"+
		"dimension%^BOLD%^%^BLACK%^.  The walls and ceiling "+
		"are %^BOLD%^%^WHITE%^perfectly smooth%^BOLD%^%^BLACK%^ "+
		"and strangely dull.  It looks to have been "+
		"originally constructed from the same %^RESET%^%^RED%^"+
		"dark red bricks%^BOLD%^%^BLACK%^ that you've seen "+
		"down here.  You are unsure of what happened "+
		"to leave this place in its current condition, "+
		"though you fear whatever happened was very "+
		"devastating.  It almost seems like a fire "+
		"of massive proportion errupted all at "+
		"once, the heat from it so fierce that it "+
		"melted and smoothed the bricks, however "+
		"there are no ashes or remnants of "+
		"any kind littering the %^BOLD%^%^WHITE%^floor"+
		"%^BOLD%^%^BLACK%^ to truly suggest such "+
		"a cause for the current state of this "+
		"room.  There is simply nothing here, aside "+
		"from one %^BOLD%^%^CYAN%^lever%^BOLD%^%^BLACK%^ "+
		"sticking out of the eastern wall.%^RESET%^";
	if(door_open == 1)
	{
		tmp += "%^BOLD%^%^BLACK%^  An opening leads out of this "+
		"room to the east.%^RESET%^";
	}
	return tmp;
}

void reset()
{
	::reset();
	if(!random(2)) summoned = 0;
	close_door();
}
