//updated base damage - Circe 5/7/04
#include <std.h>

inherit WEAPON;

void create(){
    ::create();
    set_name("nunchucks");
    set_id(({"nunchucks","nunchuck"}));
    set_short("Nunchucks");
    set_long("This is a two wooden sticks bound together by chain.");
    set_weight(7);
    set_value(10);
    set_wc(2,4);
    set_large_wc(2,4);
    set_size(2);
    set_type("bludgeoning");
    set_prof_type("club");
    set_weapon_speed(4);
    set_property("repairtype",({"woodwork"}));    
    set_weapon_prof("exotic");
    set_critical_threat_range(2);
    set_critical_hit_multiplier(3);
    set_damage_type("bludgeoning");
}

