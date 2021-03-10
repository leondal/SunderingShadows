#include <std.h>
#include "../tharis.h"
inherit HEALER;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Healer's Remodle - Created in February 2009 by Ari

void create(){
	::create();
		set_property("indoors",1);
		set_property("light",3);
		set_terrain(STONE_BUILDING);
		set_travel(PAVED_ROAD);
		
		set_name("Healer's House");
		set_short("%^BOLD%^%^MAGENTA%^Healer's House%^RESET%^");
		
		set_long("%^BOLD%^%^MAGENTA%^Healer's House%^RESET%^\n"+
			"%^RESET%^This unassuming shop is well lit and clean.  "+
			"Small though it is, the area is designed for "+
			"efficiency.  To the left, a pair of simple, "+
			"comfortable looking %^BOLD%^%^WHITE%^cots %^RESET%^"+
			"are set out.  Between them, a foldable %^ORANGE%^"+
			"wooden curtain %^RESET%^rests, able to be expanded "+
			"for privacy or closed up to make extra room.  To "+
			"the right of the shop is the main business portion, "+
			"where a wooden, shelf-front %^ORANGE%^counter "+
			"%^RESET%^displays most of the %^CYAN%^potions "+
			"%^RESET%^and %^YELLOW%^tonics %^RESET%^for sale.  "+
			"Behind the display counter, the proprietor can "+
			"usually be found, working on a %^BOLD%^%^WHITE%^"+
			"marble countertop %^RESET%^as he prepares a selection "+
			"of potions made from the many %^ORANGE%^dried herbs "+
			"%^RESET%^hung about the rear of the shop.  Simple "+
			"though the shop is, it appears to have a volume of "+
			"high traffic, from peasants seeking attention for "+
			"minor cuts and abrasions, to sturdy adventurers with "+
			"gold filled pockets looking for %^YELLOW%^miracles"+
			"%^RESET%^.");
    set_name("hersh");
		set_items(([
			({"cots"}):"%^RESET%^%^ORANGE%^These simple cots are "+
				"made of sturdy wood beams with a thick, hardy "+
				"cotton-weave cloth stretched between.  Plain "+
				"white sheets have been draped over each and a "+
				"small throw blanket is folded up in a neat square "+
				"at the bottom of the cot.  Though not the most "+
				"comfortable for long term stay, they would do "+
				"well enough for a brief rest while waiting to be "+
				"treated.%^RESET%^",
			({"curtain","wooden curtain"}):"%^RESET%^%^ORANGE%^"+
				"Created from several slats of wood, the curtain "+
				"is designed in six panels that accordion fold "+
				"open and closed.  Meant to provide some privacy "+
				"for the injured, during busy times, it is often "+
				"folded up and set against one of the walls so "+
				"that Hersh can tend to the injured without "+
				"obstruction.%^RESET%^",
			({"counter","potions","tonics","display counter"
				"shelves"}):"%^RESET%^%^ORANGE%^The display "+
				"counter has a wooden frame but no front or back. "+
				"Instead, the interior features several shelves "+
				"upon which a number of neatly labeled potions "+
				"and tonics have been set out for sale.  On the "+
				"bottom shelf a section has been set aside for "+
				"the more simple tools of the trade such as "+
				"bandages, splints and other sundry items."+
				"%^RESET%^",
			({"marble countertop","countertop"}):"%^BOLD%^"+
				"%^WHITE%^Behind the main counter is a second, "+
				"smaller workstation with a marble counter top.  "+
				"Here, a few tools of the trade such as a mortar "+
				"and pestle, a silver cutting knife, and a small "+
				"heating flame can be seen.  Under the "+
				"workstation are several shelves that hold empty "+
				"bottles, ready to be filled with the various "+
				"potions and remedies that Hersh sells.%^RESET%^",
			({"dried herbs","herbs"}):"%^RESET%^%^ORANGE%^A "+
				"selection of dried plants hang from a wooden "+
				"board toward the back of the shop.  Each bundle "+
				"is labeled with a clearly written tag, "+
				"indicating what it is and when it was picked "+
				"along with any other warnings that might be "+
				"necessary. Most appear to be well dried, though "+
				"a few look new and still in the process of "+
				"drying out.%^RESET%^",
			({"peasants","people","adventurers"}):"%^RESET%^"+
				"%^ORANGE%^Most folks from the city, be they "+
				"peasant farmers, merchants, nobility or the "+
				"visiting adventurers, eventually find their way "+
				"to this shop seeking the aid of the healer.  "+
				"They come and go at almost every hour of the "+
				"day, leaving you to wonder when, if ever, Hersh "+
				"is able to get some sleep.%^RESET%^",
		]));
	
		set_exits(([
			"south":ROOMS"west1",
		]));
}

void reset(){
    ::reset();
    if(!present("hersh")) new(MOBS"hersh")->move(TO);

	switch(random(10)){
		case 0..1:
			tell_room(TO,"%^RESET%^%^MAGENTA%^A wealthy looking "+
				"woman with several retainers spends a few "+
				"minutes speaking to the shopkeeper about "+
				"treating wounds, before making a purchase of "+
				"everal potions.%^RESET%^");
		break;
		case 2..3:
			tell_room(TO,"%^RESET%^%^BLUE%^A young man, dressed "+
				"in the clothing of one of the city guards, rests "+
				"on one of the cots, waiting to be seen to by "+
				"Hersh. A blood soaked bandage is wrapped about "+
				"his waist.%^RESET%^");
		break;
		case 4..5:
			tell_room(TO,"%^RESET%^%^ORANGE%^Hersh tends to the "+
				"injuries of a peasant. He applies a few drops of "+
				"potion to a burn on the back of the man's hand, "+
				"then wraps it in a clean bandage.%^RESET%^");
		break;
		case 6..7:
			tell_room(TO,"%^BOLD%^%^BLACK%^Hersh cuts up a few of "+
				"the dried herbs, then crushes them down into a "+
				"fine powder using a mortar and pestle.%^RESET%^");
		break;
		case 8..9:
			tell_room(TO,"%^RESET%^%^GREEN%^Hersh dusts off the "+
				"display shelf and restocks it with fresh "+
				"bandages and new potions.%^RESET%^");
		break;
	return 1;
	}
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}