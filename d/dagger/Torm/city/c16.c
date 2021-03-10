#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(BACK_ALLEY);
  set_short("Back alley");
  set_long(
  "Back alley.\n"
  "  This alley cuts behind a few houses and beside a walled compound south towards the sounds of the waterfront."
    "  It's remarkably clean for a back alley even in this section of Torm."
   "  Southwest of here is a large stone structure that appears to hold the symbol of a general store."
  );
  set("night long",
  "%^BLUE%^"
  "  This dark alley seems quite dangerous and you wonder why you decided to travel down it instead of sticking to the empty fog filled main roads."
  "  You can barely make out the walls of a compound to the west and the backs of houses to the east."
  );
  set_exits(([
  "north":TCITY+"c10",
  "south":TCITY+"c27",
  ]));
}
