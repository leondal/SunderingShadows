#include <std.h>
inherit "/std/food.c";

void create()
{
        ::create();
        set_name("%^GREEN%^cabbage%^RESET%^");
        set_short("%^RESET%^%^GREEN%^fresh cabbage%^RESET%^");
        set_id(({"cabbage","food","fresh cabbage"}));
        set_long(
        "%^GREEN%^This is a fresh head of cabbage.  It smells nice "+
		"but is a little small.  It would make a nice snack.%^RESET%^");
        set_weight(1);
        set_value(1);
        set_destroy();
        set_poison(0);
        set_strength(5);
        set_my_mess("You crunch away at the fresh cabbage.");
        set_your_mess("munches away on some cabbage.");
}
