#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("black sash");
	set_short("%^BOLD%^%^BLACK%^Black Sash%^RESET%^");
	set_id(({"sash","black sash","Black Sash","Black sash"}));
	set_long(
         "%^BOLD%^%^BLACK%^This sash has been created from "+
         "the finest black silk.  The symbol of the guard of "+
         "Tonovi has been sewn into one end of the sash."
	);
	set_weight(3);
	set_value(1);
	set_type("clothing");
	set_limbs(({"waist"}));
	set_ac(0);
}
