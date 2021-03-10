#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l2b";

void create() {
    ::create();
    set_long("%^ORANGE%^This hallway extends to the north and south, bordered by solid stone walls on "
"both sides.  They rise to meet the ornate borders that edge the roof, spanning high above your head and "
"covered in dust and the occasional spiderweb. At your feet, %^RED%^dark carpet%^ORANGE%^ cushions your "
"steps upon the tiled floor.  Within the walls to the west are regularly-spaced windows of "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^ORANGE%^ glass, shedding "
"faint light into the corridor, though their surfaces are %^BLACK%^%^BOLD%^blackened%^RESET%^%^ORANGE%^ "
"with dirt.  Within the east wall is set a door of a "
"%^BLACK%^%^BOLD%^dus%^RESET%^%^WHITE%^k%^BLACK%^%^BOLD%^y "
"gr%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^y%^RESET%^%^ORANGE%^ hue.  Soft breaths of wind brush along the "
"corridor, carrying faint %^CYAN%^whispers%^ORANGE%^ as they brush past you.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"u3-1",
      "south" : ROOMS+"u1-1",
      "east" : ROOMS+"u2-2"
    ]));
    set_door("gray door",ROOMS+"u2-2","east",0);
    set_door_description("gray door","%^ORANGE%^The door within the east wall is coated in the "
"same dust as the rest of the hallway, though under the dirt you can see it is a "
"%^BLACK%^%^BOLD%^dus%^RESET%^%^WHITE%^k%^BLACK%^%^BOLD%^y "
"gr%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^y%^RESET%^%^ORANGE%^ colour.  Despite its obvious age, it looks "
"to be in good condition.%^RESET%^");
    set_string("gray door","open","stuff");
    set_string("gray door","close","stuff");
}
