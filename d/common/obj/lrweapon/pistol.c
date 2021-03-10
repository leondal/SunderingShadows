#include <std.h>
inherit FIREARM;

create()
{
    ::create();
    set_id(({ "pistol", "gun" }));
    set_name("pistol");
    set_short("A pistol");
    set_long("This is primitive single-barrel firearm with flintlock mechanism that fires paper cartridges.");
    set_weight(4);
    set_size(1);
    set_value(1000);

    set_wc(1, 8);
    set_large_wc(1, 8);

    set_critical_hit_multiplier(4);
    set_type("bludgeoning");
    set_lr_prof_type("gun");

    set_weapon_prof("exotic");

    set_rate_of_fire(4);
    set_range(2, 4, 6);
    set_ammo("cartridge");

    set_decay_rate(100);
    set_weapon_speed(1);
    set_damage_type("piercing");
    set_property("repairtype", ({ "weaponsmith" }));
}
