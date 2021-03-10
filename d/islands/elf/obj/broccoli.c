#include <std.h>
inherit "/std/food.c";

void create()
{
        ::create();
        set_name("%^GREEN%^broccoli%^RESET%^");
        set_short("%^RESET%^%^GREEN%^fresh broccoli%^RESET%^");
        set_id(({"broccoli","food","fresh broccoli"}));
        set_long(
        "%^GREEN%^This is a fresh head of broccoli.  It smells nice "+
		"but is a little small.  It would make a nice snack.%^RESET%^");
        set_weight(1);
        set_value(1);
        set_destroy();
        set_poison(0);
        set_strength(5);
        set_my_mess("You crunch away at the fresh broccoli.");
        set_your_mess("munches away on some broccoli.");
}
