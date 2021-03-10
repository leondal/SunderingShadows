#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("belt");
	set_short("%^RESET%^%^ORANGE%^A leather belt%^RESET%^");
	set_id(({"belt","leather belt","brown belt"}));
	set_long(
	"%^ORANGE%^This is a simple belt made from leather.  It has been left its natural"+
	" color, which is a rich brown.  It has a %^YELLOW%^brass%^RESET%^%^ORANGE%^"+
	" buckle.  There are several"+
	" sets of holes to put the buckle through, allowing the wearer to select"+
	" a comfortable fit." 
	);
	set_weight(1);
	set_value(2);
	set_ac(0);
	set_type("ring");
	set_limbs(({"waist"}));
    set_property("repairtype",({ "armorsmith" }));
}
