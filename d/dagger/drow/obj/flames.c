#include <std.h>
inherit WEAPON;
void create() {
    ::create();
    set_id (({"flames"}));
    set_name ("flames");
    set_short ("%^BOLD%^%^RED%^Flames");
set_long ("The flames of the fire witch.");
    set_weight (5);
    set_size (2);
    set_value (1);
    set_property ("monsterweapon",1);
    set_wc (3,6);
set_type ("bludgeoning");
}
