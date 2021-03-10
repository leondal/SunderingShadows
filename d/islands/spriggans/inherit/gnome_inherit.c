#include <std.h>
#include "../spriggan.h"

inherit ROOM;

void create(){
   ::create();
   set_name("streets of drearuntain");
   set_short("The Streets of Drearuntain");
   set_long("This will be the town of Drearuntain, run by gnomes.");
   set_light(2);
   set_indoors(0);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_items(([
      "stuff" : "There will be stuff to look at."
   ]));
   set_smell("default","The chalky dust of the cliffs mingles with the sea air.");
   set_listen("default","You occasionally hear rubble scatter down the cliff face.");
}