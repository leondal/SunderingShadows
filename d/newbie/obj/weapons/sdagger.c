#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"dagger", "copper dagger"}));
   set_name("copper dagger");
   set_short("copper dagger");
   set_long("This is a short-bladed copper dagger.");
   set_size(1);
   set_weight(1);
   set_value(3);
   set_type("piercing");
   set_prof_type("small blades");
   set_weapon_speed(2);
   set_wc(1,4);
   set_large_wc(1,3);
}

