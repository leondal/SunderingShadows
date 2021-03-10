#include <std.h>
inherit "/std/food";

void create()
{
	::create();
	set_name("honey comb");
	set_id(({"honey comb","honey","honeycomb"}));
	set_short("A piece of sticky honey comb");
	set_long(
	"%^YELLOW%^This is a large piece of very sticky honey comb. It's getting"+
	" all over your fingers as you hold it, and you can smell its sweet"+
	" fragarance that makes your mouth water."
	);
	set_weight(1);
	set_value(0);
	set_destroy();
	set_poison(0);
	set_strength(3);
	set_my_mess("You eat the sweet piece of honey comb, licking your fingers"+
	" of honey when you're done.");
	set_your_mess("eats a sticky piece of honey comb.");
}
