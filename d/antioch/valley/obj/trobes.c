#include <std.h>
#include "../valley.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("tattered robes");
	set_id(({"robes","tattered robes"}));
	set_short("Tattered robes");
	set_long(
	"These are the very tattered, dirty robes. They have a"+
	" rather unpleasant smell to them, like that of a graveyard"+
	" and corpses. It looks like the color of these robes"+
	" might once have been a pretty sapphire blue, but it's"+
	" hard to tell now."
	);
	set_size(2);
	set_property("enchantment",1);
	set_value(10);
	set_weight(10);
//        set_ac(-2);
	set_limbs(({"torso"}));
	set_wear((:TO,"wear_me":));
	set_remove((:TO,"remove_me":));
	set_type("clothing");
}

int wear_me()
{
	write("%^ORANGE%^You put the tattered robe on and can"+
	" feel the grime against your skin.");
	say("%^ORANGE%^As "+ETO->query_cap_name()+" puts on the"+
	" tattered robe "+ETO->query_subjective()+" gets a"+
	" disgusted look on "+ETO->query_possessive()+" face.");
	return 1;
}

int remove_me()
{
	write("%^BOLD%^%^YELLOW%^As you remove the robes you can"+
	" feel your skin tingle in the cool air, free at last.");
	say("%^BOLD%^%^YELLOW%^As "+ETO->query_cap_name()+" removes"+
	" the robes "+ETO->query_subjective()+" gets a relieved"+
	" look on "+ETO->query_possessive()+" face.");
	return 1;
}
