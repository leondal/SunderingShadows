#include <std.h>

inherit "/std/weapon";

create() {
    ::create();
    set_id(({ "staff", "wooden staff", "small wooden staff", "sstaff", "small staff" }));
    set_name("staff");
    set_short("A short wooden staff");
    set_long(
        "This is a short, solid wooden staff less than two feet long.  It has "
        "little bands of metal tightened around each end to afford it more "
        "support.  This one is so small that it could be wielded in one hand "
        "by a child, or any of the smaller races."
    );
    set_wc(1,4);
    set_large_wc(1,4);
    set_weight(2);
    set_size(1);
    set("value", 2);
    set_type("bludgeoning");
    set_prof_type("staff");
    set_weapon_speed(2);
    set_weapon_prof("simple");
    set_property("repairtype",({"woodwork"}));
    set_critical_threat_range(2);
    set_critical_hit_multiplier(2);
    set_damage_type("bludgeoning");
}
