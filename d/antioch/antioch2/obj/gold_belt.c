#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("golden belt");
	set_short("%^YELLOW%^Golden Belt%^RESET%^");
	set_id(({"gold belt","golden belt","belt","Golden Belt"}));
	set_long(
	"%^YELLOW%^This belt is made out of yellow silk that has been woven"+
	" together like a rope, and ties around the waist. Golden threads"+
	" have been woven through the belt to strengthen it and give it a"+
	" little sparkle.%^RESET%^"
	);
set_weight(1);
	set_value(1);
set_type("ring");
	set_limbs(({"waist"}));
	set_ac(0);
    set_property("repairtype",({ "tailor" }));
}
