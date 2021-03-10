#include <std.h>
#include "../spriggan.h"

inherit ROOM;

void create(){
   ::create();
   set_name("chalky red caverns");
   set_short("Chalky Red Caverns");
   set_long("This will be the caverns winding beneath the red cliffs.");
   set_light(0);
   set_indoors(1);
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_items(([
      "stuff" : "There will be stuff to look at."
   ]));
   set_smell("default","The chalky dust of the caverns is almost overwhelming.");
   set_listen("default","Every sound echoes throughout the cavern.");
}