#include <std.h>
#include <move.h>
#include "../inherits/area_stuff.h"
#define C_WP "/d/common/obj/weapon/"
#define WPSP "/d/common/obj/special/sp_randwpn"

inherit CONTAINER;
mixed *WPNS = ({"empty", "empty", "empty", "empty", "empty"});
int numwpns;
int get() { return 0; }
void choose_my_weapons();

void create() 
{
	::create();
    	choose_my_weapons();
	set_name("a weapon rack");	
	set_id(({"rack", "weapon rack", "wooden weapon rack", 
	"mahogany rack", "mahogany weapon rack", "weapon_ao_ob_saide"}));
	set_short("%^YELLOW%^A wooden weapon rack%^RESET%^");
	set_long((:TO, "mylong":));
	set_max_internal_encumbrance(100);
     	set_value(50);
    	set_weight(100);
	numwpns = 5;
}

string mylong()
{	
	int x, flag;
	string desc;
	mixed tmp;
	desc = "%^BOLD%^%^WHITE%^This weapon rack looks ancient, as if it has "+
	"set undisturbed for countless years.  It is forged from a light "+
	"%^RESET%^%^YELLOW%^mahogany%^BOLD%^%^WHITE%^ wood and pieced "+
	"together %^BOLD%^%^YELLOW%^f%^BOLD%^%^WHITE%^l%^BOLD%^%^YELLOW%^"+
	"a%^BOLD%^%^WHITE%^w%^BOLD%^%^YELLOW%^l%^BOLD%^%^WHITE%^"+
	"e%^BOLD%^%^YELLOW%^s%^BOLD%^%^WHITE%^s%^BOLD%^%^YELLOW%^"+
	"l%^BOLD%^%^WHITE%^y.  A thick layer of dust has settled over "+
	"it.  It has slots to hold up to five different weapons.  "+
	"It currently holds : \n\n";
	
	for(x = 0;x < numwpns;x++)
	{
		tmp = WPNS[x];
		if(tmp == "empty")
		{
			tmp = "%^BOLD%^%^WHITE%^Empty.%^RESET%^";
		}
		else { flag++; }
		if(objectp(tmp)) 
		{
			flag++;
			tmp = tmp->query_short();
		}
		desc += "%^BOLD%^%^CYAN%^Slot "+(x+1)+": %^RESET%^"+tmp+"%^RESET%^\n";
	}
	if(flag) 
	{
		desc += "\n%^RESET%^You could %^BOLD%^%^WHITE%^take%^RESET%^"+
		" one of them %^BOLD%^%^WHITE%^from the rack%^RESET%^ if you wanted to... "; 
	}
	return desc;
}
	
	

void choose_my_weapons()
{
	int x, flag;
	string *wp_files;
	object tmp;
	wp_files = get_dir(C_WP+"*.c");
	wp_files -= ({"rake-garrett"}); //garrett has a rake in this directory cause he's strange :P lets not use it
	for(x = 0;x < 5;x++)
	{
		if(random(2)) continue;
		if(!random(20) && !flag)
		{
			tmp = new(WPSP);
			tmp->move(TO);
			WPNS[x] = tmp;
			flag = 1;
			continue;
		}
		tmp = new(C_WP+wp_files[random(sizeof(wp_files))]);
		WPNS[x] = tmp;
		tmp->move(TO);
		continue;
	}
	
}

void init()
{
	::init();
	add_action("get_me", "take");
}

void possess_more(object vic)
{
	int x, flag = -1;
	object tmp;
	if(!objectp(TO)) return;
	if(!objectp(vic)) return;
	if(!objectp(ETO)) return;
	for(x = 0;x < numwpns;x++)
	{
		if(WPNS[x] == "empty") continue;
		flag = x;
	}
	if(flag == -1) return;
	tmp = new(RA_MON+"phantom_weapon");
	
	tell_object(vic, "%^BOLD%^%^WHITE%^Another weapon - "+
	WPNS[flag]->query_short() + 
	" - %^BOLD%^%^CYAN%^ floats %^BOLD%^%^WHITE%^up into the air from the "+
	"rack and attacks you!%^RESET%^");

	tell_room(ETO, "%^BOLD%^%^WHITE%^Another weapon - "+
	WPNS[flag]->query_short() + " - %^BOLD%^%^CYAN%^ floats"+
	"%^BOLD%^%^WHITE%^ up into the air from the rack "+
	"and attacks "+vic->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^", vic);

	tmp->possess_this(WPNS[flag]);
	if(objectp(WPNS[flag])) WPNS[flag]->remove();
	WPNS[flag] = "empty";
	tmp->move(ETO);
	tmp->force_me("kill "+vic->query_name());
	if(!random(2)) 
	{
		call_out("possess_more", 5, TP);
	}
	return;	
}

int get_me(string str)
{
	string which;
	int x, flag = -1;
	object tmp;
	if(!str) return 0;
	if(sscanf(str, "%s from the rack", which) == 1)
	{
		for(x = 0;x < numwpns;x++)
		{
			if(WPNS[x] == "empty") continue;
			if(objectp(WPNS[x])) 
			{	
				if(!WPNS[x]->id(which)) continue;
				flag = x;
				break;
			}
		}
		if(flag == -1) 
		{
			tell_object(TP, "There is no "+which+" on the weapon rack.");
			return 1;
		}
		if(!random(75)) 
		{
			if(objectp(WPNS[flag])) 
			{
				if((int)WPNS[flag]->move(TP) == MOVE_NO_ROOM)
				{
					tell_room(ETO, TPQCN +"%^BOLD%^%^RED%^ tries to take "+
					"the "+WPNS[flag]->query_short() + " %^BOLD%^%^RED%^"+
					"from the weapon rack and drops it to the floor!%^RESET%^", TP);
					tell_object(TP, "%^BOLD%^%^RED%^You try to take the "+
					WPNS[flag]->query_short()+"%^BOLD%^%^RED%^"+
					" from the weapon rack, but its too heavy for you and it clambers "+
					"to the floor!");
					WPNS[flag]->move(ETO);
					WPNS[flag] = "empty";
					return 1;
				}
				else 
				{
					tell_object(TP, "%^BOLD%^%^RED%^You take the "+
					WPNS[flag]->query_short()+"%^BOLD%^%^RED%^ from the weapon "+
					"rack.%^RESET%^");
					tell_room(ETO, TPQCN +"%^BOLD%^%^RED%^ takes the "+
					WPNS[flag]->query_short() + " %^BOLD%^%^RED%^"+
					"from the weapon rack.%^RESET%^", TP);
					WPNS[flag] = "empty";
					return 1;
				}
			}
			tell_object(TP, "Something went wrong in the weapon_rack code - please do "+
			"<bug rack> from this room and mention this message.");
			return 1;
		}
		tmp = new(RA_MON+"phantom_weapon");
		tell_object(TP, "%^BOLD%^%^BLACK%^An %^BOLD%^%^GREEN%^insane "+
		"laughter%^BOLD%^%^BLACK%^ fills the area as the "+WPNS[flag]->query_short() +
		" %^BOLD%^%^CYAN%^floats%^BOLD%^%^BLACK%^ up into midair, on its own accord, as "+
		"you try to take it and attacks you!%^RESET%^");
		tell_room(ETO, "%^BOLD%^%^BLACK%^An %^BOLD%^%^GREEN%^insane laughter"+
		"%^BOLD%^%^BLACK%^ fills the area as the "+WPNS[flag]->query_short() + 
		"%^BOLD%^%^BLACK%^ that "+TPQCN+" %^BOLD%^%^BLACK%^ was trying "+
		"to take from the rack %^BOLD%^%^CYAN%^floats%^BOLD%^%^BLACK%^"+
		" up into midair, on its own accord, and attacks "+TPQO+
		"%^BOLD%^%^BLACK%^!%^RESET%^", TP);
		tmp->possess_this(WPNS[flag]);
		tmp->move(ETO);
		tmp->force_me("kill "+TPQN);
		if(objectp(WPNS[flag])) WPNS[flag]->remove();
		WPNS[flag] = "empty";
		if(!random(2)) 
		{
			call_out("possess_more", 5, TP);
		}
		return 1;		
	}
	return 0;
}

int is_rack_empty()
{
	mixed tmp;
	tmp = copy(WPNS);
	tmp -= ({"empty"});
	if(!sizeof(tmp)) return 1;
	return 0;
}