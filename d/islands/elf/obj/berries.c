#include <std.h>
inherit "/std/food.c";

void create()
{
        ::create();
        set_name("%^GREEN%^berries%^RESET%^");
        set_short("%^RESET%^%^GREEN%^bag of berries%^RESET%^");
        set_id(({"berries","food","bag of berries"}));
        set_long(
        "%^GREEN%^This is a bag of fresh berries.  It smells nice "+
		"and looks tastey.  It would make a nice snack.%^RESET%^");
        set_weight(1);
        set_value(1);
        set_destroy();
        set_poison(0);
        set_strength(5);
        set_my_mess("You munch down the yummy berries.");
        set_your_mess("munches away on a bag of berries.");
}
