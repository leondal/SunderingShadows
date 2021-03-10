#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"dagger", "steel dagger"}));
   set_name("steel dagger");
   set_short("steel dagger");
   set_long("This is a dagger with a steel blade about 18 inches long.");
   set_size(1);
   set_weight(3);
   set_value(3);
   set_type("piercing");
   set_prof_type("small blades");
   set_weapon_speed(2);
   set_wc(1,4);
   set_large_wc(1,3);
}

