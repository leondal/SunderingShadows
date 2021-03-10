
#include <std.h>

inherit WEAPON;

void create()
{
  ::create();
    set_property("monsterweapon",1);
    set_name("darksword");
    set_id( ({"darksword","sword"}) );
    set_short("%^BOLD%^%^BLACK%^a darksword%^RESET%^");
    set_long("This sword is scorched black by fire but remains sharp "
             "and deadly. The hand guard and hilt look alot like a "
             "bat.");
    set_weight(5);
    set_value(1000);
    set_type("slashing");
    set_wc(1,6);
    set_large_wc(1,8);
    set_property("enchantment",2);
}
