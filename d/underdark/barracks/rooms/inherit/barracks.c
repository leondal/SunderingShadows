#include <std.h>
#include "../barracks.h";
#include "../../../underdark.h";

inherit "/std/room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light", -3);
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
   set_short("Drow Barracks");
   set_listen("default","%^RESET%^%^BLUE%^It is deathly silent here.%^RESET%^");
   set_smell("default","%^RESET%^%^GREEN%^There is no smell.%^RESET%^");
}
