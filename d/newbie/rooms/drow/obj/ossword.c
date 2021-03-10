#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

create() {
   	::create();
   	set_id(({ "sword", "shortsword", "short sword", "obsidian sword","obsidian shortsword", "obsidian short sword" }));
   	set_name("shortsword");
   	set_short("%^BOLD%^%^BLUE%^obsidian shortsword%^RESET%^");
   	set_long(
   		"%^BOLD%^%^BLUE%^"+
   		"This shortsword is made from the volcanic glass called obsidian.  "+
   		"You would think it would be brittle, but it is fact quite resilient. "+
   		"The blade has been painstakingly chiseled into a double edged weapon "+
   		"with a sharp point.  The handle has been wrapped with leather straps to "+
   		"make the grip quite comfortable and effective.  The weapon is shorter "+
                    "than other swords, but makes a good backup weapon that your opponent "+
   		"cannot ignore.\n"+
		"%^RESET%^"
   	);
   	set_weight(5);
   	set_size(1);
   	set("value", 10);
   	//set_wc(2,3);
   	//set_large_wc(1,8);
	//set_type("slashing");
   	//set_weapon_speed(5);
}
