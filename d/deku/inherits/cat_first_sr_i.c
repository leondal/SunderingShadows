#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/forest.h"

inherit ROOM;
int no_gold;
void create() 
{
    	::create();
    	set_short("%^BOLD%^%^RED%^A massive brick chamber%^RESET%^");
    	set_name("A massive brick chamber");
    	set_property("light",0);
    	set_property("indoors",1);
    	set_terrain(ROCKY);
    	set_travel(PAVED_ROAD);
    	set_property("no teleport",1);
	set_property("no sticks", 1);
	set_long((:TO, "long_desc":));

     	set_listen("default","%^BOLD%^%^GREEN%^Eerie howls and moans "+
	"float about down here constantly, lowering from a defeaning roar "+
	"to barely audible.%^RESET%^");

    	set_smell("default","The air is heavy with dust and decay, making "+
	"it hard to breath.");    

    	set_items(( [
		({"bricks", "dark red bricks", "red bricks"}) : "%^RED%^"+
		"These bricks look ancient, however, they have gracefully "+
		"withstood the test of time.%^RESET%^", 
		({"dust", "caked dust"}) : "%^BOLD%^%^BLACK%^Thick "+
		"dust has caked everything here.  Suggesting that this "+
		"chamber has stood empty for some time.%^RESET%^",
		({"gold", "pile of gold"}) : "%^BOLD%^%^YELLOW%^This "+
		"massive pile of gold just sits there... you could "+
		"easily %^BOLD%^%^CYAN%^grab%^BOLD%^%^YELLOW%^ "+
		"it.%^RESET%^",
     	] ));

      set_search("default", "There is only dust here, it could hardly "+
	"conceal anything.");
}

void init()
{
	::init();
	if(no_gold == 0) 
	{
		add_action("grab_gold", "grab");
	}
}

void remove_gold()
{
	no_gold = 1;
	TO->remove_item(({"gold", "pile of gold"}));
}
void add_gold()
{
	if(no_gold == 1)
	{
		no_gold = 0;
		TO->add_item(({"gold", "pile of gold"}), "%^BOLD%^%^YELLOW%^This "+
		"massive pile of gold just sits there... you could "+
		"easily %^BOLD%^%^CYAN%^grab%^BOLD%^%^YELLOW%^ "+
		"it.%^RESET%^");
	}
}

int grab_gold(string str)
{
	if(!objectp(TP)) return 0;
	if(!str) return 0;
	if(str == "gold" || str == "the gold")
	{
		if(no_gold == 1) return 0;
		tell_room(TO, TPQCN + "%^BOLD%^%^RED%^ rushes up to the pile of "+
		"gold and %^BOLD%^%^CYAN%^grabs%^BOLD%^%^RED%^ it!%^RESET%^", TP);
		tell_object(TP, "%^BOLD%^%^RED%^You rush up to the pile of "+
		"gold and %^BOLD%^%^CYAN%^grab%^BOLD%^%^RED%^ it!%^RESET%^");
		if(random(20))
		{
			tell_object(TP, "%^BOLD%^%^YELLOW%^A hideous laugher "+
			"cackles in your head as the coins turn to "+
			"%^BOLD%^%^BLACK%^dust%^BOLD%^%^YELLOW%^ "+
			"and blow around the room!%^RESET%^");

			tell_room(TO, "%^BOLD%^%^YELLOW%^You gaze in "+
			"shock as the coins that "+TPQCN+"%^BOLD%^%^YELLOW%^ "+
			"just picked up turn to %^BOLD%^%^BLACK%^"+
			"dust%^BOLD%^%^YELLOW%^ and blow around the room!%^RESET%^", TP);
			remove_gold();
			return 1;
		}
		tell_object(TP, "%^BOLD%^%^YELLOW%^You examine the coins "+
		"and finding nothing wrong with them, save a thick coating of "+
		"dust, you add them to your coin purse.%^RESET%^");
		TP->add_money("gold", 5000 + random(2500));
		remove_gold();
		return 1;
	}
	return 0;
}

void long_desc() 
{
	string tmp;
	tmp = "%^BOLD%^%^RED%^The massive chamber that you find yourself "+
	"in looks at least several centuries old.  It is composed entirely of "+
	"%^RESET%^%^RED%^dark red bricks%^BOLD%^%^RED%^ that have somehow, "+
	"miraculously, withstood the test of time.  It looks as if it has "+
	"stood empty for many of those centuries.  The walls, floor, and "+
	"ceiling of this chamber look to still be quite sturdy.  "+
	"You are unsure of what has kept this room in such a state "+
	"while the hallways down here are almost crumbling, as it "+
	"lacks any signs of life.  A thick layer of "+
	"%^BOLD%^%^BLACK%^dust%^BOLD%^%^RED%^ cakes everything here.";
	if(no_gold == 0)
	{
		tmp+= "%^BOLD%^%^RED%^  You notice that a massive pile of "+
		"%^BOLD%^%^YELLOW%^gold%^RESET%^%^BOLD%^%^RED%^ rests "+
		"in the center of the chamber, obviously undisturbed for some "+
		"time, as dust has also settled over it.%^RESET%^";

	}
	return tmp;	
}

