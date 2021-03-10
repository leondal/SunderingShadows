#include <std.h>
#include "../dragon.h";

inherit ROOM;

void create() {
   ::create();
   set_property("light", 2);
   set_property("indoors", 1);
   set_terrain(STONE_BUILDING);
   set_travel(SLICK_FLOOR);
   set_property("no teleport", 1);
   set_short("%^BOLD%^%^RED%^Tower of the Arcane Brotherhood%^RESET%^");
   set_listen("default","%^RESET%^%^YELLOW%^It is very quiet here.%^RESET%^");
   set_smell("default","%^RESET%^%^GREEN%^The air is full of pleasant scents.%^RESET%^");
}