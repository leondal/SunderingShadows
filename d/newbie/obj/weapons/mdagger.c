#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"dagger", "silver dagger"}));
   set_name("silver dagger");
   set_short("silver dagger");
   set_long("This is a silver dagger with a leather thong wrapped around the hilt to give a better grip.");
   set_size(1);
   set_weight(2);
   set_value(3);
   set_type("piercing");
   set_prof_type("small blades");
   set_weapon_speed(2);
   set_wc(1,4);
   set_large_wc(1,3);
}

