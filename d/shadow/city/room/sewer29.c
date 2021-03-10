//Titania 10/21/2019
//Shadow Sewers, Room 29

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
   set_long("%^RESET%^This small room looks as if it's been lived in, although "+ 
   "does not appear to be currently occupied. Piles of %^GREEN%^rubble %^WHITE%^and "+ 
   "%^ORANGE%^wood %^WHITE%^and %^BOLD%^%^BLACK%^broken things %^RESET%^line the "+ 
   "walls, and a few %^ORANGE%^wobbly chairs %^WHITE%^are strewn about the area. A "+ 
   "%^ORANGE%^wooden table %^WHITE%^sits atop an old, %^CYAN%^tattered rug "+ 
   "%^WHITE%^in the middle of the room. The water-stained floor and walls are "+ 
   "made from %^BOLD%^%^BLACK%^crumbling stones%^RESET%^, and "+ 
   "%^BOLD%^%^GREEN%^m%^RESET%^%^GREEN%^o%^BOLD%^ld %^RESET%^grows in every "+ 
   "crack and crevice. Some %^CYAN%^water %^WHITE%^drips down from the "+ 
   "cracking ceiling.%^RESET%^\n");
   set_smell("default","You smell the disgusting confluence of refuse "+
      "and excrement wafting all about you.");
   set_listen("default","You hear flowing water echoing throughout "+
      "the nearby tunnel.");
   set_items(([
	({"rubble","wood","things"}) : "%^RESET%^%^MAGENTA%^Sometimes one man's trash is another man's treasure, but these piles have been picked through and scavenged so many times that only useless garbage remains.%^WHITE%^",
	({"chairs"}) : "%^RESET%^%^ORANGE%^Chairs collected from various establishments and households seem to have found their way to this small room. The only thing they have in common is that they're either broken or breaking. Sit at your own risk.%^WHITE%^",
	({"table"}) : "%^RESET%^%^ORANGE%^The surface of the table is so marred and marked from decades of defacers that it looks like scribbles atop of scribbles.%^WHITE%^",
	({"rug"}) : "%^RESET%^%^CYAN%^This rug is so threadbare and dirty that it's impossible to tell what it looked like, once upon a time. Really, it's a stretch to call it a rug at all. %^WHITE%^",
	({"walls","ceiling","floor"}) : "%^BOLD%^%^BLACK%^The structure of this room is crumbling and looks as if it's set to collapse at any time. Mold grows in cracks, made damp from the water seeping in through the ceiling. %^RESET%^",
	]));  
   set_exits(([
      "east" : ROOMS"sewer27",
	  "south" : ROOMS"sewer30",
   ]));	
}
