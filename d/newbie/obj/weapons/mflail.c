#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"flail", "iron flail"}));
   set_name("iron flail");
   set_short("iron flail");
   set_long("This is a flail with a two-foot-long wooden handle and a free-swinging piece of iron attached to the end.");
   set_size(2);
   set_weight(8);
   set_value(5);
   set_type("bludgeoning");
   set_prof_type("flail");
   set_weapon_speed(6);
   set_wc(1,5);
   set_large_wc(1,5);
}

