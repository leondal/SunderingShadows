#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("vest");
	set_short("%^RESET%^%^ORANGE%^A leather vest%^RESET%^");
	set_id(({"vest","leather vest","brown vest"}));
	set_long(
	"%^RESET%^%^ORANGE%^This leather vest has been made from high quality hide. It is a very"+
	" dark brown and has been tanned enough to make it durable for everyday"+
	" things, but still comfortable. Brass buttons can either close up the"+
	" front, or be left undone, whatever the wearer wishes.%^RESET%^"
	);
	set_value(12);
	set_weight(1);
	set_type("ring");
	set_limbs(({"torso"}));
	set_ac(0);
    set_property("repairtype",({ "armorsmith" }));
}
