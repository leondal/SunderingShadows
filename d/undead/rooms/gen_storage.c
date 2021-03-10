#include <std.h>;
#include "../undead.h"
inherit "/d/darkwood/tabor/include/gstorage";

void create() {
   ::create();
   set_name("Graez general storage");
   set_short("Graez general storage");
   set_long("Storage room for Graez's general store.");
   set_property("no teleport",1);

   set_exits(([
     "out":TOWN"general",
   ]));
}
