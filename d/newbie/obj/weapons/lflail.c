#include <std.h>

inherit WEAPON;

void create(){
   ::create();
   set_id(({"flail", "spiked flail"}));
   set_name("spiked flail");
   set_short("spiked flail");
   set_long("This is a large flail with spiked balls of iron swinging on heavy chains.");
   set_size(3);
   set_weight(10);
   set_value(5);
   set_type("bludgeoning");
   set_prof_type("flail");
   set_weapon_speed(6);
   set_wc(1,5);
   set_large_wc(1,5);
}

