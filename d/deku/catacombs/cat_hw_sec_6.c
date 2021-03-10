#include <std.h>
#include "/d/deku/inherits/forest.h"

inherit CAT_HW_S;
string *pegs;
int door_open, peg_froze;
void assign_peg_states();
void original();
string original_long;
void create() 
{
	::create();
	original_long = TO->query_long();
	set_exits(([
		"east" : CAT_ROOMS"cat_hw_sec_5",
		//"west" : CAT_ROOMS"cat_hw_sec_6"
	] )); 
	remove_item("brick");
	original();
	fix_exits();
	remove_item("brick");
	add_item("brick", "%^RED%^This particular brick "+
	"is sticking out slightly from the western wall.  "+
	"You could try to %^BOLD%^%^WHITE%^push%^RESET%^%^RED%^ "+
	"it back in, if you wanted to.%^RESET%^");
}

void peg_freeze()
{
	if(door_open == 1)
	{
			tell_room(TO, "%^BOLD%^%^RED%Suddenly the "+
			"missing section of the western wall "+
			"slides back into view!%^RESET%^");
			original();	
	}
	peg_froze = 1;
}

int is_door_open()
{
	return door_open;
}

void original()
{
	string roomn;
	peg_froze = 0;
	door_open = 0;
	pegs = ({});
	assign_peg_states();	
	add_item(({"peg", "pegs"}), (:TO, "pegs_desc":));
	set_long(original_long + "  %^BOLD%^%^YELLOW%^You notice "+
	"that there are some %^BOLD%^%^WHITE%^pegs%^BOLD%^%^YELLOW%^ "+
	"sticking out from the western wall and to the right of "+
	"them a %^RESET%^%^RED%^brick%^BOLD%^%^YELLOW%^ jaunts out "+
	"slightly.  %^BOLD%^%^YELLOW%^"+
	"The tunnel continues eastward here.%^RESET%^");
	roomn = CAT_ROOMS"cat_sec_room_1";
	roomn->close_door();
	remove_exit("west");
}

void open_door()
{
	string roomn;
	set_long(original_long + "  %^BOLD%^%^YELLOW%^A section of "+
	"the western wall has disappeared, revealing "+
	"an opening into a large room and to the right of "+
	"it a %^RESET%^%^RED%^brick%^BOLD%^%^YELLOW%^ jaunts "+
	"out slightly.  %^BOLD%^%^YELLOW%^"+
	"The tunnel continues eastward here.%^RESET%^");
	add_exit(CAT_ROOMS"cat_sec_room_1", "west");
	door_open = 1;
	roomn = CAT_ROOMS"cat_sec_room_1";
	roomn->open_door();
	remove_item(({"peg", "pegs"}));
}

void pegs_desc()
{
	int x;
	string tmp;
	tmp = "%^BOLD%^%^RED%^There are twelve pegs set directly "+
	"into the center of the western wall here.  The three along "+
	"the top as well as the three along the bottom seem "+
	"immobile and stuck in place.  However, closer inspection "+
	"reveals that six of them, the ones running "+
	"vertically on the wall are not.  You could %^BOLD%^%^GREEN%^"+
	"twist%^BOLD%^%^RED%^ them, if you were so inclined.  "+
	"Standing back a bit you realize that as a whole they form "+
	"the outline of something.%^RESET%^\n\n";
	tmp += "%^BOLD%^%^GREEN%^\n __ __ __\n";
	x = 0;
	while(x <= 4)
	{
		tmp += "%^BOLD%^%^GREEN%^ "+pegs[x];
		if(pegs[x] == "__")
		{
			if(pegs[x+1] == "|")
			{
				if(x == 2)
				{
					tmp += "  %^BOLD%^%^RED%^o%^RESET%^  "+
					"%^RESET%^%^BOLD%^%^GREEN%^"+pegs[x+1]+"\n";
				}
				else
				{
					tmp += "     "+"%^RESET%^%^BOLD%^"+
					"%^GREEN%^"+pegs[x+1]+"\n";
				}
			}
			if(pegs[x+1] == "__")
			{
				if(x == 2)
				{
					tmp += "  %^BOLD%^%^RED%^o%^RESET%^ "+
					"%^RESET%^%^BOLD%^%^GREEN%^"+pegs[x+1]+"\n";
				}
				else 
				{
					tmp += "    "+"%^RESET%^%^BOLD%^%^GREEN%^"+
					pegs[x+1]+"\n";
				}
			}
			x+=2;
			continue;
		}
		if(pegs[x] == "|")
		{
			if(pegs[x+1] == "|")
			{
				if(x == 2)
				{
					tmp += "   %^BOLD%^%^RED%^o%^RESET%^  "+
					"%^BOLD%^%^GREEN%^"+pegs[x+1]+"\n";
				}
				else
				{
					tmp += "      "+pegs[x+1]+"\n";
				}
			}
			if(pegs[x+1] == "__")
			{
				if(x == 2)
				{
					tmp += "   %^BOLD%^%^RED%^o%^RESET%^ "+
					"%^BOLD%^%^GREEN%^"+pegs[x+1]+"\n";
				}
				else
				{
					tmp += "     "+pegs[x+1]+"\n";
				}
			}
			x+=2;
			continue;
		}    
	}
	tmp += "%^BOLD%^%^GREEN%^ -- -- --\n%^RESET%^";
	return tmp;
}

void assign_peg_states()
{
	int x = 6;
	pegs = ({});
	if(objectp(TO)) 
	{
		tell_room(TO, "%^BOLD%^%^WHITE%^The vertical pegs "+
		"on the western wall begin quickly turning "+
		"and they eventually settle into place after a few moments "+
		"of erratic spinning!%^RESET%^");
	}
	while(x >= 1)
	{
		switch(random(2)) 
		{
			case 0:
				pegs += ({"|"});
				break;
			case 1: 
				pegs += ({"__"});
				break;
		}
		x--;
	}
}

void init()
{
	::init();
	add_action("twist_peg", "twist");
	add_action("push_brick", "push");
}

void change_peg(int wp)
{
	if(objectp(TP)) 
	{
		if(peg_froze == 0)
		{
			tell_object(TP, "%^BOLD%^%^WHITE%^You reach out and easily "+
			"%^BOLD%^%^GREEN%^twist%^BOLD%^%^WHITE%^ one of the "+
			"vertical pegs!%^RESET%^");
			if(!TP->query_invis()) 
			{
				if(objectp(TO)) 
				{
					tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ reaches out "+
					"easily %^BOLD%^%^GREEN%^twists%^BOLD%^%^WHITE%^ "+
					"one of the vertical pegs!%^RESET%^");
				}
			}
		}
		if(peg_froze == 1)
		{
			tell_object(TP, "%^BOLD%^%^WHITE%^You reach out and easily "+
			"%^BOLD%^%^GREEN%^twist%^BOLD%^%^WHITE%^ one of the "+
			"vertical pegs... it and suddenly goes back to its "+
			"original position!%^RESET%^");
			if(!TP->query_invis()) 
			{
				if(objectp(TO)) 
				{
					tell_room(TO, TPQCN+"%^BOLD%^%^WHITE%^ reaches out "+
					"easily %^BOLD%^%^GREEN%^twists%^BOLD%^%^WHITE%^ "+
					"one of the vertical pegs... but it goes "+
					"back it its original position!%^RESET%^");
				}
			}
			return;
		}
	}
	wp--;
	if(pegs[wp] == "|")
	{
		pegs[wp] = "__";
		return;
	}
	if(pegs[wp] == "__")
	{
		pegs[wp] = "|";
		return;
	}
}

int push_brick(string str)
{
	if(!objectp(TP)) return 0;
	if(!str) return 0;
	if(str == "brick")
	{
		if(door_open == 1)
		{
			tell_object(TP, "%^BOLD%^%^RED%^You give the "+	
			"odd brick a push and suddenly the "+
			"missing section of the western wall "+
			"slides back into view!%^RESET%^");

			tell_room(TO, "%^BOLD%^%^RED%^As "+TPQCN+
			"%^BOLD%^%^RED%^ gives the odd brick a "+
			"push the missing section of the western "+
			"wall slides back into view!%^RESET%^", TP);
			original();
			return 1;
		}
		if(door_open == 0)
		{
			if(pegs[0] == "|" && pegs[1] == "|" &&
			pegs[2] == "|" && pegs[3] == "|" &&
			pegs[4] == "|" && pegs[5] == "|")
			{
				tell_object(TP, "%^BOLD%^%^RED%^You give "+
				"the odd brick a push and suddenly "+
				"a section of the western wall "+
				"slides aside!%^RESET%^");
				tell_room(TO, "%^BOLD%^%^RED%^As "+TPQCN+
				"%^BOLD%^%^RED%^ gives the odd brick a "+
				"push a section of the western wall "+
				"slides aside!%^RESET%^", TP);
				open_door();
				return 1;
			}
			else
			{
				tell_object(TP, "%^BOLD%^%^RED%^You give "+
				"the odd brick a push.%^RESET%^");
				tell_room(TO, TPQCN+"%^BOLD%^%^RED%^ gives "+
				"the odd brick a push.%^RESET%^", TP);
				assign_peg_states();
				return 1;
			}
		}
	}
	return 0;
}

int twist_peg(string str)
{
	if(!objectp(TP)) return 0;
	if(door_open) return 0;	
	if(!str) 
	{
		tell_object(TP, "What do you want to twist?");
		return 1;
	}
	if(str == "peg")
	{
		tell_object(TP, "Which peg do you want to twist?  There are six "+
		"that you can twist.");
		return 1;
	}
	switch(str)
	{
		case "peg 1":
			change_peg(1);
			return 1;
		case "peg 2":
			change_peg(2);
			return 1;
		case "peg 3":
			change_peg(3);
			return 1;
		case "peg 4":
			change_peg(4);
			return 1;
		case "peg 5":
			change_peg(5);
			return 1;
		case "peg 6":
			change_peg(6);
			return 1;
		default:
			return 0;
	}	
	return 0;
}

void reset()
{
	::reset();
	if(door_open == 1)
	{	
		original();
	}
}
