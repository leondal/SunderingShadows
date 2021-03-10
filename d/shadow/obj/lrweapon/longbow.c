#include <std.h>
inherit LRWEAPON;

create() {
    ::create();
   set_id(({ "long bow","longbow", "bow" }));
   set_name("longbow");
   set_short("A long bow");
   set_long("This is a standard long bow. It has a wooden shaft that is bent and arched, inbetween which a sturdy bit of line has been strung. It is large and sometimes akward to handle, but it has a long range.");
   set_weight(2);
   set_size(3);
   set("value", 60);
   set_prof_type("staff");
   set_lr_prof_type("long bow");
   set_two_handed();
   set_wc(1,8);
   set_large_wc(1,8);
   set_type("bludgeoning");
   set_rate_of_fire(2);
   set_range(7,15,21);
   set_ammo("longbow arrow");
   set_decay_rate(100);
   set_lr_type("piercing");
}
