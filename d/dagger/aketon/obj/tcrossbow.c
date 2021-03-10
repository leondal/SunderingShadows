#include <std.h>

inherit LRWEAPON;

create() {
    ::create();
   set_id( ({"triple crossbow","crossbow","bow"}) );
   set_name("triple crossbow");
   set_short("A triple crossbow");
   set_long("This is a standard triple crossbow.");
   set_weight(10);
   set_size(2);
   set("value",100);
   set_wc(3,5);
   set_large_wc(3,5);
   set_type("slashing");
   set_rate_of_fire(3);
   set_range(12,17,22);
   set_ammo("tcarrows");
   set_prof_type("cross bow");
}
