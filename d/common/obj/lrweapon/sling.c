#include <std.h>

inherit LRWEAPON;

void create(){
    ::create();
    set_id(({"sling"}));
    set_name("sling");
    set_short("A sling");
    set_long(
        "This sling is improvised from common materials and the craftsmanship"+
        " is very simple. There is a long string with one end tied"+
        " in a loop. In the middle of the string is a little"+
        " pocket to set the bullets. Overall, there is not much to it."
    );
    set_prof_type("staff");
    set_weight(1);
    set_type("bludgeoning");
    set_decay_rate(100);
    set_range(2,7,12);
    set_ammo("bullet");
    set_lr_prof_type("sling");
    set_weapon_prof("simple");
    set_lr_type("bludgeoning");
    set_size(1);
    set_wc(1,4);
    set_large_wc(1,4);
    set_value(3);
    set_rate_of_fire(2);
    set_weapon_speed(2);
    set_damage_type("bludgeoning");
    set_property("repairtype",({"woodwork", "leatherwork"}));
    set_critical_threat_range(1);
    set_critical_hit_multiplier(2);
}

