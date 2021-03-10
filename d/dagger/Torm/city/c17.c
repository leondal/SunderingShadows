#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Northeast Tanar road");
  set_long(
  "Northeast Tanar road.\n"
  "  Tanar road continues along the outer wall of Torm."
  "  You can see southeast the waters of the Dagger sea and where the walls of Torm out in them."
    "  The back of a grand stone building is to the south."
  );
  set("night long",
  "%^BLUE%^"
  "  You can hear the sounds of the waters of the Dagger Sea but the fog"+
  " here tends to obscure things a bit, it would be easier to find it by"+
   " listening to the waves than with your eyes most likely."+
  "  The back of a large stone building is to the south here."
  );
  set_exits(([
  "northwest":TCITY+"c10",
  "southeast":TCITY+"c18",
  ]));
}
