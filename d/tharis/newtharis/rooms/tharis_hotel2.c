#include <std.h>
#include "../tharis.h"
inherit VAULT;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Hotel Remodle - Created in February 2009 by Ari

void create(){
	::create();
		set_property("indoors",1);
		set_property("light",3);
		set_terrain(STONE_BUILDING);
		set_travel(PAVED_ROAD);
		
		set_name("tharis inn");
		set_short("%^BOLD%^%^MAGENTA%^Tharis Inn%^RESET%^");
		
		set_long("%^BOLD%^%^MAGENTA%^Tharis Inn%^RESET%^\n"+
			"%^RESET%^%^CYAN%^This narrow hall is as tight "+
			"and constricting as the entryway, but offers the "+
			"%^WHITE%^solace %^CYAN%^of having no cats present. "+
			"To the contrary, the %^BOLD%^%^BLACK%^darkish hall "+
			"%^RESET%^%^CYAN%^appears to be vacant of any sort "+
			"of amenity, with the exception of several life-"+
			"like %^WHITE%^portraits %^CYAN%^of two %^ORANGE%^"+
			"f%^RED%^e%^BOLD%^%^BLACK%^l%^RESET%^%^ORANGE%^in"+
			"%^RED%^e%^ORANGE%^s%^CYAN%^ from the lobby. A "+
			"series of doors lead to the guest rooms, lobby and "+
			"the attached restaurant.%^RESET%^");

		set_smell("default","\nA thick, cloying perfume permeates "+
			"the air.");
		set_listen("default","The occasional bout of laughter from "+
			"restaurant cuts through the hall's silence.%^RESET%^");
		
		set_items(([
		({"portraits","cats","felines","walls"}):"%^RESET%^%^CYAN%^"+
			"The walls are covered in an off-white paint that "+
			"looks faded and rather old in this %^BOLD%^%^BLACK%^"+
			"dark hallway.  In an effort to cheer it up, the walls "+
			"have been hung with a number of %^WHITE%^representing "+
			"%^CYAN%^the two cats that call the Inn home.  Some of "+
			"the paintings are actually very well done and life-"+
			"like.  Others are rather amateur and childlike.%^RESET%^",
		({"rooms"}):"%^RESET%^%^CYAN%^There are apears to be two "+
			"rooms available.  The first features a bright %^BOLD%^"+
			"%^MAGENTA%^pink %^RESET%^%^CYAN%^door, while the other "+
			"is painted %^GREEN%^green%^RESET%^%^CYAN%^. Painted on "+
			"the first are the words %^WHITE%^Manxi's Chateau"+
			"%^CYAN%^ while the other shows the words %^WHITE%^"+
			"Maxi's Apartment%^CYAN%^.%^RESET%^",
		({"lobby"}):"%^RESET%^%^CYAN%^From here you can see the "+
			"lobby just to the north where guests to the Inn can "+
			"check in.  An old woman with white hair sits behind "+
			"a large counter, serving the patrons in between "+
			"petting the two large cats.%^RESET%^",
		({"restaurant","double doors"}):"%^RESET%^%^CYAN%^This "+
			"set of double doors opens to the %^ORANGE%^Fattened "+
			"Dwarf Tavern%^CYAN%^, a comfortable looking, "+
			"establishment with a number of booths and tables, "+
			"and the rich, flavorful smell of good food and "+
			"drink.%^RESET%^",
		]));
		
		set_exits(([
		"east":ROOMS"tharis_dwarf",
		"west":ROOMS"tharis_hotel3",
		"northwest":ROOMS"tharis_hotel4"
		]));
		
		set_door("double doors",ROOMS"tharis_dwarf","east",0);
		set_door("pink door",ROOMS"tharis_hotel3","west",0);
		set_door("green door",ROOMS"tharis_hotel4","northwest",0);
		
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}