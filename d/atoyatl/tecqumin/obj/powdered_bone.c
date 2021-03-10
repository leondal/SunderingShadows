//Coded by Lujke


#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("bone powder");
    set_id( ({"powder","bone","bone powder","powdered bone", "handfull"
                 }) );
    set_short("%^BOLD%^%^WHITE%^handful of powdered bone");
    set_weight(1);
    set_long("A handful of%^BOLD%^%^WHITE%^ powdered b%^RESET%^o%^BOLD%^"
            +"%^WHITE%^ne%^RESET%^, slimed and smeared with some %^BOLD%^"
            +"%^BLACK%^dark greasy substance%^RESET%^. It's not very"
            +" nice.");
}


