#include <std.h>
inherit FIREARM;

create()
{
    ::create();
    set_id(({ "hackbut", "gun" }));
    set_name("hackbut");
    set_short("A hackbut");
    set_ammo("cartridge");

    set_long("This double-length rifle uses a pair of trunnions to mount its barrel into a swiveling mechanism fastened to a lightweight, two-wheeled carriage.");
    set_two_handed();
    set_weight(18);
    set_size(2);

    set_range(4, 8, 12);
    set_wc(2, 12);
    set_large_wc(2, 12);
    set_critical_hit_multiplier(4);

    set_value(4000);
    set_weapon_speed(1);
    set_property("repairtype", ({ "weaponsmith" }));
}
