#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("silver robe");
	set_short("%^BOLD%^%^WHITE%^Silver Robe%^RESET%^");
	set_id(({"robe","silver robe","Silver Robe"}));
	set_long(
	"%^BOLD%^%^WHITE%^This robe has been crafted from a gray cotton and has been woven with"+
	" threads of silver, to give it added protection as well as a silver"+
	" glow. The image of a pegasus has been woven into the front with the"+
	" silver threads, the sign of the Antioch guard.%^RESET%^"
	);
	set_weight(8);
        set_value(30);
	set_type("clothing");
        set_size(-1);
	set_limbs(({"torso"}));
	set_ac(1);
	if(!random(5)) {
        set("no curse",1);
		set_property("enchantment",1);
	}
}
