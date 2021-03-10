#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l2b";

void create() {
    ::create();
    set_long("%^ORANGE%^This hallway extends to the north and south, bordered by solid stone walls on "
"both sides.  They rise to meet the ornate borders that edge the roof, spanning high above your head and "
"covered in dust and the occasional spiderweb. At your feet, %^RED%^dark carpet%^ORANGE%^ cushions your "
"steps upon the tiled floor.  Within the walls to the east are regularly-spaced windows of "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^ORANGE%^ glass, shedding "
"faint light into the corridor, though their surfaces are %^BLACK%^%^BOLD%^blackened%^RESET%^%^ORANGE%^ "
"with dirt.  Within the west wall is set a door of an %^GREEN%^em%^BOLD%^e%^RESET%^%^GREEN%^rald "
"gre%^BOLD%^e%^RESET%^%^GREEN%^n%^ORANGE%^ hue.  Soft breaths of wind brush along the corridor, carrying "
"faint %^CYAN%^whispers%^ORANGE%^ as they brush past you.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"u5-5",
      "south" : ROOMS+"u3-5",
      "west" : ROOMS+"u4-4"
    ]));
    set_door("green door",ROOMS+"u4-4","west",0);
    set_door_description("green door","%^ORANGE%^The door within the west wall is coated in the "
"same dust as the rest of the hallway, though under the dirt you can see it is a "
"%^GREEN%^em%^BOLD%^e%^RESET%^%^GREEN%^rald gre%^BOLD%^e%^RESET%^%^GREEN%^n%^ORANGE%^ colour.  Despite "
"its obvious age, it looks to be in good condition.%^RESET%^");
    set_string("green door","open","stuff");
    set_string("green door","close","stuff");
}
