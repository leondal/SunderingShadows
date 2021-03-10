#include "../../undead.h"
inherit VAULT;

void create() {
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
    set_name("Bayside Inn");
    set_short("%^BOLD%^%^WHITE%^Bayside Inn%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Bayside Inn%^RESET%^\n"
"This small room is big enough for perhaps two people to stay in, but no "
"more than that.  It is simple and lacks excess furnishings, with only a "
"%^CYAN%^quilt-covered %^RESET%^bed and a little table beside it.  A small "
"circular window sheds a ray of %^YELLOW%^light %^RESET%^into the room, "
"bordered by linen curtains that could be pulled across to darken the area.  "
"Small though the room may be, it is clean and feels %^RED%^warm and "
"cosy.%^RESET%^\n");
    set_smell("default","The odor of cooking food drifts up from below.");
    set_listen("default","You can hear the distant sound of plates clanging.");

    set_exits(([
      "west":TOWN"inn2",
    ]));

    set_door("dolphin door",TOWN"inn2","west",0);
    set_door_description("dolphin door","%^RESET%^The door is made of the same "
"slats as the building, unremarkable in appearance except for a "
"%^BOLD%^%^BLUE%^carved dolphin %^RESET%^in the centre of the wood.");
}
