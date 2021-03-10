#include <std.h>
#include "../antioch.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("sapphire ring");
	set_short("%^BOLD%^%^BLUE%^A st%^WHITE%^a%^BLUE%^r sapphire ring%^RESET%^");
	set_id(({"ring","sapphire ring","star sapphire ring"}));
	set_long(
	"%^BOLD%^%^WHITE%^This is a %^BLUE%^star %^RESET%^%^BLUE%^sapphire%^BOLD%^%^WHITE%^"+
	" ring. It has a band made out of white gold with stars etched into"+
	" it. In the center of the band the %^RESET%^%^BLUE%^sapphire%^BOLD%^%^WHITE%^"+
	" is set on top of a network of white gold strands. The gem is very"+
	" large and has been polished into an oval shape. The %^BLUE%^star%^WHITE%^"+
	" almost seems to be glowing it is so bright.%^RESET%^"
	);
	set_weight(1);
	set_value(3200);
	set_ac(0);
	set_type("ring");
	set_limbs(({"left hand","right hand"}));
}
