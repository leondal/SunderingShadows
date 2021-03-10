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
		
		set_name("general store of tharis");
        set_short("%^YELLOW%^General Store of Tharis%^RESET%^");
        set_long("%^YELLOW%^General Store of Tharis%^RESET%^\n"+
			"%^RESET%^A selection of goods are laid out in neat, "+
			"organized %^ORANGE%^shelves %^RESET%^and %^BOLD%^"+
			"%^BLACK%^bins%^RESET%^.  Each one labeled with its "+
			"contents along with the price asked.  Though many "+
			"of the supplies upon these %^ORANGE%^hard wood "+
			"shelves %^RESET%^are mundane, the occasional piece "+
			"of %^MAGENTA%^e%^CYAN%^n%^MAGENTA%^cha%^WHITE%^n"+
			"%^CYAN%^t%^MAGENTA%^ed %^RESET%^equipment, %^BOLD%^"+
			"%^BLACK%^scroll %^RESET%^or other such %^YELLOW%^ "+
			"trinket %^RESET%^turns up for sale now and again.  "+
			"Between the shelves, wide isles allow for easy "+
			"movement of patrons, even the larger set, without "+
			"risking anything being knocked over.  Toward the back "+
			"of the shop a few %^ORANGE%^racks %^RESET%^have been "+
			"arranged for wearable goods, though the selection "+
			"looks pretty slim right now.  Toward the front of "+
			"the shop, near the only door, is a %^BOLD%^%^BLACK%^"+
			"flat-topped counter%^RESET%^ behind which the "+
			"store clerk sits and helps customers.%^RESET%^");
		
		set_smell("default","A faint citrus smell can be detected.");
		set_listen("default","The shop is noisy with customers.");
		
        set_items(([
			({"shelves","bins","goods","supplies"}):"%^RESET%^"+
				"%^ORANGE%^Made from a type of hardwood that looks "+
				"strong and meant for enduring, the shelves are set "+
				"along wide isles that give plenty of room for "+
				"customers to walk along.  Each shelf is neatly "+
				"organized, some containing bins for the smaller "+
				"items, while others simply have supplies set out "+
				"upon them.  Prices are marked and you could "+
				"probably send some time moving going through the "+
				"inventory to find what you're looking for.%^RESET%^",			
			({"enchanted equipment","scroll","trinket"}):"%^BOLD%^"+
				"%^WHITE%^Most of the gear for sale looks ordinary "+
				"and mundane, but every now and again the shop will "+
				"have something magical for sale.  Usually these "+
				"are placed toward the front of the shop where the "+
				"store clerk can keep an eye on them.  You'd have "+
				"to check the inventory to find out if anything "+
				"really good is for sale today.%^RESET%^",
			({"racks"}):"%^RESET%^%^ORANGE%^The racks are located "+
				"toward the back of the store.  They appear to be "+
				"meant for the wearable gear that is occasionally "+
				"sold here.  Since the inventory changes "+
				"occasionally you never know what you'll find back "+
				"there.%^RESET%^",
			({"counter"}):"%^BOLD%^%^BLACK%^The counter is a wide, "+
				"flat topped structure that is more like a table "+
				"then a true counter.  Bins of sale items are "+
				"tucked under it and tilted to face customers for "+
				"a last minute buy, while behind the counter the "+
				"shop's clerk sits, taking money and wrapping "+
				"goods up for their travel home."
		]));
		
		set_exits(([
                "west" : ROOMS"north2"
        ]));

}

void reset(){
   ::reset();
   if(!present("cath")) new(MOBS"cath")->move(TO);
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}