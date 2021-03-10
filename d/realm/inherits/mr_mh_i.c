#include <std.h>
#include <area_stuff.h>
#include <daemons.h>

inherit RA_MR_HALL;
string wwall, hidden_room;

void create()
{
	::create();
}

void init()
{
	::init();
	add_action("enter_mural", "enter");
}

void reset()
{
	::reset();
}	

int enter_mural(string arg)
{
	object hidroom;
	if(!arg && arg != "mural") return 0;
	if(!objectp(TP)) return 0;

	tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ walks up to a mural on the "+
	wwall + " wall and steps through it!%^RESET%^", TP);
	tell_object(TP, "%^BOLD%^%^WHITE%^You walk up a mural on the "+wwall+
	" wall and step through it!%^RESET%^");	
	hidroom = find_object_or_load(hidden_room);
	if(!objectp(hidroom)) 
	{
		tell_object(TP, "%^B_CYAN%^%^BOLD%^%^GREEN%^Could not find "+
		"the destination room - please let Saide know - do <bug here>");
		return 1;
	}
	tell_room(hidroom, "%^BOLD%^%^WHITE%^Steps out from one of the "+
	"murals!%^RESET%^", TP);
	TP->move_player(hidroom);
	return 1;
}
	
int mural_search(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN +"%^BOLD%^%^BLUE%^ searches the murals "+
	"carefully!%^RESET%^", TP);
	
	tell_object(TP, "%^BOLD%^%^BLUE%^You search over the murals "+
	"carefully and realize that one of them on the "+wwall+
	" wall is actually a portal, you could %^BOLD%^%^WHITE%^"+
	"enter%^BOLD%^%^BLUE%^ it, if you were brave enough.%^RESET%^");
	return 1;
}
