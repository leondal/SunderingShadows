#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"club", "small club"}));
   set_name("small club");
   set_short("small club");
   set_long("This is a small piece of wood fashioned into a club.");
   set_size(1);
   set_weight(3);
   set_value(5);
   set_type("bludgeoning");
   set_prof_type("small clublike");
   set_weapon_speed(4);
   set_wc(1,6);
   set_large_wc(1,3);
}

