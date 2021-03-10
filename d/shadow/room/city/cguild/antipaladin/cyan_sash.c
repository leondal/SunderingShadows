#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("dark cyan sash");
	set_short("%^CYAN%^Dark Cyan Sash%^RESET%^");
	set_id(({"sash","cyan sash","dark cyan sash","Dark Cyan Sash"}));
	set_long(
         "%^CYAN%^This sash is made out of a cyan color silk.  "+
         "Mithril thread is sewn throughout the sash giving is a slight glow."
	);
	set_weight(3);
	set_value(1);
	set_type("clothing");
	set_limbs(({"waist"}));
	set_ac(0);
}
