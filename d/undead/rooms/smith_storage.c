#include <std.h>;
#include "../undead.h"
inherit "/d/darkwood/tabor/include/armor_storage";

void create() {
   ::create();
   set_name("Graez smith storage");
   set_short("Graez smith storage");
   set_long("Storage room for Graez's smith.");
   set_property("no teleport",1);

   set_exits(([
     "out":TOWN"smith",
   ]));
}
