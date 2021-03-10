#include <std.h>
#include "../tormdefs.h"
inherit whatever;

void create()   {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Tanar on the Dagger Sea");
  set_long( "Tanar on the Dagger Sea.\n"
    "  Tanar runs along the Dagger Sea coast here where it comes right up to the rocks the city is built on.  Stonework has enclosed what was once an alley and empty lot to the north."
  "  Tanar continues west towards the center of the city and east to a large ampitheatre, where it curves north to the walls."
    "  You can see south across the great harbor and all the docks and boardwalks seem active.  There is definitely money in the air."
  );
  set("night long",
  "  Tanar Road is covered in a light fog, making it a bit difficult"+
  " to tell exactly where you're going.  The Dagger Sea is to the south,"+
  " but you can hear it much easier than you can see it right now.  The"+
  " air is a little bit cold, and the fog doesn't help."
  );
  set_exits(([
//  "north":TCITY+"c26",  converting c26 to part of Girruuth's shop
  "east":TCITY+"c37",
  "west":TCITY+"c35",
/*  "northeast":TCITY+"c27",   didn't make sense mapped - Styx 12/26/01 */
  ]));
}
