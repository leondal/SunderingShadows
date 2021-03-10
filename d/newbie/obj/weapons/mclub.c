#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"club", "chair club"}));
   set_name("club");
   set_short("club");
   set_long("This is a club that looks like it might have once been part of a strong chair.");
   set_size(2);
   set_weight(5);
   set_value(5);
   set_type("bludgeoning");
   set_prof_type("medium clublike");
   set_weapon_speed(4);
   set_wc(1,6);
   set_large_wc(1,3);
}

