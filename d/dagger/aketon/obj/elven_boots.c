#include <std.h>
inherit "/std/armour";

void create()
{
	::create();
	set_name("%^GREEN%^elven boots%^RESET%^");
	set_id(({"boots","green boots","elf boots","elven boots"}));
	set_short("Elven boots");
	set_long(
	"%^GREEN%^These boots are made from supple leather that has been dyed"+
	" a dark green. They look like they would be very comfortable.%^RESET%^"
	);
	set_weight(3);
	set_size(2);
	set_type("clothing");
	set_ac(1);
	set_value(180);
	set_limbs(({"right foot","left foot"}));
   set_wear("%^GREEN%^You slip the boots onto your fit, a perfect fit.%^RESET%^");
}

