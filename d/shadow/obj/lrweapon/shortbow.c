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
   set_wc(1,6);
   set_large_wc(1,6);
  set_type("bludgeoning");
   set_two_handed();
  set_lr_prof_type("short bow");
   set_prof_type("staff");
   set_rate_of_fire(2);
   set_range(5,10,15);
   set_ammo("shortbow arrow");
   set_decay_rate(100);
     set_lr_type("piercing");
}
