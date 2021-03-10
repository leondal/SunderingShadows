#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l2c";

void create() {
    ::create();
    set_long("%^ORANGE%^This enclosed room must have once provided the living space for several people.  "
"It is decorated entirely in shades of %^BLUE%^bl%^BOLD%^u%^RESET%^%^BLUE%^e%^ORANGE%^, with the "
"exception of the %^RED%^dark carpet%^ORANGE%^ beneath your feet.  The furniture is quite simple, though "
"strangely enough it all seems relatively undamaged by age, despite the thick layer of dust upon "
"everything in sight.  Several simple beds are spaced evenly against the back wall, and a single "
"cupboard and desk stand a little way apart across the room.  The stone walls here are much the same as "
"the rest of the building, bordered ornately where they meet the high roof, and covered in dust and the "
"occasional spiderweb.  Within the wall to the east is a door of a "
"%^BLUE%^co%^BOLD%^b%^RESET%^%^BLUE%^alt bl%^BOLD%^u%^RESET%^%^BLUE%^e%^ORANGE%^ hue.  Soft breaths of "
"wind brush along the walls, carrying faint %^CYAN%^whispers%^ORANGE%^ as they brush past "
"you.%^RESET%^\n");
    set_exits(([
      "east" : ROOMS+"u5-5"
    ]));
    set_door("blue door",ROOMS+"u5-5","east",0);
    set_door_description("blue door","%^ORANGE%^The door within the east wall is coated in the "
"same dust as the rest of the room, though under the dirt you can see it is a "
"%^BLUE%^co%^BOLD%^b%^RESET%^%^BLUE%^alt bl%^BOLD%^u%^RESET%^%^BLUE%^e%^ORANGE%^ colour.  Despite "
"its obvious age, it looks to be in good condition.%^RESET%^");
    set_string("blue door","open","stuff");
    set_string("blue door","close","stuff");
}
