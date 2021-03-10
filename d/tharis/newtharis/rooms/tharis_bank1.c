#include <std.h>
#include "../tharis.h"
inherit BANK;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Bank Remodle - Created in February 2009 by Ari

void create(){
	::create();
		set_property("indoors",1);
		set_property("light",3);
		set_terrain(STONE_BUILDING);
		set_travel(PAVED_ROAD);
		
		set_name("tharis bank");
		set_short("%^YELLOW%^Tharis Bank%^RESET%^");
		
		set_long("%^YELLOW%^Tharis Bank%^RESET%^\n"+
			"%^RESET%^Dark %^ORANGE%^wood walls%^RESET%^ and "+
			"stately %^BOLD%^%^WHITE%^marble columns %^RESET%^"+
			"provide an old world feeling to this large and "+
			"spacious bank.  A comfortable %^BOLD%^%^BLACK%^"+
			"sitting area %^RESET%^has been arranged by the "+
			"entrance where banking clients can wait to be seen.  "+
			"On the other side of the room, three spacious "+
			"%^ORANGE%^booths %^RESET%^have been set up for "+
			"banking privacy.  Each one featuring a desk and "+
			"leather seating chairs.  Beyond these booths lays the "+
			"secure %^BOLD%^%^BLACK%^vault %^RESET%^into which "+
			"many a Tharis fortune has been entrusted.  Guarding "+
			"this vault are two %^BOLD%^%^WHITE%^stone golems "+
			"%^RESET%^whose watchful gaze never lingers.  Even the "+
			"clerks seem hesitant to approach the vault with such "+
			"careful guardians. A sign has been placed on the counter, "+
                  "which you could probably read.%^RESET%^");
		
		set_smell("default","\nThe deep, rich smell of wealth "+
			"permeates the air.");
		set_listen("default","You hear the clink of coins being "+
			"counted.");
			
			set_items(([
				({"walls","wood","wood walls"}):"%^RESET%^%^ORANGE%^"+
					"The walls are made from a dark, rich grained "+
					"wood that is highly polished.  Each panel is "+
					"carefully fitted, making the walls smooth and "+
					"warm.%^RESET%^",
				({"columns","marble","marble columns"}):"%^BOLD%^"+
					"%^WHITE%^Breaking up the dark wood walls, "+
					"these marble columns stand in contrast.  Their "+
					"white surfaces simple with a slight banding "+
					"of %^BLACK%^black%^WHITE%^ ribboning that "+
					"changes the otherwise stark white into a more "+
					"mellow gray tone that blends well with the "+
					"bank's settings and adds an additional sense "+
					"of wealth and steadiness to the atmosphere. "+
					"%^RESET%^",
				({"sitting area"}):"%^BOLD%^%^BLACK%^The sitting "+
					"area occupies the first part of the bank and "+
					"is arranged just to the side of the entrance. "+
					"A thick space rug stretches under several "+
					"padded leather chairs.  A few side tables "+
					"have been set beside these chairs, providing "+
					"a place to set personal items while waiting "+
					"to be helped. %^RESET%^",
				({"booths","booths","leather chairs","chairs",
					"desk"}):"%^RESET%^%^ORANGE%^Sectioning the "+
					"front of the bank from the rear, this row of "+
					"booths stretches across the middle of the "+
					"bank.  Each created from the dark wood panels "+
					"that the walls are made of, and feature a "+
					"privacy door that can be closed in the event "+
					"of large exchanges.  Comfortable chairs are "+
					"set on the customer's side, with a large "+
					"desk between them and the clerk.%^RESET%^",
			]));
			
			set_exits(([
                                "west":ROOMS"north3",
			]));
}

void reset(){
    ::reset();
    if(!present("bankgolem")){
		new(MOBS"bankgolem")->move(TO);
		new(MOBS"bankgolem")->move(TO);
	}
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}