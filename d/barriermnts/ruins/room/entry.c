#include <std.h>
#include "../inherit/ruins.h"
inherit VAULT;

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
    set_long("%^ORANGE%^You are just inside the great doorway of an old building.  A pair of great "
"%^BLACK%^%^BOLD%^wooden doors%^RESET%^%^ORANGE%^ are set in the northern wall, presumably leading "
"outside.  The roof reaches high above your head, supported by curved arches from the walls at either "
"side.  The walls and roof are entirely covered in a thick layer of "
"%^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  The floor beneath your feet is perfectly flat, without "
"rubble or upturned stones to impede your progress, though it is coated in still more "
"%^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  To the south, the building opens into a hallway of "
"impressive size.  It seems very %^BLUE%^lifeless%^ORANGE%^ here, though a heavy feeling rests upon your "
"shoulders, making you feel a little uneasy.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"path0",
      "south" : ROOMS+"1-3"
    ]));
    set_items(([
      "floor" : "%^ORANGE%^The floor is solid and level beneath your feet, though a thick layer of "
"%^BLACK%^%^BOLD%^dirt%^RESET%^%^ORANGE%^ and %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^ covers it, making "
"it nearly impossible to see the original floor beneath.  In a few spots you can see the remains of what "
"were probably rather ornate patternings upon the floor, somehow still preserved beneath the "
"grime.%^RESET%^",
      ({"walls","wall"}) : "%^ORANGE%^The walls are crafted of strong stone, and darkened by decades of "
"%^BLACK%^%^BOLD%^dirt%^RESET%^%^ORANGE%^ and %^BLUE%^weathering%^ORANGE%^.  In a few places, however, "
"you can still make out the markings of patterns along the walls, as if they have been somehow preserved "
"over the ages.  Within the walls are set tall windows, %^BLACK%^%^BOLD%^blackened%^RESET%^%^ORANGE%^ "
"with age.%^RESET%^",
      ({"dirt","dust"}) : "%^ORANGE%^A thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^ coats "
"every visible surface.  The building has probably been abandoned for a long time.%^RESET%^",
      "roof" : "%^ORANGE%^The roof reaches high above your head, shrouded in "
"%^BLACK%^%^BOLD%^shadows%^RESET%^%^ORANGE%^ and %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  Ornate "
"bordering from nearby walls and pillars traces along the ceiling's edges.%^RESET%^",
      "doors" : "%^ORANGE%^Two great %^BLACK%^%^BOLD%^ash doors %^RESET%^%^ORANGE%^tower almost to the "
"roof, set in the northern wall.  An ornate brass handle is affixed to each.%^RESET%^"
    ]));
    set_door("great doors",ROOMS+"path0","north",0);
    set_door_description("great doors","%^ORANGE%^Two great %^BLACK%^%^BOLD%^ash doors "
"%^RESET%^%^ORANGE%^tower almost to the roof, set in the northern wall.  An ornate brass handle is "
"affixed to each.%^RESET%^");
    set_string("great doors","open","The doors swing open silently.");
    set_string("great doors","close","The doors click shut without a sound.");
}
