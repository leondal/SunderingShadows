#include <std.h>
inherit "/std/food.c";

void create() {
	::create();
	set_name("nuts");
	set_short("A bag of mixed nuts");
	set_id(({"nuts","bag of nuts","mixed nuts","bag of mixed nuts","bag","food"}));
	set_long(
	"This is a bag of mixed nuts. They are good for the trail because they"+
	" last for a long time and can be snacked on while you're walking. There"+
	" are many different types, peanuts, pecans, walnuts, almonds, and"+
	" cashews. All of them have been shelled already."
	);
	set_weight(3);
	set_value(10);
	set_destroy();
	set_poison(0);
   set_strength(20);
	set_canSave(1);
	set_my_mess("You snack on a bag of delicious nuts.");
	set_your_mess("eats a bag of mixed nuts.");
}
