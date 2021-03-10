
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;

void create(){
      ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(PAVED_ROAD);
set_property("light", 1);
      set_name("Cobbled Path");
      set_short("%^CYAN%^Cobbled Path");
      set_long(
	     "%^CYAN%^You are on a cobbled path which winds through the woods.  "
	     "You think you can see the towers of a castle above the treetops ahead.  "
      );
      set_listen("default",
        "You hear a few birds in the trees and the breeze blowing through the trees."
      );
      set_smell("default",
        "You smell the fresh scent of the woods!"
      );
      set_items(([
        "path":"The cobbled path winds between the trees.",
        ({"woods","trees"}):"The trees sway gently in the mild breeze",
       ]));
      set_exits(([
         "southwest": RPATH "path3",
         "north": RPATH "path1"
       ]));
}
