#include <std.h>

inherit "/std/ammo";

void create(){
   ::create();
   set_id(({ "cannonballs","cannonball" }));
   set_name("cannonball");
   set_short("sack of cannonballs");
   set_long("These are cannonballs.");
   set_ammo_type("cannonball");

   set_shots(20);
   set_value(1);
   set_wc(1,8);
   set_large_wc(1,8);
}
