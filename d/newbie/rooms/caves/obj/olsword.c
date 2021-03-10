#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

create() {
   	::create();
   	set_id(({ "sword", "longsword", "long sword", "obsidian sword","obsidian longsword" }));
   	set_name("longsword");
   	set_short("%^BOLD%^%^BLUE%^obsidian long sword%^RESET%^");
   	set_long(
   		"%^BOLD%^%^BLUE%^"+
   		"This longsword is made from the volcanic glass called obsidian.  "+
   		"You would think it would be brittle, but it is fact quite resilient. "+
   		"The blade has been painstakingly chiseled into a double edged weapon "+
   		"with a sharp point.  The handle has been wrapped with leather straps to "+
   		"make the grip quite comfortable and effective.  The weapon is thinner "+
   		"than the broad and bastard sword, but a bit longer in length.  It looks "+
   		"very effective as its combination of an edge, point, speed and length "+
   		"make it more versatile than many other weapons.\n"+
		"%^RESET%^"
   	);
   	//set_weight(7);
   	set_size(2);
   	set("value", 15);
   	//set_wc(2,4);
   	//set_large_wc(2,6);
	//set_type("slashing");
   	//set_weapon_speed(5);
}
