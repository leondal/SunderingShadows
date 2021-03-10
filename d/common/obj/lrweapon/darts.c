#include <std.h>

inherit LRWEAPON;

void create(){
    ::create();
    set_id(({"darts"}));
    set_name("darts");
    set_short("A stack of darts");
    set_long(
        "This is a stack of heavy throwing darts."
        );
    set_prof_type("staff");
    set_weight(2);
    set_type("piercing");
    set_decay_rate(100);
    set_range(2,4,8);
    set_ammo("darts");
    set_lr_prof_type("sling");
    set_weapon_prof("simple");
    set_lr_type("piercing");
    set_size(1);
    set_wc(1,4);
    set_large_wc(1,4);
    set_value(3);
    set_rate_of_fire(2);
    set_weapon_speed(2);
    set_property("repairtype",({"woodwork", "weaponsmith"}));
}
