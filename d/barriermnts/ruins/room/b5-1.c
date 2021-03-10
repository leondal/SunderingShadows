#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l0";

void create() {
    ::create();
    set_long("%^BLUE%^The corridor widens here, leading off to the east into darkness, and narrowing to "
"the north.  The roof reaches high above your head, barely visible within the "
"%^BLACK%^%^BOLD%^shadows%^RESET%^%^BLUE%^ that seem almost alive with movement.  Stone walls surround "
"you on either side, blackened with %^BLACK%^%^BOLD%^shadows%^RESET%^%^BLUE%^ and "
"%^ORANGE%^grime%^BLUE%^.  The floor beneath your feet feels perfectly flat, without rubble or upturned "
"stones to impede your progress, but a thick layer of %^WHITE%^foggy mist%^BLUE%^ around your feet makes "
"it impossible to see, and brushes a %^CYAN%^%^BOLD%^chill%^RESET%^%^BLUE%^ against your legs.  The "
"silence is absolute down here, hanging thickly in the air around you.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"b6-1",
      "south" : ROOMS+"b4-1",
      "east" : ROOMS+"b5-2"
    ]));
    add_item(({"fog","mist","mists"}),"%^BLUE%^Thick %^WHITE%^mist%^BLUE%^ conceals the entire floor "
"from sight, swirling in thick chilling tendrils around your feet, and leaving tiny crystals of "
"%^WHITE%^%^BOLD%^i%^CYAN%^c%^WHITE%^e%^RESET%^%^BLUE%^ upon your legs.  There's no telling what might "
"be hidden beneath it.%^RESET%^");
}
