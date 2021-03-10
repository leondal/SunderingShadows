#include <std.h>

inherit WEAPON;

create()
{
    ::create();
    set_id(({ "polearm" }));
    set_name("polearm");
    set_short("A slashing polearm");
    set_long("This is a slashing polearm.");
    set_weight(8);
    set_size(3);
    set("value", 5);
    set_wc(3, 4);
    set_large_wc(3, 4);
    set_type("slash");
    set_prof_type("polearm");
    set_weapon_prof("martial");
    set_weapon_speed(10);
    set_critical_threat_range(1);
    set_critical_hit_multiplier(3);
    set_damage_type("slashing");
    set_property("repairtype", ({ "weaponsmith" }));
}
