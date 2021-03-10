#include <std.h>
inherit "/std/food.c";

void create() {
        ::create();
        set_name("snake meat");
        set_id(({"meat","snake meat","food"}));
        set_short("%^RED%^Snake meat%^RESET%^");
        set_weight(1);
        set_value(0);
        set_destroy();
        set_poison(0);
        set_strength(8);
        set_long("This is chunk of raw meat.  You can tell from the skin still on part of it that it was cut or gnawed from the corpse of one of the large snakes found in this area.  It looks fairly fresh.");
        set_my_mess("The meat is stringy and some blood oozes from it as you gnaw on it savagely.");
        set_your_mess("gnaws on the raw meat savagely.");
}
