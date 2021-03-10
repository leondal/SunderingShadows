#include <std.h>
inherit "/std/food.c";

void create()
{
	::create();
	set_name("cured meat");
	set_short("Some cured meat");
	set_id(({"meat","food","cured meat"}));
	set_long(
	"These are several thin slices of deliciously cured meat.  Not much of"+
	" their flavor has been lost and they keep well without spoiling."
	);
	set_weight(2);
   set_strength(20);
	set_poison(0);
	set_destroy();
	set_canSave(1);
	set_value(5);
	set_my_mess("You eat the tasty slices of dried meat.");
	set_your_mess("eats several slices of dried meat.");
}
