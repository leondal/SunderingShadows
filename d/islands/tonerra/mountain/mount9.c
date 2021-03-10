#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit "/d/islands/tonerra/mountain.c";

void create(){
   ::create();
   set_light(2);
   set_indoors(0);
   set_listen("default","The slight breeze stirs the small plants.");
   set_smell("default","The land has a charred smell about it.");
   set_exits(([
      "southwest":MOUNTAIN+"mount8",
      "southeast":MOUNTAIN+"mount54",
      "northeast":MOUNTAIN+"mount10"
   ]));
}
