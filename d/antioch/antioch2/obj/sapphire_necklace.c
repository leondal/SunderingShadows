#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("sapphire necklace");
	set_short("%^BOLD%^%^BLUE%^An exquisite %^RESET%^%^BLUE%^"+
		"s%^CYAN%^a%^BOLD%^p%^BLUE%^p%^RESET%^%^CYAN%^h%^BLUE%^"+
		"i%^BOLD%^r%^RESET%^%^BLUE%^e%^BOLD%^ necklace%^RESET%^");
	set_id(({"necklace","sapphire necklace","exquisite necklace","exquisite sapphire necklace"}));
	set_long(
	"%^RESET%^This is an absolutely breath taking %^BLUE%^sapphire%^RESET%^ necklace."+
	" The chain is made of white gold and is quite thick, %^BLUE%^sapphires%^RESET%^"+
	" drip down from the center of it, longest in the center of the chain."+
	" The center %^BLUE%^sapphire%^RESET%^ that is set into the necklace is quite large, and has a brilliant %^BOLD%^%^BLUE%^star%^RESET%^ in"+
	" the center of it."
	);
	set_weight(2);
	set_value(5000);
	set_ac(0);
	set_type("ring");
	set_limbs(({"neck"}));
}
