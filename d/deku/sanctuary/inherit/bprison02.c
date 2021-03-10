#include <std.h>
#include "../dragon.h";

inherit ROOM;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors", 1);
   set_terrain(STONE_BUILDING);
   set_travel(DECAYED_FLOOR);
   set_property("no teleport", 1);
   set_short("%^BOLD%^%^RED%^Abandoned prison%^RESET%^");
   set_listen("default","%^RESET%^%^GREEN%^It is very quiet here.%^RESET%^");
   set_smell("default","%^RESET%^%^CYAN%^The air is filled with the smell of something rotting.%^RESET%^");
}
