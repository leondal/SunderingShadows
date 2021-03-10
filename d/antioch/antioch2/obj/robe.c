#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("robe");
	set_id(({"robe","cloth robe","azure robe"}));
	set_short("%^RESET%^%^CYAN%^A%^BOLD%^%^BLUE%^z"+
		"%^RESET%^%^CYAN%^u%^BOLD%^%^BLUE%^r%^RESET%^%^CYAN%^e robe");
	set_long(
	"%^BOLD%^%^CYAN%^This lovely azure robe has been crafted with the idea"+
	" of protection in mind, though it only offers a little. It is a lovely"+
	" shade, the color rich throughout the garment. Quilted layers of thick"+
	" cotton have been woven together to create minimal encumbrance and bulge,"+
	" while allowing maximum protection. It is useful as well as pretty. %^RESET%^"
	);
	set_weight(5);
	set_value(20);
	set_type("clothing");
	set_limbs(({"torso"}));
}
