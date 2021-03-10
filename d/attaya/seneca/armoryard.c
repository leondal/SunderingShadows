#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
   set_short("Armor shop.");
   set_property("indoors",0);
   set_property("light",3);
   set_long(
@DESC
You are just outside the %^CYAN%^Seneca Armor Shop%^RESET%^. Scrap metal and 
hulks of rusty discarded armor lie in piles against the 
building. A large brick path that rises in steps that are 
edged with logs leads up to the door. Thick black smoke rises 
from the smokestack from the smelting furnace beside the 
building.
DESC
   );
   set_exits(([
      "enter" : "/d/attaya/seneca/armorshop",
      "north" : "/d/attaya/seneca/street6",
   ]));
   set_door("door", "/d/attaya/seneca/armorshop", "enter", 0);
   set_open("door", 0);
   set_items(([
      "path" : "The path is built from large stone bricks.  It rises in small steps and logs edge them to protect the stones from chipping.",
      "grass" : "The healthy green grass has been recently cut.",
      "piles" : "Large piles of scrap await resmelting into new armor",
      "armor" : "Most of it is the rusted fragments of old armor.  Most likely dug up by graverobbers from the tombs of buried soldiers and sold here as scrap for a few gold.",
      "furnace" : "An old smelting furnace runs constantly as metals are heated untiil molten and maleable for use in armor construction.",
   ]));
}
