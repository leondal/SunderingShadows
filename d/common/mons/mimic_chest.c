//basic mimic chest - functions like a normal chest except that it will 
//become a mimic and attack whenever someone tries to interact with it
//Idea is that anyone can use it and have it scale properly 
//to a specified level, with damage/health and such, then 
//when the mimic dies, anything set in
//set_my_treasure() will spill out 
//in the meantime should the person fighting it leave the room 
//or die - it will return to a normal chest - Saide
//set_my_treasure() works like 
//set_my_treasure((["currency type" : amount]))
//OR 
//set_my_treasure((["file name" : amt]))
//to set a level do setMyMimicLevel(int level, int exp_level) 
//first argument is the literal level of the mimic, 2nd is the 
//level of exp it will grant - mimics grant "normal" exp 
//for their level

#include <std.h>
#include <move.h>
#define MIMIC_MON "/d/common/mons/mimic"

inherit "/d/common/obj/misc/chest";

int isMimic;
int MyMimicLevel, MyMimicExpLevel; 
mapping MyMimicTreasure;
int AmIMimic() { return isMimic; }
int query_mimic() { return isMimic; }

void setMyMimicLevel(int x, int y) 
{
	if(x < 1) x = 1;
	if(x > 55) x = 55;
	if(y < 1) y = 1;
	if(y > 40) y = 40;
	MyMimicLevel = x;
	MyMimicExpLevel = y;
}

int query_myMimicLevel() { return MyMimicLevel; }

int query_myMimicExpLevel() { return MyMimicExpLevel; }

void set_my_treasure(mapping MyTreasure)
{
	if(!mapp(MyTreasure)) return;
	MyMimicTreasure = MyTreasure;
}

mapping query_myMimicTreasure()
{
	if(!mapp(MyMimicTreasure)) return ([]);
	return MyMimicTreasure;
}

void Victimize(object who)
{
	object MyMim;
	string msg;
	if(!objectp(TO)) return;
	msg = "%^BOLD%^%^BLACK%^With a fierce %^BOLD%^%^RED%^ROAR%^BOLD%^%^BLACK%^ the "+
		TO->query_short()+"%^BOLD%^%^BLACK%^  springs open, rows upon rows "+
		"of %^BOLD%^%^WHITE%^gleaming metal%^BOLD%^%^BLACK%^ teeth lining "+
		"what should be the inside "+
		"of a chest full of a %^BOLD%^%^CYAN%^treasure%^BOLD%^%^BLACK%^ and "+
		"a massive %^BOLD%^%^RED%^muscular%^BOLD%^%^BLACK%^ arm reaches "+
		"out from each end!%^RESET%^";
	
	tell_room(ETO, msg);
	
	MyMim = new(MIMIC_MON);
	if(!objectp(MyMim)) return;
	MyMim->become_this(TO, who);
	return;
}
	


int get() 
{
	if(isMimic) 
	{
		Victimize(TP);
		return 1;
	}
	return 1;
}

int get_from(string str)
{
	if(isMimic && TO->id(str)) 
	{
		Victimize(TP);
		return 1;
	}
	return ::get_from(str);
}

int put_into(string str)
{
	if(isMimic && TO->id(str))
	{
		Victimize(TP);
		return 1;
	}
	return ::put_into(str);
}

int open_container(string str)
{
	if(isMimic && TO->id(str))
	{
		Victimize(TP);
		return 1;
	}
	return ::open_container(str);
}

int close_container(string str)
{
	if(isMimic && TO->id(str)) 
	{
		Victimize(TP);
		return 1;
	}
	return ::close_container(str);
}

int unlock_container(string str)
{
	if(isMimic && TO->id(str)) 
	{
		Victimize(TP);
		return 1;
	}
	return ::unlock_container(str);
}

int lock_container(string str)
{
	if(isMimic && TO->id(str))
	{
		Victimize(TP);
		return 1;
	}
	return ::lock_container(str);
}

int PickLock(string str)
{
	if(isMimic && TO->id(str))
	{
		Victimize(TP);
		return 1;
	}
	return ::PickLock(str);
}

void create() 
{
	::create();
	isMimic = 1;
}

void clear_mimic()
{
	isMimic = 0;
}