#include <std.h>
inherit LRWEAPON;

create() {
    ::create();
   set_id(({ "shortbow", "bow" }));
   set_name("shortbow");
   set_short("A short bow");
   set_long("This is a standard shortbow. A wooden shaft has been bent and arched, inbetween the two ends a sturdy bit of line has been strung. It is smaller than the longbow, and so easier to handle, but will not shoot as well at far targets.");
   set_weight(2);
   set_size(2);
   set("value", 30);
   set_wc(2,4);
   set_large_wc(2,4);
  set_type("piercing");
   set_two_handed();
   set_lr_prof_type("short bow");
   set_weapon_prof("simple");
   set_prof_type("staff");
   set_rate_of_fire(2);
   set_range(5,10,15);
   set_ammo("shortbow arrow");
   set_decay_rate(100);
   set_property("repairtype",({"woodwork"}));
   set_weapon_speed(3);
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("piercing");
}
