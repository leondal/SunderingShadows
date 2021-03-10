//  Created by Ignatius, for ShadowGate
//  Coded 05 March, 1995
//  Weapon for Charu Mountain Dwarves

#include <std.h>
#include "/d/antioch/areadefs.h"
inherit "/std/weapon";

create() {
    ::create();
   set_id(({ "sword", "short sword", "a short sword", "short" }));
   set_name("short sword");
   set_short("A short sword");
   set_long(
	"This is a shiny, well kept short sword. "
   );
   set_weight(3);
   set_size(1);
   set_wc(1,6);
   set_large_wc(1,8);
   set_value(10);
  set_type("slashing");
}
