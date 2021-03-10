#include <std.h>

inherit LRWEAPON;

create() {
    ::create();
   set_id( ({"rosewood crossbow","crossbow","bow"}) );
   set_name("rosewood crossbow");
   set_short("%^MAGENTA%^Rosewood crossbow");
   set_long("%^MAGENTA%^This is an ornate rosewood crossbow. Some runic "
      "tatoo is carved into the grooved support. The bow is covered with "
      "thin silver plating. The thread is made of some strong elastic "
      "material which gives out a tremedous force when released.");
   set_weight(8);
   set_size(2);
   set("value",500);
   set_wc(2,5);
   set_large_wc(3,5);
   set_type("slashing");
   set_rate_of_fire(2);
   set_range(10,15,20);
   set_ammo("rcarrows");
   set_prof_type("cross bow");
   set_property("enchantment",2);
}
