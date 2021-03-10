#include <std.h>
inherit "/std/food.c";

void create()
{
	::create();
	set_name("plum");
	set_id(({"plum","ripe plum"}));
	set_short("%^MAGENTA%^A ripe plum");
	set_long(
	"%^MAGENTA%^A delicious and ripe plum. It looks very tasty."
	);
	set_weight(1);
	set_value(0);
	set_destroy();
	set_poison(0);
	set_strength(3);
	set_my_mess("You bite into the delicious plum, it's very sweet and juicy.");
	set_your_mess("eats a plum.");
}
