#include <std.h>

inherit LRWEAPON;

int is_firearm()
{
    return 1;
}

create() {
    ::create();
    set_lr_prof_type("firearm");
    set_damage_type("piercing");
    set_ammo("bullet");
    set_type("firearm");
    set_weapon_prof("exotic");
    set_prof_type("club");
    set_decay_rate(5);
    set_wc(1,2);
    set_large_wc(1,2);
    set_critical_hit_multiplier(4);
    set_rate_of_fire(10);
    set_range(2,4,8);
}
