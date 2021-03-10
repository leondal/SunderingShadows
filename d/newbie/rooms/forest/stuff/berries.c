#include <std.h>
inherit "/std/food.c";

void create() {
        ::create();
        set_name("berries");
        set_id(({"berries","juicy berries","food"}));
        set_short("%^MAGENTA%^Juicy berries%^RESET%^");
        set_weight(1);
        set_value(0);
        set_destroy();
        set_poison(0);
        set_strength(5);
        set_long("This handful of %^MAGENTA%^berries %^RESET%^looks juicy and tasty.");
        set_my_mess("Some of the juice runs down your chin as you eat the %^MAGENTA%^berries %^RESET%^with zeal.");
        set_your_mess("eats the handful of %^MAGENTA%^juicy berries with zeal.");
}
