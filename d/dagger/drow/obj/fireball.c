#include <std.h>
inherit WEAPON;
void create() {
    ::create();
    set_id (({"fireball"}));
    set_name ("fireball");
    set_short ("%^RED%^%^BOLD%^Fireball");
set_long ("The fireball of the fire witch.");
    set_weight (20);
    set_size (1);
    set_value (1);
    set_property ("monsterweapon",1);
    set_wc (4,4);
set_type ("bludgeoning");
}
