#include <std.h>
inherit FIREARM;

create()
{
    ::create();
    set_id(({ "cannon", "gun" }));
    set_name("cannon");
    set_short("A cannon");
    set_long("This is an artillery cannon. Someone really big decided to use it as a handgun.");
    set_ammo("cannonball");
    set_two_handed();
    set_weight(40);
    set_size(4);

    set_range(4, 8, 12);
    set_wc(2, 14);
    set_large_wc(2, 14);
    set_critical_hit_multiplier(6);

    set_value(4000);
    set_weapon_speed(1);
    set_property("repairtype", ({ "weaponsmith" }));
}
