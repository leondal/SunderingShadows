#include <std.h>


inherit ROOM;

void create() {
   ::create();
   set_property("light", 2);
   set_property("indoors", 1);
   set_terrain(STONE_BUILDING);
   set_travel(SLICK_FLOOR);
   set_property("no teleport", 1);
   set_short("A very decorative room.");
   set_listen("default","%^RESET%^%^BLUE%^Silence is all around you.%^RESET%^");
   set_smell("default","%^RESET%^%^GREEN%^Smell does not exist here.%^RESET%^");
}
