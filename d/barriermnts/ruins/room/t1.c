#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l2b";

void create() {
    ::create();
    set_long("%^ORANGE%^You stand at the top of a spiralling stone staircase, leading down out of "
"sight.  It is surrounded by steep walls, that rise to meet the ornate borders edging the roof above, "
"and are covered in dust and the occasional spiderweb. At your feet, %^RED%^dark carpet%^ORANGE%^ "
"cushions your steps upon the tiled floor, leading up from the centre of the stairs and reaching under "
"the doorway before you.  Within the north wall is set a door of a %^RED%^da%^BOLD%^r%^RESET%^%^RED%^k "
"cri%^BOLD%^m%^RESET%^%^RED%^son%^ORANGE%^ hue.  Soft breaths of wind swirl up and down the staircase, ""carrying faint %^CYAN%^whispers%^ORANGE%^ as they brush past you.%^RESET%^\n");
    add_item("stairs","%^ORANGE%^A stone staircase spirals down out of sight, lined with a strip of "
"%^RED%^carpet%^ORANGE%^ down the middle.%^RESET%^");
    add_item("staircase","%^ORANGE%^A stone staircase spirals down out of sight, lined with a strip of "
"%^RED%^carpet%^ORANGE%^ down the middle.%^RESET%^");
    set_exits(([
      "down" : ROOMS+"u7-3",
      "north" : ROOMS+"t2"
    ]));
    set_door("crimson door",ROOMS+"t2","north",0);
    set_door_description("crimson door","%^ORANGE%^The door within the north wall is almost entirely "
"free of dust, unlike the rest of the area. It is of a %^RED%^da%^BOLD%^r%^RESET%^%^RED%^k "
"cri%^BOLD%^m%^RESET%^%^RED%^son%^ORANGE%^ colour, and despite its obvious age, it looks to be in near "
"perfect condition.%^RESET%^");
    set_string("crimson door","open","stuff");
    set_string("crimson door","close","stuff");
}
