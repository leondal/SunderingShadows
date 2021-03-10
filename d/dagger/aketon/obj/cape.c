#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("white cape");
	set_id(({"cape","white cape","cloak","white cloak"}));
	set_short("%^WHITE%^A white cape%^RESET%^");
	set_long(
	"%^WHITE%^%^BOLD%^This cape is made out of a light material"+
	" that appears to be a mixture of cotton and silk. It is"+
	" soft and smooth to the touch and it ties around the wearer's"+
	" head and has a hood that you can lift up over your face.%^RESET%^"
	);
	set_value(30);
	set_weight(5);
	set_ac(1);
	set_size(2);
	set_property("enchantment",1);
	set_limbs(({"neck"}));
	set_type("clothing");
}

