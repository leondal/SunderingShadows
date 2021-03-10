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
"At the top of the stairs here is a small open hall, walled in with "
"%^ORANGE%^wooden slats%^RESET%^.  Small windows are set along its length, "
"shedding rays of %^YELLOW%^light %^RESET%^into the homey building.  Before "
"you is a single door, and another stands at either end of the hallway.\n");
    set_smell("default","The odor of cooking food drifts up from below.");
    set_listen("default","You can hear the distant sound of plates clanging.");

    set_exits(([
      "down":TOWN"inn",
      "east":TOWN"inn3",
      "west":TOWN"inn4",
      "north":TOWN"inn5",
    ]));

    set_door("dolphin door",TOWN"inn3","east",0);
    set_door("turtle door",TOWN"inn4","west",0);
    set_door("crab door",TOWN"inn5","north",0);
    set_door_description("dolphin door","%^RESET%^The door is made of the same "
"slats as the building, unremarkable in appearance except for a "
"%^BOLD%^%^BLUE%^carved dolphin %^RESET%^in the centre of the wood.");
    set_door_description("turtle door","%^RESET%^The door is made of the same "
"slats as the building, unremarkable in appearance except for a %^GREEN%^carved "
"turtle %^RESET%^in the centre of the wood.");
    set_door_description("crab door","%^RESET%^The door is made of the same "
"slats as the building, unremarkable in appearance except for a %^RED%^carved "
"crab %^RESET%^in the centre of the wood.");
}
