// level 1 hall centre

#include <std.h>
#include "../inherit/ruins.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",1);
    set_name("Darkened hall of an abandoned building");
    set_short("%^BLACK%^%^BOLD%^Darkened hall of an abandoned building%^RESET%^");
    set_smell("default","Age-old dust fills the air, tickling at your nose.");
    set_listen("default","You can hear the faint scratching of claws on stone.");
    set_items(([
      "floor" : "%^ORANGE%^The floor is solid and level beneath your feet, though a thick layer of "
"%^BLACK%^%^BOLD%^dirt%^RESET%^%^ORANGE%^ and %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^ covers it, making "
"it nearly impossible to see the original floor beneath.  In a few spots you can see the remains of what "
"were probably rather ornate patternings upon the floor, somehow still preserved beneath the "
"grime.%^RESET%^",
      ({"dirt","dust"}) : "%^ORANGE%^A thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^ coats "
"every visible surface.  The building has probably been abandoned for a long time.%^RESET%^",
      "roof" : "%^ORANGE%^The roof reaches high above your head, shrouded in "
"%^BLACK%^%^BOLD%^shadows%^RESET%^%^ORANGE%^ and %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  Ornate "
"bordering from nearby pillars traces along the ceiling's edges.%^RESET%^",
      ({"pillar","pillars"}) : "%^ORANGE%^Tall pillars support the roof at regular intervals throughout "
"the hall.  Ornate bordering runs around the upper and lower edges of each, where they meet the roof and "
"floor.%^RESET%^"
    ]));
}
