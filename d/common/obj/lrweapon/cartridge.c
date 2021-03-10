#include <std.h>

inherit "/std/ammo";

void create(){
   ::create();
   set_id(({ "cartridges","cartridge" }));
   set_name("cartridge");
   set_short("pouch of cartridges");
   set_long("These are small paper cartridges, with alchemical charge at one end and bullet at the other.");
   set_ammo_type("cartridge");
   set_weight(1);

   set_shots(250);
   set_value(1);
   set_wc(1,4);
   set_large_wc(1,4);
}
