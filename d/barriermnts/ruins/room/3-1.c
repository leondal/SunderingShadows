#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l1a";

void create() {
    ::create();
    set_long("%^ORANGE%^You are standing within an extensive hallway, set with strong pillars at " 
"regular intervals.  The roof reaches high above your head, supported by curved arches from these "
"pillars, decorated ornately but covered in a thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  "
"The floor beneath your feet is perfectly flat, without rubble or upturned stones to impede your "
"progress, though it is coated in still more %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  Tall windows of "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^ORANGE%^ glass are set "
"within the stone walls of the building, but they are %^BLACK%^%^BOLD%^darkened%^RESET%^%^ORANGE%^ with "
"dirt and hard to see through.  A corridor to the south leads away from the main hallway.  It seems very "
"%^BLUE%^lifeless%^ORANGE%^ here, though a heavy feeling rests upon your shoulders, making you feel a "
"little uneasy.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"2-1",
      "south" : ROOMS+"4-1",
      "east" : ROOMS+"3-2"
    ]));
}
