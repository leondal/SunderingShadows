#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit VAULT;

void create() {
  ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no sticks",1);
    set_terrain(STONE_BUILDING);
    set_travel(SLICK_FLOOR);
    set_short("%^BOLD%^%^WHITE%^A tomb%^RESET%^");
    set_name("A tomb");
}

