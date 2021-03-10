#include <std.h>
#include <area_stuff.h>
#include <daemons.h>

inherit RA_MR_UFT;
int searched;
string wwall, hidden_room, sexit;
void create() 
{
 	::create();
	searched = 0;
}

void open_hidden_room()
{
	object hidroom;
	if(searched == 0) 
	{
		searched = 1;
		tell_room(TO, "%^BOLD%^%^RED%^A section of the "+wwall+
		" wall slides to the side, revealing "+
		"an opening!%^RESET%^");
		TO->add_exit(hidden_room, sexit);
		hidroom = find_object_or_load(hidden_room);
		if(!objectp(hidroom)) return;
		hidroom->open_hidden_room();
		return;
	}
}

void close_hidden_room()
{
	object hidroom;
	if(searched == 1)
	{
		tell_room(TO, "%^BOLD%^%^RED%^A section of the "+wwall+
		" wall slides back into place!%^RESET%^");
		searched = 0;
		TO->remove_exit(sexit);
		hidroom = find_object_or_load(hidden_room);
		if(!objectp(hidroom)) return;
		hidroom->close_hidden_room();
		return;
	}
}


void init()
{
	::init();
	add_action("step_brick", "press");
}



void reset()
{
	::reset();
	close_hidden_room();
}	

int step_brick(string arg)
{
	if(!arg) return 0;
	if(arg != "brick") return 0;
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN+"%^BOLD%^%^%^RED%^ steps on a brick that's sticking up "+
	"from the floor and presses it down.  It slowly rises back up when "+
	TP->QS + " moves "+TP->QS+" weight from it!", TP);
	tell_object(TP, "%^BOLD%^%^RED%^You step on the brick and press it "+
	"back into the floor but as soon as you remove your weight from it "+
	"it rises slowly back up!%^RESET%^");
	if(searched == 0) 
	{
		open_hidden_room();
		return 1;
	}
	if(searched == 1)
	{
		close_hidden_room();
		return 1;
	}
	return 1;
}
	
int floor_search(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN + " %^RED%^searches carefully along the "+
	"floor.%^RESET%^", TP);

	tell_object(TP, "%^RED%^You search carefully along the floor "+
	"and find a find a lone brick that is sticking up slightly, "+
	"you could %^BOLD%^%^CYAN%^press%^RESET%^%^RED%^ "+
	"it back into place, if you wanted.%^RESET%^");
	return 1;
}
