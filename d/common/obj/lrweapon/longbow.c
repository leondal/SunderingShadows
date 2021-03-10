#include <std.h>
inherit LRWEAPON;

create() {
    ::create();
   set_id(({ "long bow","longbow", "bow" }));
   set_name("longbow");
   set_short("A long bow");
   set_long("This is a standard long bow. It has a wooden shaft that is bent and arched.  In between, a sturdy bit of line has been strung. It is large and sometimes awkward to handle and requires more physical strength to pull, but it has a longer range than a short bow.");
   set_weight(2);
   set_size(3);
   set("value", 60);
   set_prof_type("staff");
   set_lr_prof_type("long bow");
   set_weapon_prof("martial");
   set_two_handed();
   set_wc(2,6);
   set_large_wc(2,6);
   set_type("piercing");
   set_rate_of_fire(2);
   set_range(7,15,21);
   set_ammo("longbow arrow");
   set_decay_rate(100);
   set_property("repairtype",({"woodwork"}));
   set_weapon_speed(4);
   set_critical_threat_range(1);
   set_critical_hit_multiplier(3);
   set_damage_type("piercing");
}
