#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l2c";

void create() {
    ::create();
    set_long("%^ORANGE%^This enclosed room must have once provided the living space for several people.  "
"It is decorated entirely in shades of am%^BOLD%^b%^RESET%^%^ORANGE%^er, with the exception of the "
"%^RED%^dark carpet%^ORANGE%^ beneath your feet.  The furniture is very plain, though strangely enough "
"it all seems relatively undamaged by age, despite the thick layer of dust upon everything in sight.  A "
"single tall cupboard stands alone against a side wall, near a few simple beds and a short honey-hued "
"desk.  The stone walls here are much the same as the rest of the building, bordered ornately where "
"they meet the high roof, and covered in dust and the occasional spiderweb.  Within the wall to the west "
"is a door of a pale am%^BOLD%^b%^RESET%^%^ORANGE%^er hue.  Soft breaths of wind brush along the walls, "
"carrying faint %^CYAN%^whispers%^ORANGE%^ as they brush past you.%^RESET%^\n");
    set_exits(([
      "west" : ROOMS+"u3-1"
    ]));
    set_door("amber door",ROOMS+"u3-1","west",0);
    set_door_description("amber door","%^ORANGE%^The door within the west wall is coated in the "
"same dust as the rest of the room, though under the dirt you can see it is a pale "
"am%^BOLD%^b%^RESET%^%^ORANGE%^er colour.  Despite its obvious age, it looks to be in good "
"condition.%^RESET%^");
    set_string("amber door","open","stuff");
    set_string("amber door","close","stuff");
}
