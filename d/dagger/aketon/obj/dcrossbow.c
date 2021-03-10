#include <std.h>

inherit LRWEAPON;

create() {
    ::create();
   set_id( ({"double crossbow","crossbow","bow"}) );
   set_name("double crossbow");
   set_short("A double crossbow");
   set_long("This is a standard double crossbow.");
   set_weight(8);
   set_size(2);
   set("value",90);
   set_wc(3,4);
   set_large_wc(3,4);
   set_type("slashing");
   set_rate_of_fire(3);
   set_range(10,15,20);
   set_ammo("dcarrows");
   set_prof_type("cross bow");
}
