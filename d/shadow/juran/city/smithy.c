#include <std.h>
#include "../juran.h"
inherit ROOM;

void create(){
	::create();
   set_name("smithy");
	set_short("Juran Smithy");
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
	set_property("indoors",1);
	set_long(
                "The blacksmith's work area is covered with soot and "+
		"smells of smoke.  This area is hot and oppressive owing to "+
		"the fact that the furnace is stoked and kept hot so that "+
		"the smith may apply his trade.  A large black anvil dominates "+
		"the center of the room and the furnace against the west wall.  "+
		"Raw iron ore sits in bins as well as billets piled in the "+
		"south awaiting to become a weapon or horse shoes.  A huge "+
		"wooden barrel of water sits next to the anvil.  Hammers, "+
		"tongs, and other tools of the smiths trade hang from the "+
		"rafters near the anvil.\n"+
		"%^RESET%^"
   );
	set_property("light",-2);
   set_smell("default", "The smell of oils, metal, and leather fill the air.");
   set_listen("default", "The shop is relatively quiet.");
	set_items(([
		({"tool","tools","hammer","tongs"}) : "Tools use by the "+
			"smithy hang awaiting use.  While the area is soot covered, "+
			"the tools are in excellent shape.\n",
		({"bins","iron ore","billets","billet"}) : "The bins contain "+
			"materials used by a smithy in making steel and iron items as "+
			"needed.  Near the bins are billets.  Billets are blocks of "+
			"steel, iron or other metal waiting shaping into a usable form.\n",
		"anvil" : "The anvil is huge and serves as the work surface for "+
			"the blacksmith in forming the metals of his trade into usable "+
			"items.  The anvil looks like it would be impossible to lift, but "+
			"even so it is affixed the the ground with huge spikes.\n",
		({"water","barrel","barrel of water"}) : "The barrel of water sits "+
			"next to the anvil so that the smithy will be able to quench the "+
			"metals he works on without moving very far from the anvil.\n"
   ]));
	set_exits(([
		"west" : JROOMS+"stables"
	]));
	set_property("smithy",1);
}
