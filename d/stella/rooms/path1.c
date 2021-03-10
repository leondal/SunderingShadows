
#include <std.h>

#include "/d/stella/short.h"

inherit ROOM;

void reset(){
        ::reset();
	if (!present("old man")) new(MPATH "oldman")->move(TO);
	}

void create(){
      ::create();
   set_travel(PAVED_ROAD);
   set_terrain(LIGHT_FOREST);
set_property("light", 1);
      set_name("Cobbled Path");
      set_short("%^CYAN%^Cobbled Path");
      set_long(
	     "%^CYAN%^You are on a cobbled path which winds through the woods.  "
	     "You think you can see the towers of a castle above the treetops ahead.  "
	     "You've reached the castle.  Ahead you see an archway leading into the "
	     "castle gardens.  "
      );
      set_listen("default",
        "You hear a few birds in the trees and the breeze blowing through the trees."
      );
      set_smell("default",
        "You smell the fresh scent of the woods!"
      );
      set_items(([
        ({"castle","marble castle"}):"You can see the outer wall of the castle.  ",
        "wall":"The wall is made entirely out of large blocks of rose and grey marble.  It "
           "is somehow both beautiful and intimidating at the same time.  That castle was built "
           "for strength as well as beauty.",
        "path":"The cobbled path winds between the trees.",
        ({"woods","trees"}):"The trees sway gently in the mild breeze",
	"archway":"The archway is tall and wide. There's an old man sitting just to the outside "
	   "of the castle grounds.  "
       ]));
      set_exits(([
         "south": RPATH "path2",
         "archway": RPATH "garden1"
       ]));
}
