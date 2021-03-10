// A sword for the Shadow Guard ... by Killashandra

#include <std.h>
#include <daemons.h>
#include "/d/stella/short.h"

inherit "std/weapon";
	
void create(){
	::create();
	set_name("Shadow Sword");
	set_id(({"sword","shadow sword"}));
        set_short("Shadow Sword");
        set_long("A sword seemingly formed of shadow!");
	set_weight(1);
	set_value(1000);
        set_property("monsterweapon",1);
	set_wc(1,8);
	set_large_wc(1,12);
	set_size(2);
	set_type("slashing");
	set_property("enchantment",4);
	}
