#include <std.h>
inherit "/std/food.c";

void create() {
        ::create();
        set_name("peach");
        set_id(({"peach","food"}));
        set_short("%^YELLOW%^Ri%^RED%^p%^YELLOW%^e pe%^RED%^a%^YELLOW%^ch%^RESET%^");
        set_weight(1);
        set_value(0);
        set_destroy();
        set_poison(0);
        set_strength(5);
        set_long("This nicely firm, fuzzy %^YELLOW%^peach %^RESET%^still has "
            "a blush of red and looks just ripe enough to be really tasty.");
        set_my_mess("The %^YELLOW%^peach %^RESET%^is just sour enough to "
            "make you pucker a little as you enjoy the flavor.");
        set_your_mess("eats the %^YELLOW%^ripe peach%^RESET%^ and puckers a "
            "little.");
}
