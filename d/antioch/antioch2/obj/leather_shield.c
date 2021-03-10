// #include <std.h>
// #include "../antioch.h"
// inherit "/std/armour";
// changing to use /d/common/obj files

inherit "/d/common/obj/armour/shield.c";

void create() {
	::create();
	set_name("leather shield");
	set_short("A leather shield");
	set_id(({"shield","leather shield","A leather shield","leather_shield"}));
	set_long(
	"This shield has been crafted from a large piece of hide that has been"+
	" tanned for a long time, and then stretched over a metal frame. It has"+
	" been waterproofed completely and looks like it would provide adequate"+
	" protection. A diamond pattern has been carved into the front of the shield."
	);
//	set_type("shield");
	set_weight(10);
//	set_value(10);
//	set_limbs(({"right hand"}));
}
