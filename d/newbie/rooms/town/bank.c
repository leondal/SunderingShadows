#include <std.h>
#include "../../newbie.h"
inherit BANK;

//string getBankId() {return "Newbie";}

void create()
{
	::create();
	set_property("indoors",1);
//        set_property("light",2);  banks have a base of 2 already, *Styx* 1/29/04
	set_terrain(STONE_BUILDING);
	set_travel(PAVED_ROAD);
	set_short("The Offestry Bank");
	set_long(
	"This is the Bank of Offestry. It is a rather small room, there is a desk"+
	" tucked into one corner that the teller sits at, and a stool for the bank"+
	" guard near the front door. In the back there is a large vault where all"+
	" the money is kept, but no one can get back there. This place gets a lot"+
	" of traffic, despite the fees they charge for depositing money. It's not"+
	" always safe to keep the money with you, what with thieves lurking about.\n"+
 	"A sign on the wall tells you what you can do here."
	);
	set_smell("default","The metallic scent of money hangs in the air.");
   set_listen("default","You can hear the clink of money changing hands.");
	set_items(([
	"sign" : "This is a pretty sign. You should probably read it.",
	"desk" : "This is a simple wooden desk that is piled high with paperwork.",
	"stool" : "The wooden stool is in the corner near the door so that the guard"+
	" can keep an eye on everyone who comes in.",
	"vault" : "That is where all the money is stored. There is no way to get back"+
	" there, even if it weren't for the guard, it is magically sealed with the"+
	" best spells the bank can buy.",
	]));
	set_exits(([
	"west" : MAINTOWN"sstreet1",
	"north" : MAINTOWN"estreet1",
	]));
}

void reset()
{
	::reset();
	if(!present("gleveth")) {
                find_object_or_load(MON"gleveth")->move(TO);
	}
	if(!present("bank guard")) {
		new(MON"bank_guard")->move(TO);
	}
}
