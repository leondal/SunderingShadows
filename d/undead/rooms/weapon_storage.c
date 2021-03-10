#include <std.h>;
#include "../undead.h"
inherit "/d/darkwood/tabor/include/weapon_storage";

void create() {
   ::create();
   set_name("Graez weaponsmith storage");
   set_short("Graez weaponsmith storage");
   set_long("Storage room for Graez's weaponsmith.");
   set_property("no teleport",1);

   set_exits(([
     "out":TOWN"weapons",
   ]));
}
