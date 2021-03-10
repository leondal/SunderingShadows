#include <std.h>
#include <area_stuff.h>
#include <daemons.h>

inherit RA_MR_HALL;
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
	add_action("push_brick", "push");
}



void reset()
{
	::reset();
	close_hidden_room();
}	

int push_brick(string arg)
{
	if(!arg) return 0;
	if(arg != "brick") return 0;
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ pushes one of the bricks "+
	"into the wall, but it comes right "+
	"back out!%^RESET%^", TP);
	tell_object(TP, "%^BOLD%^%^RED%^You push the brick that was sticking "+
	"out back into the wall, but it slowly slides right back out!"+
	"%^RESET%^");
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
	
int brick_search(string ob)
{
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	tell_room(TO, TPQCN +"%^BOLD%^%^RED%^ searches carefully over "+
	"the bricks.%^RESET%^", TP);
	tell_object(TP, "%^BOLD%^%^RED%^You carefully search the bricks "+
	"here and find one that seems like it sticks out a little "+
	"too far, you could probably %^BOLD%^%^WHITE%^push"+
	"%^BOLD%^%^RED%^ it, if you wanted to.%^RESET%^");
	return 1;
}
