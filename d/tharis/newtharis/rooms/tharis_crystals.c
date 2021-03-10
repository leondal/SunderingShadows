#include <std.h>
#include "../tharis.h"
inherit ROOM;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Cup Tavern Remodle - Created in February 2009 by Ari

void create(){
	::create();
		set_terrain(STONE_BUILDING);
		set_travel(PAVED_ROAD);
		set_property("no sticks", 1);
		set_property("light",2);
		set_property("indoors",1);
		set_short("%^YELLOW%^Collected Treasures%^RESET%^");
		set_long("%^YELLOW%^Collected Treasures\n%^RESET%^"+
			"%^RESET%^%^ORANGE%^Little more then a hole in the wall "+
			"with an old board tacked across the front as a door, "+
			"Collected Treasures ekes out a business by supplying "+
			"a selection of dusty, novelty %^RESET%^trinkets"+
			"%^ORANGE%^ imported from 'far and wide', housed upon "+
			"even dustier shelves. Most of the dingy, cramped "+
			"store's inventory appears to be barely a step up from "+
			"cast off %^BOLD%^%^BLACK%^junk%^RESET%^%^ORANGE%^, "+
			"and some doesn't even appear that good. The only real "+
			"thing of interest is the %^CYAN%^cabinet %^ORANGE%^in "+
			"the rear of the shop which is crammed full of dusty, "+
			"half cut %^RESET%^c%^CYAN%^r%^RESET%^ys%^MAGENTA%^t"+
			"%^RESET%^als%^ORANGE%^, many of which %^CYAN%^g"+
			"%^MAGENTA%^l%^CYAN%^ow %^ORANGE%^faintly in the dusty "+
			"air. It is over this cabinet that the proprietor "+
			"hovers, watching every prospective customer with "+
			"hungry eyes.%^RESET%^");

		set_smell("default","\nDust chokes the air.");
		set_listen("default","The shelves groan under the weight of "+
			"all this trash.");
		
		set_items(([
			({"board","door"}):"%^BOLD%^%^BLACK%^The board that "+
				"covers the entryway is little more then an old "+
				"plank tacked up.  It can be lifted and propped up "+
				"with a few wooden poles, forming a sort of awning, "+
				"or lowered and locked by use of a few chains.  "+
				"Not the most secure of doors to be sure.  Though "+
				"why anyone would want to steal the stuff in this "+
				"shop...%^RESET%^",
			({"trinkets","inventory","junk"}):"%^RESET%^%^ORANGE%^"+
				"The shelves are dusty and filth covered.  Stashed "+
				"upon them in no particular order what-so-ever are "+
				"a number of trinkets that looks like they're "+
				"mostly junk pulled out of the rubbish pile.  Here "+
				"and there you see an item that might hold some "+
				"worth, but its so filthy it's hard to be sure."+
				"%^RESET%^",
			({"shelves","dust"}):"%^RESET%^%^ORANGE%^Covered in "+
				"years of dust and grime, the shelves are filthy "+
				"and cluttered.  Goods that the shop sells are "+
				"piled haphazardly upon these wooden planks in "+
				"hope that someone might one day be so desperate "+
				"to buy something they'd brave touching the filth."+
				"%^RESET%^",
			({"cabinet","crystals"}):"%^RESET%^%^CYAN%^Toward the "+
				"back of the shop, a single cabinet appears to "+
				"have been cleaned recently, though the shop's "+
				"grime still coats the corners of the glass "+
				"case.  Oily smears mar the top and make it hard "+
				"to see what lays within, though the front of the "+
				"case is still fairly clear.  Within, a selection "+
				"of precious and semi-precious gems can be found.  "+
				"A few of them glow faintly, suggesting there "+
				"might be a power lodged within them, though the "+
				"rest of the collection look rather mundane and "+
				"uninteresting.%^RESET%^"
		]));

		set_exits(([
                        "west":ROOMS"north1",
		]));
}

void reset(){
   ::reset();
   if(!present("ralsh")) new(MOBS"ralsh")->move(TO);
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}