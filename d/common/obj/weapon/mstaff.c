#include <std.h>

inherit "/std/weapon";

create() {
    ::create();
    set_id(({ "staff", "wooden staff", "medium wooden staff", "mstaff", "medium staff" }));
    set_name("staff");
    set_short("A medium wooden staff");
    set_long(
        "This is a sturdy wooden staff about three feet long.  It has bands of "
        "metal tightened around the far end and along its length to afford it "
        "more support.  This one is small enough to be wielded in one hand by "
        "human size races or be used like a quarter staff for the smaller ones."
    );
    set_wc(1,4);
    set_large_wc(1,4);
    set_weight(3);
    set_size(2);
    set("value", 2);
    set_type("bludgeoning");
    set_prof_type("staff");
    set_weapon_speed(3);
    set_weapon_prof("simple");
    set_property("repairtype",({"woodwork"}));
    set_critical_threat_range(1);
    set_critical_hit_multiplier(2);
    set_damage_type("bludgeoning");
    set_property("double weapon", 1);
}
