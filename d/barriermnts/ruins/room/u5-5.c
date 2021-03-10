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
"with dirt.  Within the west wall is set a door of a %^BLUE%^co%^BOLD%^b%^RESET%^%^BLUE%^alt "
"bl%^BOLD%^u%^RESET%^%^BLUE%^e%^ORANGE%^ hue.  Soft breaths of wind brush along the corridor, carrying "
"faint %^CYAN%^whispers%^ORANGE%^ as they brush past you.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"u6-5",
      "south" : ROOMS+"u4-5",
      "west" : ROOMS+"u5-4"
    ]));
    set_door("blue door",ROOMS+"u5-4","west",0);
    set_door_description("blue door","%^ORANGE%^The door within the west wall is coated in the "
"same dust as the rest of the hallway, though under the dirt you can see it is a "
"%^BLUE%^co%^BOLD%^b%^RESET%^%^BLUE%^alt bl%^BOLD%^u%^RESET%^%^BLUE%^e%^ORANGE%^ colour.  Despite "
"its obvious age, it looks to be in good condition.%^RESET%^");
    set_string("blue door","open","stuff");
    set_string("blue door","close","stuff");
}
