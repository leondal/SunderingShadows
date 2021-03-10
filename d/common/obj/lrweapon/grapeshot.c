#include <std.h>

inherit "/std/ammo";

void create(){
   ::create();
   set_id(({ "grapeshots","grapeshot" }));
   set_name("grapeshot");
   set_short("pouch of grapeshot cartridges");
   set_long("These are small paper cartridges, with alchemical charge at one end and grapeshot balls at the other.");
   set_weight(1);
   set_ammo_type("grapeshot");

   set_shots(250);
   set_value(1);
   set_wc(1,4);
   set_large_wc(1,4);
}
