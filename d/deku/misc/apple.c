#include <std.h>
inherit "/std/food.c";

void create() {
        ::create();
        set_name("apple");
        set_id(({"apple","food"}));
        set_short("%^BOLD%^%^RED%^Shiny red apple%^RESET%^");
        set_weight(1);
        set_value(0);
        set_destroy();
        set_poison(0);
        set_strength(5);
        set_long("This %^BOLD%^%^RED%^shiny red apple %^RESET%^is still "
            "quite fresh and looks delicious.");
        set_my_mess("When you bite into it, you find that the %^BOLD%^%^RED%^apple "
            "%^RESET%^is as crisp, juicy, and delicious as it looked.");
        set_your_mess("eats the %^BOLD%^%^RED%^shiny red apple%^RESET%^ "
            "and seems to enjoy it.");
}
