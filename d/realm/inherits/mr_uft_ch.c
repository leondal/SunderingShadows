#include <std.h>
#include <area_stuff.h>
#include <daemons.h>

inherit RA_MR_UFT;
string wwall, hidden_room, sexit;
int searched;

void create()
{
	::create();
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
	add_action("pull_lever", "pull");
}

void reset()
{
	::reset();
	close_hidden_room();
}	

int pull_lever(string arg)
{
	if(!arg) return 0;
	if(arg != "lever") return 0;
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN+"%^BOLD%^%^YELLOW%^ sticks "+TP->QP+
	" hand into one of the cracks and seems to be feeling "+
	"around inside!%^RESET%^", TP);
	tell_object(TP, "%^BOLD%^%^YELLOW%^You stick your hand "+
	"into the crack and pull the lever!%^RESET%^");	
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
	
int crack_search(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN + "%^BOLD%^%^YELLOW%^ sticks "+TP->QP+
	" hand into one of the large cracks and feels around.%^RESET%^", TP);
	tell_object(TP, "%^BOLD%^%^YELLOW%^You stick your hand into one "+
	"of the larger cracks and feel around - finding a %^BOLD%^%^WHITE%^"+
	"lever%^BOLD%^%^YELLOW%^ hidden within.%^RESET%^");
	return 1;
}