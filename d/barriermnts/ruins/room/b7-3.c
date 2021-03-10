#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l0";

void create() {
    ::create();
    set_long("%^BLUE%^%^BLUE%^This is a dead-end corridor, leading off to the west into pitch-black "
"darkness.  The roof reaches high above your head, barely visible within the "
"%^BLACK%^%^BOLD%^shadows%^RESET%^%^BLUE%^ that seem almost alive with movement.  Stone walls surround "
"you on either side, blackened with %^BLACK%^%^BOLD%^shadows%^RESET%^%^BLUE%^ and "
"%^ORANGE%^grime%^BLUE%^.  The floor beneath your feet feels perfectly flat, without rubble or upturned "
"stones to impede your progress, but a thick layer of %^WHITE%^foggy mist%^BLUE%^ around your feet makes "
"it impossible to see, and brushes a sharp %^CYAN%^%^BOLD%^chill%^RESET%^%^BLUE%^ against your legs.  "
"The silence is absolute down here, hanging thickly in the air around you.  Clusters of "
"%^WHITE%^%^BOLD%^ici%^CYAN%^c%^WHITE%^les%^RESET%^%^BLUE%^ line the walls all around you.%^RESET%^\n");
    set_exits(([
      "south" : ROOMS+"b6-3"
    ]));
    add_item(({"fog","mist","mists"}),"%^BLUE%^Thick %^WHITE%^mist%^BLUE%^ conceals the entire floor "
"from sight, swirling in thick chilling tendrils around your feet, and leaving tiny crystals of "
"%^WHITE%^%^BOLD%^i%^CYAN%^c%^WHITE%^e%^RESET%^%^BLUE%^ upon your legs.  There's no telling what might "
"be hidden beneath it.%^RESET%^");
    add_item(({"walls","wall"}),"%^BLUE%^The walls are difficult to see, shrouded in "
"%^BLACK%^%^BOLD%^shadows %^RESET%^%^BLUE%^that seem to move constantly.  They are crafted of strong "
"stone, darkened by decades of dirt and weathering, and lined with clusters of "
"%^WHITE%^%^BOLD%^ici%^CYAN%^c%^WHITE%^les%^RESET%^%^BLUE%^.  In a few places, however, you can still "
"make out the markings of patterns along the walls, as if they have been somehow preserved over the "
"ages.%^RESET%^");
    add_item("roof","%^BLUE%^The roof reaches high above your head, shrouded in "
"%^BLACK%^%^BOLD%^shadows%^RESET%^%^BLUE%^ and %^ORANGE%^dust%^BLUE%^.  Ornate bordering from nearby "
"walls traces along the ceiling's edges, lined with clusters of "
"%^WHITE%^%^BOLD%^ici%^CYAN%^c%^WHITE%^les%^RESET%^%^BLUE%^.%^RESET%^");
    add_item(({"ice","icicle","icicles"}),"%^BLUE%^The edges of the roof and walls here are all lined "
"in clusters of %^WHITE%^%^BOLD%^ici%^CYAN%^c%^WHITE%^les%^RESET%^%^BLUE%^, adding a biting chill to "
"the air around you.%^RESET%^");
}

void reset() {
   ::reset();
   if(!present("frost wyvern")) { new(MON+"wyvern")->move(TO); }
}
