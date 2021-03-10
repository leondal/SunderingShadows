#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"club", "heavy club"}));
   set_name("heavy club");
   set_short("heavy club");
   set_long("This is a large piece of wood which has had the edges trimmed and rounded a bit.");
   set_size(3);
   set_weight(7);
   set_value(5);
   set_type("bludgeoning");
   set_prof_type("large clublike");
   set_weapon_speed(4);
   set_wc(1,6);
   set_large_wc(1,3);
}

