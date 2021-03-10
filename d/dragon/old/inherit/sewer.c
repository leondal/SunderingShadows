#include <std.h>
#include "../dragon.h";

inherit ROOM;

void create() {
   ::create();
   set_smell("default","The smell of stagnant water assaults your senses.");
   set_listen("default","%^RESET%^%^CYAN%^There is only silence here.%^RESET%^");
   set_terrain(SHALLOW_WATER);
   set_travel(SLICK_FLOOR);
}
