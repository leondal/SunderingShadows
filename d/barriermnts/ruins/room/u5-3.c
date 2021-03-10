#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l2c";

void create() {
    ::create();
    set_long("%^ORANGE%^This enclosed room must have once provided the living space for several people.  "
"It is decorated entirely in shades of %^MAGENTA%^vi%^BOLD%^o%^RESET%^%^MAGENTA%^let%^ORANGE%^, with the "
"exception of the %^RED%^dark carpet%^ORANGE%^ beneath your feet.  The furniture is very plain, though "
"strangely enough it all seems relatively undamaged by age, despite the thick layer of dust upon "
"everything in sight.  A single tall cupboard stands alone against a side wall, near a few simple beds "
"and a short violet-tinted desk.  The stone walls here are much the same as the rest of the building, "
"bordered ornately where they meet the high roof, and covered in dust and the occasional spiderweb.  "
"Within the wall to the north is a door of a %^MAGENTA%^de%^BOLD%^e%^RESET%^%^MAGENTA%^p "
"vi%^BOLD%^o%^RESET%^%^MAGENTA%^let%^ORANGE%^ hue.  Soft breaths of wind brush along the walls, carrying "
"faint %^CYAN%^whispers%^ORANGE%^ as they brush past you.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"u6-3"
    ]));
    set_door("violet door",ROOMS+"u6-3","north",0);
    set_door_description("violet door","%^ORANGE%^The door within the north wall is coated in the "
"same dust as the rest of the room, though under the dirt you can see it is a "
"%^MAGENTA%^de%^BOLD%^e%^RESET%^%^MAGENTA%^p vi%^BOLD%^o%^RESET%^%^MAGENTA%^let%^ORANGE%^ colour.  "
"Despite its obvious age, it looks to be in good condition.%^RESET%^");
    set_string("violet door","open","stuff");
    set_string("violet door","close","stuff");
}
