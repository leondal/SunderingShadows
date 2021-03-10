#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(NAT_CAVE);
   set_travel(PAVED_ROAD);
   set_name("The entry to a mine");
   set_short("%^ORANGE%^The entry to a mine%^RESET%^");
   set_long("%^ORANGE%^The entry to a mine%^RESET%^\n"
"You stand within the shade of a %^BOLD%^%^BLACK%^yawning cavern entrance"
"%^RESET%^, leading into what appears to be a vast mine shaft.  The "
"%^ORANGE%^craggy rock face %^RESET%^of the mountain looms above you, "
"bordering the southern and eastern fronts of the small township to the "
"north.  Along the ground at your feet run a pair of %^BOLD%^%^BLACK%^thick "
"metal rails%^RESET%^, leading into the %^BLUE%^dark mouth %^RESET%^of the "
"mining tunnel.\n");
   set_smell("default","The air carries a dry and dusty smell.");
   set_listen("default","The distant echo of metal on stone reaches your 
ears.");
   set_items(([
     ({"town","township"}):"To the north lies a small township, nothing more "
"than a scattering of buildings here at the foot of the mountainside.",
     ({"mountain","mountainside"}):"Mountains rise up to the east and the "
"south, bordering in the little town that lies just to the north.  The "
"%^BLUE%^dark mouth %^RESET%^of a mining tunnel opens before you, leading "
"into the mountainside.",
     ({"rails","ground","floor"}):"Along the ground run a pair of "
"%^BOLD%^%^BLACK%^thick metal rails%^RESET%^, leading into the mine.  "
"Presumably they are designed to carry mining carts back and forth.",
   ]));
   set_exits(([
     "northeast":"/d/dagger/kinaro/street5",
     "south":MINES"mines1",
   ]));
}
