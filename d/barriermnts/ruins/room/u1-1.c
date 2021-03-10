#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l2a";

void create() {
    set_monsters(({MON+"cultspirit"}),({1}));
    ::create();
    set_repop(30);
    set_long("%^ORANGE%^This hallway extends to the east and north, bordered by solid stone walls on "
"both sides.  They rise to meet the ornate borders that edge the roof, spanning high above your head and "
"covered in dust and the occasional spiderweb. At your feet, %^RED%^dark carpet%^ORANGE%^ cushions your "
"steps upon the tiled floor.  Within the walls to the south and west are regularly-spaced windows of "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^ORANGE%^ glass, shedding "
"faint light into the corridor, though their surfaces are %^BLACK%^%^BOLD%^blackened%^RESET%^%^ORANGE%^ "
"with dirt.  Soft breaths of wind brush along the corridor, carrying faint %^CYAN%^whispers%^ORANGE%^ as "
"they brush past you.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"u2-1",
      "east" : ROOMS+"u1-2",
    ]));
}
