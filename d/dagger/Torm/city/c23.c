#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_short("Outside Torm's magic shop");
  set_door("door",TCITY+"c31","south","masterkey");
  set_long(
  "Outside Torm's magic shop.\n"
    "  Just south of you is Torm's magic shop."
    "  You can smell the reagents and components wafting out through the open door and it feels more welcoming than most of the shops of this kind that you've seen."
    "  North you can see the walls of a compound and just barely the spires of the mansion behind them."
  );
    set("night long",
  "%^BLUE%^"
  "A light fog has settled over the city, making it a little hard to"+
  " see where you're going at night.  The magic shop to the south"+
  " appears closed, although there is a faint light on within.  If it"+
  " were an emergency you could probably go in and ask for something,"+
  " but you might get charged more than normal." 
  );
   add_item("building","The building to the south here not only has the sign of a mage's shop, you can smell the numerous reagents drifting out of it.");
  set_exits(([
  "west":TCITY+"c22",
  "east":TCITY+"c24",
  "south":TCITY+"c31",
  ]));
}
