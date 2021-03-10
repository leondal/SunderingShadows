#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"flail", "horsemans flail", "horseman's flail"}));
   set_name("horseman's flail");
   set_short("horseman's flail");
   set_long("This is a small horseman's flail with a long wooden handle and 4 iron balls attached by chain to the end.");
   set_size(1);
   set_weight(6);
   set_value(5);
   set_type("bludgeoning");
   set_prof_type("flail");
   set_weapon_speed(6);
   set_wc(1,5);
   set_large_wc(1,5);
}

