#include <std.h>
inherit "/std/food.c";

void create()
{
	::create();
	set_name("apple");
	set_id(({"apple","big apple","red apple","large apple","food"}));
	set_short("%^BOLD%^%^RED%^A big red apple%^RESET%^");
	set_weight(1);
	set_value(0);
	set_destroy();
	set_poison(0);
	set_strength(5);
	set_long("%^BOLD%^%^RED%^This is a large red apple that looks"+
	" absolutely delicious.");
	set_my_mess("You sink your teeth into the delicious apple, enjoying every bite.");
	set_your_mess("eats a delicious %^BOLD%^%^RED%^red%^RESET%^ apple.");
}
