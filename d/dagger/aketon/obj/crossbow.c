#include <std.h>

inherit LRWEAPON;

create() {
    ::create();
   set_id( ({"crossbow","bow"}) );
   set_name("crossbow");
   set_short("A crossbow");
   set_long("This is a standard crossbow.");
   set_weight(5);
   set_size(2);
   set("value",80);
   set_wc(3,3);
   set_large_wc(3,3);
   set_type("slashing");
   set_rate_of_fire(2);
   set_range(8,13,18);
   set_ammo("carrows");
   set_prof_type("cross bow");
}
