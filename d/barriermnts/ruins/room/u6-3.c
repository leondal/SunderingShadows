#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l2b";

void create() {
    ::create();
    set_long("%^ORANGE%^This hallway extends to the east and west, bordered by solid stone walls on "
"both sides.  They rise to meet the ornate borders that edge the roof, spanning high above your head and "
"covered in dust and the occasional spiderweb. At your feet, %^RED%^dark carpet%^ORANGE%^ cushions your "
"steps upon the tiled floor.  Within the wall to the south is a door of a "
"%^MAGENTA%^de%^BOLD%^e%^RESET%^%^MAGENTA%^p vi%^BOLD%^o%^RESET%^%^MAGENTA%^let%^ORANGE%^ hue, while to "
"the north, you can see a stairwell leading up out of sight.  Soft breaths of wind brush along the "
"corridor, carrying faint %^CYAN%^whispers%^ORANGE%^ as they brush past you.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"u7-3",
      "south" : ROOMS+"u5-3",
      "east" : ROOMS+"u6-4",
      "west" : ROOMS+"u6-2"
    ]));
    set_door("violet door",ROOMS+"u5-3","south",0);
    set_door_description("violet door","%^ORANGE%^The door within the south wall is coated in the "
"same dust as the rest of the hallway, though under the dirt you can see it is a "
"%^MAGENTA%^de%^BOLD%^e%^RESET%^%^MAGENTA%^p vi%^BOLD%^o%^RESET%^%^MAGENTA%^let%^ORANGE%^ colour.  "
"Despite its obvious age, it looks to be in good condition.%^RESET%^");
    set_string("violet door","open","stuff");
    set_string("violet door","close","stuff");
}
