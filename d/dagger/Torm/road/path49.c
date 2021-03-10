#include <std.h>
#include "/d/dagger/Torm/tormdefs.h"
inherit ROOM;

void create() {
   ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
   set_light(2);
   set_short("Rocky outcropping on the Dagger Sea");
   set_long("%^CYAN%^The waters of the Dagger Sea surround this "
      "outcropping, and the city of Torm seems further away than it "
      "is. In fact, all the land seems to be dwarfed by the enormity "
      "of the ocean and the temple on the promontory to the southeast, "
      "though the rocks under your feet seem solid enough.%^RESET%^\n");
   set_items(([
      ({"torm","Torm"}) : "The walls of the city are barely visible far in the "
         "distance, dwarfed by the wide sea and the imposing walls of the temple.",
      ({"promontory","temple"}) : "To the southeast, the pathway ends in a "
         "promontory supporting an enormous temple made of pale stone walls "
         "that tower over the outcropping."
   ]));
   set_exits(([
      "northwest":ROAD+"path48",
      "southeast":ROAD+"path50"
   ]));
   set_listen("default","The area is rather serene with only the sound of waves and occasional seabirds.");
   set_smell("default","The air here is crisp and clean, carrying a hint of salt.");
}
