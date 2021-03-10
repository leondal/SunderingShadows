#include <std.h>
#include "../tharis.h"
inherit ROOM;

// Based on old Tharis City Buildings, Mobs, etc.
// Tharis City Remodle - Created by LoKi in 2009.  
// Tharis Clothier Remodle - Created in February 2009 by Ari

void create(){
	::create();
		set_terrain(STONE_BUILDING);
		set_travel(PAVED_ROAD);
		set_property("no sticks", 1);
		set_property("light",2);
		set_property("indoors",1);
		
		set_name("clothier of tharis");
        set_short("%^YELLOW%^Clothier of Tharis%^RESET%^");
        set_long("%^YELLOW%^Clothier of Tharis%^RESET%^\n"+
			"%^RESET%^Bolts of fine %^ORANGE%^fabric%^RESET%^, "+
			"cases of expensive %^YELLOW%^accents %^RESET%^and "+
			"shelves of %^MAGENTA%^trim %^RESET%^occupy a large "+
			"potion of this shop.  Between, cloth mannequins have "+
			"been arranged in life like positions to provide "+
			"displays for the one-of-a-kind pieces that are sold "+
			"here.  Two %^ORANGE%^booths %^RESET%^have been set "+
			"up toward the back of the shop providing customers "+
			"with a place to try their %^ORANGE%^garments "+
			"%^RESET%^on and have %^MAGENTA%^fittings %^RESET%^"+
			"made.  Another door leads into the back of the shop "+
			"where most of the sewing is done.  Rich %^ORANGE%^"+
			"woods %^RESET%^accent the walls, each trimmed with "+
			"heavy %^YELLOW%^tapestries %^RESET%^that gather "+
			"sound and make the shop nearly silent, even when "+
			"busy.%^RESET%^");
		
		set_smell("default","\nThe rich scent of fine cloth "+
			"fills the air.");
		set_listen("default","It is very quiet in the shop.  "+
			"All the sounds seem muffled.");
		
        set_items(([
			({"fabric","accents","trim"}):"%^BOLD%^%^WHITE%^"+
				"Every imaginable type of cloth can be seen "+
				"neatly rolled into bolts and stacked upon the "+
				"many shelves of this shop.  Everything from "+
				"silk to cotton to tweed and wool are here.  "+
				"Interspersed between the shelves of cloth are "+
				"cabinets filled with trim and fixtures.  Some "+
				"are simple buttons and laces, others are more "+
				"elaborate, depending on what is called for."+
				"%^RESET%^",
			({"mannequins","displays"}):"%^BOLD%^%^WHITE%^Set "+
				"throughout the shop are several cloth and wood "+
				"mannequins arranged into somewhat natural "+
				"poses.  These are each dressed in some of the "+
				"more stunning garments that the shop makes.  "+
				"Racks are tucked off toward the side of the "+
				"shop, offering more common attire for everyday "+
				"use.%^RESET%^",
			({"booths"}):"%^BOLD%^%^WHITE%^A booth is set off "+
				"to either of the back corners.  Triangle in "+
				"shape, a swinging door allows access to each "+
				"where a mirror can be found, along with a hook "+
				"and a small stool.  These dressing rooms are "+
				"meant for trying on the various garments sold "+
				"here.%^RESET%^",
			({"woods","walls","tapestries"}):"%^GREEN%^Hanging "+
				"over the dark wood tones of the wall are several "+
				"thick tapestries.  The majority appear to be "+
				"scenes from the nearby Tharis Forest.  Unicorns, "+
				"Korrids and the occasional majestic tree seem to "+
				"be the focus of the artwork, though a few show "+
				"somewhat darker settings, leading you to wonder "+
				"why anyone would hang such dark art up.%^RESET%^"
		]));
        
		set_exits(([
                "east":ROOMS"north3"
        ]));

}

void reset(){
   ::reset();
   if(!present("peppy")) new(MOBS"peppy")->move(TO);
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}