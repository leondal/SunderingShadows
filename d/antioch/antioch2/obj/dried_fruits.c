#include <std.h>
inherit "/std/food.c";

void create()
{
	::create();
	set_name("dried fruits");
	set_short("A bag of dried fruits");
	set_id(({"dried fruits","fruits","fruit","food"}));
	set_long(
	"This is a bag of mixed dried fruits.  You see raisins, dried figs,"+
	" plums, peaches, apples, and even some apricots."
	);
	set_weight(3);
	set_value(5);
   set_strength(25);
	set_canSave(1);
	set_destroy();
	set_poison(0);
	set_my_mess("You eat a bag of delicious dried fruits, they're quite good.");
	set_your_mess("eats a bag of dried fruits.");
}
