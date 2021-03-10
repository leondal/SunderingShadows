#include <std.h>
#include "../spriggan.h"

inherit ROOM;

void create(){
   ::create();
   set_name("a rocky red cliff");
   set_short("A Rocky Red Cliff");
   set_long("This will be the rocky red cliff description.");
   set_light(2);
   set_indoors(0);
   set_terrain(ROCKY);
   set_travel(RUBBLE);
   set_items(([
      "stuff" : "There will be stuff to look at."
   ]));
   set_smell("default","The chalky dust of the cliffs mingles with the sea air.");
   set_listen("default","You occasionally hear rubble scatter down the cliff face.");
}