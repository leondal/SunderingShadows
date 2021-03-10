// A sword for the Shadow Guard ... by Killashandra

#include <std.h>
#include <daemons.h>
#include "/d/stella/short.h"

inherit "std/armour";
	
void create(){
	::create();
	set_name("Shadow Armor");
	set_id(({"armor","shadow armor"}));
        set_short("Shadow Armor");
        set_long("Plate armor seemingly formed of shadow!");
	set_weight(5);
	set_value(7000);
        set_property("monsterarmor",1);
	set_ac(2);
        set_type("plate");
        set_limbs(({"torso"}));
	set_property("enhancement",5);
	}
