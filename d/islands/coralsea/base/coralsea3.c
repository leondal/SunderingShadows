#include <std.h>
#include "../defs.h"
inherit BASE"coralfun";

// Coral Sea Area - Created January 2009 by Ari
// Is inherited by all coral_s22-s25.c files


void create(){
	::create();
		set_property("light",1);
		set_property("indoors",0);
		set_property("no teleport",1);
		set_terrain(DEEP_WATER);
		set_travel(FRESH_BLAZE);
	
		set_name("Under the Saakrune Sea");
		set_short("%^RESET%^%^CYAN%^Under the S%^WHITE%^a%^GREEN%^a"+
				"%^CYAN%^kr%^WHITE%^u%^GREEN%^n%^CYAN%^e S%^WHITE%^e"+
				"%^GREEN%^a%^RESET%^");
	
		set_long("%^BOLD%^%^BLUE%^The deep waters of the ocean swirl "+
				"around you in an %^BLACK%^inky blackness %^BLUE%^that "+
				"makes it near impossible to see.  Long gone are the "+
				"faint rays of light cast by the moon and sun into the "+
				"surface waters, all that is left is the cheerless "+
				"%^RESET%^%^BLUE%^abyss %^BOLD%^of the deep waters.  "+
				"An occasional flicker of %^BLUE%^p%^GREEN%^h%^CYAN%^"+
				"o%^BLUE%^sp%^GREEN%^h%^CYAN%^or%^BLUE%^es%^GREEN%^c"+
				"%^CYAN%^e%^BLUE%^nt l%^CYAN%^i%^GREEN%^g%^BLUE%^ht "+
				"%^BOLD%^catches your attention, but as soon as you "+
				"turn toward it, it flits away, born away by the fish "+
				"whose body has adapted to this dark realm.  Here and "+
				"there, piles of rock and rubble rise upward from the "+
				"sandy bottom, their shapes looking a bit too ordered "+
				"to be naturally placed.%^RESET%^\n");
	
		set_smell("default","\nThere is nothing to smell under the water.");
		set_listen("default","You hear your air bubbling away.");
	
		set_items(([
		
			({"rock","rubble","bottom"}):"%^BOLD%^%^BLACK%^The sandy "+
				"bottom of the sea is strewn with rock piles here.  "+
				"The shapes a bit too square in their lay out to "+
				"reflect natural placement and you imagine these might "+
				"have been some of the buildings near the large tower "+
				"structure.  If they are, there might be something "+
				"hidden within them.  Though what would have survived "+
				"this long is a mystery.%^RESET%^",
	
			({"water","inky blackness","blackness"}):"%^BOLD%^%^BLUE%^These "+
				"dark waters make it impossible to see much of anything. "+
				"What little you can see is restricted to any light you "+
				"currently carry.%^RESET%^",
		
			({"light","phosphorescent light","phosphorescence","fish"}):""+
				"%^BOLD%^%^BLUE%^The occasional, faint flicker of pale "+
				"light catches your attention in these dark waters, but "+
				"as soon as you look for the creature that causes, the "+
				"light vanishes.%^RESET%^",
					
		]));
	
	set_pre_exit_functions(({"rise","dive","north","south","east","west","northeast",
		"northwest","southeast","southwest"}),({"GoThroughDoor","GoThroughDoor",
		"GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor",
		"GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor"}));
}


