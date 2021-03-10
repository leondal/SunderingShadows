#include <std.h>
inherit FIREARM;

create()
{
    ::create();
    set_id(({ "arquebus", "gun" }));
    set_name("arquebus");
    set_short("An arquebus");
    set_ammo("cartridge");

    set_long("This is an arquebus, primitive firearm with flintlock mechanism that fires paper cartridges.");
    set_two_handed();
    set_weight(8);
    set_size(2);

    set_wc(1, 8);
    set_large_wc(1, 8);
    set_critical_hit_multiplier(4);

    set_value(1500);
    set_weapon_speed(1);
    set_property("repairtype", ({ "weaponsmith" }));
}
