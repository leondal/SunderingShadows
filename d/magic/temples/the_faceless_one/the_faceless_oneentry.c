//Temple of the Faceless One - created by Nienne 2/18
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(0);
   set_name("A narrow path in the mountains");
   set_short("%^YELLOW%^A narrow path in the mountains%^RESET%^");
   set_long("%^YELLOW%^A narrow path in the mountains%^RESET%^\n"
"%^ORANGE%^This small side-path leads away from the main trail, with twists and turns that quickly hide it from sight.  The high stone walls of the %^YELLOW%^Charu Mountains %^RESET%^"
"%^ORANGE%^rise up to either side, shrouding the path in perpetual %^BLUE%^shadow%^ORANGE%^.  Little grows here, beyond a few small and scraggly %^GREEN%^thorns %^ORANGE%^that snatch at "
"anything that passes close.  A little further along, the narrow trail comes to an end against a cliff face, where a %^BOLD%^%^BLACK%^dark crevasse %^RESET%^%^ORANGE%^splits the mountainside, "
"leading to darkness within.%^RESET%^\n%^RESET%^");
   set_smell("default","The clean scent of fresh water fills the air.");
   set_listen("default","You hear the distant burble of a fast moving stream.");
   set_exits(([
      "northeast": "/d/shadow/room/beastvillage/rooms/beast13",
      "temple": "/d/magic/temples/the_faceless_one/the_faceless_one",
   ]));
}