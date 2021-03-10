#include <std.h>
#include "../tharis.h"
inherit STORAGE"shar_path";

void create(){
   ::create();
   set_long(::query_long()+"%^CYAN%^The path ends here, at the "+
      "sheer rock wall broken by the yawning entrance to a "+
      "cavern.\n");
   add_item("cavern","The cavern entrance stands about six "+
      "feet wide and eight feet high.  It leads into darkness, "+
      "allowing you to see very little.  It is the only opening "+
      "into the rock wall in sight.");
   set_exits(([
      "northeast" : MOUNTAIN"spath3",
      "enter" : "/d/magic/temples/shar_tunnel5"
   ]));
}
