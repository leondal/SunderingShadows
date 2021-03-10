#include <std.h>
inherit "/std/food.c";

void create()
{
	::create();
	set_name("pine nuts");
	set_short("A bag of pine nuts");
	set_id(({"nuts","bag of nuts","pine nuts","bag of pine nuts","bag","food"}));
	set_long(
         "This small bag is made of thick burlap.  A flap closes the "+
         "top, though there seems to be no way to secure it.  Inside are "+
         "tiny white pine nuts collected from the trees nearby.  Their "+
         "smell is reminiscent of clean mountain air."
	);
	set_weight(4);
	set_value(10);
	set_destroy();
	set_poison(0);
      set_strength(15);
	set_canSave(1);
	set_my_mess("You snack on a bag of delicious nuts.");
	set_your_mess("eats a bag of pine nuts.");
}
