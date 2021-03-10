#include <std.h>
#include "../antioch.h"
inherit "/std/food.c";

void create()
{
	::create();
	set_name("cheese");
	set_short("A block of cheese");
	set_id(({"cheese","block of cheese","food"}));
	set_long(
	"This is a block of hardened cheese.  It is kept in a protective cloth"+
	" but you can still smell it easily.  It has a rather pungent odor and it"+
	" is white.  That's about all you can tell of it.  They say it's supposed"+
	" to travel fairly well and that the taste is a bit strong."
	);
	set_weight(3);
   set_strength(14);
	set_value(5);
	set_poison(0);
	set_destroy();
	set_canSave(1);
	set_my_mess("You eat the block of cheese.  It has a very strong taste but"+
	" you still aren't sure what type it is.");
	set_your_mess("eats a block of cheese.");
}
