#include <std.h>
#include <move.h>
#include "../inherits/area_stuff.h"
#define C_AR "/d/common/obj/armour/"+

inherit OBJECT;
string myarmorstr, atype;
int taken, asize;
int get() { return 0; }
void choose_my_armor();

void create() 
{
	::create();
    	choose_my_armor();
	set_long(TO->query_long() + "%^RESET%^\n\n You could "+
	"just %^BOLD%^%^WHITE%^take%^RESET%^ it - hopefully no one "+
	"would ever notice, right?%^RESET%^");
     	set_value(50);
    	set_weight(100);
}

void choose_my_armor()
{
	object myarmor;
	string *armor_files;
	armor_files = ({C_AR"banded", C_AR"breastplate",
	C_AR"fullplate", C_AR"field", C_AR"leather", 
	C_AR"padded", C_AR"scale", C_AR"sfullplate",
	C_AR"splate", C_AR"splint", C_AR"studded",
	RA_OB+"phantoms_embrace"});

	myarmorstr = armor_files[random(sizeof(armor_files))];
	myarmor = new(myarmorstr);
	if(myarmorstr == RA_OB+"phantoms_embrace")
	{
		atype = myarmor->query_atype();
		asize = myarmor->query_size();
	}

	set_short("%^BOLD%^%^RED%^"+myarmor->query_short()+"%^RESET%^");
	set_long("%^BOLD%^%^RED%^"+myarmor->query_long()+"%^RESET%^");
	set_name(myarmor->query_name());
	set_id(myarmor->query_id());
	add_id("armor");
	add_id("armor_ao_ob_saide");
	myarmor->remove();
}


void init()
{
	::init();
	add_action("get_me", "take");
}

string query_myarmorstr() { return myarmorstr; }

int get_me(string str)
{
	object myarmor, att;
	if(!str || !TO->id(str)) return 0;
	if(!objectp(TP)) return 0;
	if(!objectp(TO)) return 0;
	if(taken) return 0;
	tell_room(ETP, TPQCN+"%^BOLD%^%^WHITE%^ is trying to take "+
	TO->query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^", TP);
	myarmor = new(myarmorstr);
	if(myarmorstr == RA_OB+"phantoms_embrace")
	{
		myarmor->create_armor(atype);
		myarmor->set_size(asize);
	}
	if(!random(75))
	{
		if(!random(2)) 
		{
			if(!(int)myarmor->query_property("enchantment")) 
			{
				myarmor->set_property("enchantment", 3 + random(3));
			}		
		}
		if((int)myarmor->move(TP) == MOVE_NO_ROOM) 
		{
			tell_object(TP, "%^BOLD%^%^RED%^You cant carry the "+
			myarmor->query_short() +"%^BOLD%^%^RED%^ and it "+
			"crashes to the floor "+
			"with a loud bang!%^RESET%^");
			tell_room(ETP, TPQCN+"%^BOLD%^%^RED%^ cant carry "+
			"the "+myarmor->query_short() + "%^BOLD%^%^RED%^ "+
			"and it crashes to the floor with a "+
			"loud bang!%^RESET%^", TP);
			myarmor->move(ETP);
		}
		else
		{
			tell_object(TP, "%^BOLD%^%^RED%^You easy take the "+
			myarmor->query_short() + "%^BOLD%^%^RED%^.%^RESET%^");
			tell_room(ETP, TPQCN+"%^BOLD%^%^RED%^ takes the "+
			myarmor->query_short()+"%^BOLD%^%^RED%^.%^RESET%^", TP);
		}
		TO->remove();
		return 1;
	}

	tell_object(TP, "%^BOLD%^%^MAGENTA%^A hideous crude laughter bellows "+
	"through the room as the "+myarmor->query_short() + 
	"%^BOLD%^%^MAGENTA%^ springs forth %^BOLD%^%^WHITE%^p%^BOLD%^%^CYAN%^h"+
	"%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^n"+
	"%^BOLD%^%^WHITE%^t%^BOLD%^%^CYAN%^o"+
	"%^BOLD%^%^WHITE%^m%^BOLD%^%^MAGENTA%^ "+
	"appendages and attacks you!%^RESET%^");

	tell_room(ETP, "%^BOLD%^%^MAGENTA%^A hideous crude laughter bellows through "+
	"the room as the "+myarmor->query_short() + 
	"%^BOLD%^%^MAGENTA%^ springs forth %^BOLD%^%^WHITE%^p%^BOLD%^%^CYAN%^h"+
	"%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^n"+
	"%^BOLD%^%^WHITE%^t%^BOLD%^%^CYAN%^o"+
	"%^BOLD%^%^WHITE%^m%^BOLD%^%^MAGENTA%^ "+
	"appendages and attacks "+
	TPQCN+"%^BOLD%^%^MAGENTA%^!%^RESET%^", TP);
	
	att = new(RA_MON+"phantom_armor");
	att->possess_this(myarmor);
	att->move(ETP);
	att->force_me("kill "+TPQN);
	if(objectp(myarmor)) myarmor->remove();
	TO->remove();
	return 1;
}