#include <std.h>
inherit FIREARM;

create()
{
    ::create();
    set_id(({ "culverin", "gun" }));
    set_name("culverin");
    set_short("A culverin");
    set_ammo("grapeshot");

    set_long("The culverin, also known as a hand bombard, consists of a simple smoothbore tube, sealed at one end except for a small hole used to ignite a gunpowder charge.");
    set_two_handed();
    set_weight(40);
    set_size(2);

    set_wc(2, 8);
    set_large_wc(2, 8);
    set_critical_hit_multiplier(4);

    set_value(4000);
    set_weapon_speed(1);
    set_property("repairtype", ({ "weaponsmith" }));
}
