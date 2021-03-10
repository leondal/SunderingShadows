#include <std.h>
#include "../tormdefs.h"
inherit whatever;

void create()   {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
  set_short("Northeast corner of Torm");
  set_long(
  "Northeast corner of Torm.\n"
    "This section of Torm seems to be getting a facelift.  "
    "A walled compound's gates are to the southwest from here.  You can see "
    "the gates standing open as if inviting visitors and the grounds are "
    "clearly well kept.  North Tanar road continues west and southeast.  "
  "A dark alley leads south and a set of stairs leads up to the walls of Torm."
  );
  set("night long",
  "%^BLUE%^"
  "The entire city seems to be covered in a light fog."
    "  A walled compound's gates are to the southwest and %^YELLOW%^light seems "
    "to beckon %^RESET%^%^BLUE%^an invitation to passersby."
    "  Stairs lead up to the top of Torm's walls and roads lead off west, southeast, and south."
  );
  set_exits(([
  "up":TCITY+"c19",
  "west":TCITY+"c9",
  "south":TCITY+"c16",
  "southwest":TCITY+"c98",
  "southeast":TCITY+"c17",
  ]));
}
