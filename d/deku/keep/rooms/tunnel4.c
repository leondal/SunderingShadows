#include <std.h>
#include "../keep.h"

inherit TUNNEL;

void create() 
{
    	::create();
	set_long(TO->query_long() + "%^YELLOW%^  The tunnel continues into "+
	"%^BOLD%^%^BLACK%^darkness %^RESET%^%^YELLOW%^to the north "+
	"and the south.%^RESET%^");
    	set_exits(([
		"south": KEEPR + "tunnel5", "north" : KEEPR + "tunnel3"
    	] ));
	
}

int water_search(object ob) 
{
	if(!objectp(TP)) return 0;	
	tell_object(TP, "%^BOLD%^%^BLUE%^You stick your hand into the %^BOLD%^%^GREEN%^"+
	"foul smelling%^RESET%^%^BOLD%^%^BLUE%^ liquid and feel around, and to your suprise "+
	"you find a hole that you could %^BOLD%^%^GREEN%^dive%^BOLD%^%^BLUE%^ into if "+
	"you were brave enough!%^RESET%^");
	return 1;
}

void init()
{
	::init();
	add_action("dive_em", "dive");
}

int dive_em(string str)
{
	if(!str)
	{
		tell_object(TP, "What do you want to dive into?");
		return 1;
	}
	if(str == "water" || str == "hole" || str == "liquid" ||
	str == "foul smelling liquid" || str == "foul water")
	{
		if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed()
		|| TP->query_tripped()) 
		{
            	TP->send_paralyzed_message("info",TP);
                	return 1;
        	}
		tell_object(TP, "You decided, against your better judgement, "+
		"to dive head first into the foul smelling liquid!");	
		if(!TP->query_invis()) 
		{
			tell_room(TO, TPQCN + " dives head first into the "+
			"%^BOLD%^%^GREEN%^foul smelling liquid%^RESET%^!", TP);
		}
		TP->move(KEEPR+"tunnel_uw1");
		TP->force_me("look");
		return 1;
	}
	else 
	{
		tell_object(TP, "What do you want to dive into?");
		return 1;
	}
}


