#include <std.h>
inherit "/std/armour";
void create(){
    ::create();
set_name("dark shield");
set_id(({"shield","dark shield"}));
set_short("%^RESET%^%^BLUE%^Dark Shield%^RESET%^");
set_long(
        "This is an extremely dark and menacing looking shield.  It covers most of the body and must be quite heavy."
        );
set_weight(30);
set_value(150);
set_type("shield");
set_limbs(({"right hand"}));
set_ac(1);
set_property("enchantment", 2);

}
