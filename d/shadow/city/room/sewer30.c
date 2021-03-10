//Titania 10/21/2019
//Shadow Sewers, Room 30

#include <std.h>
#include "../defs.h"
inherit INH"sewer";

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",0);
   set_travel(DECAYED_FLOOR);
   set_terrain(BUILT_TUNNEL);
   set_climate("temperate");
   set_name("%^RESET%^%^ORANGE%^A small crumbling room%^RESET%^");
   set_short("%^RESET%^%^ORANGE%^A small crumbling room%^RESET%^");
   set_long("%^RESET%^This dark room is little more than a rotting "+
   "%^ORANGE%^straw mattress %^WHITE%^tossed into the corner. A rotting "+ 
   "%^CYAN%^blanket %^WHITE%^is balled up and thrown aside. Some burnt down "+ 
   "%^BOLD%^candles %^RESET%^are melted to the %^ORANGE%^dirty floor%^WHITE%^. "+ 
   "The walls are cold and crumbling, and the cracks in the ceiling drip "+ 
   "with fetid water. It seems as if someone once called this small room "+ 
   "home, but have long since moved on.\n");
   set_smell("default","You smell the disgusting confluence of refuse "+
      "and excrement wafting all about you.");
   set_listen("default","You hear flowing water echoing throughout "+
      "the nearby tunnel.");
   set_items(([
	({"walls","ceiling","floor"}) : "%^BOLD%^%^BLACK%^The structure of this room is crumbling and looks as if it's set to collapse at any time. Mold grows in cracks, made damp from the water seeping in through the ceiling.%^RESET%^",
	({"candles"}) : "%^BOLD%%^WHITE%^These plain wax candles have long since burnt out.%^RESET%^",
	({"mattress","blanket"}) : "%^RESET%^ %^MAGENTA%^Once upon a time this might have been some very uncomfortable sleeping quarters, but now is nothing more than a nest for rats and bugs.%^WHITE%^",
	]));  
   set_exits(([
	  "north" : ROOMS"sewer29",
   ]));	
}
