#include <std.h>
#include "../dragon.h";


inherit BTOWN;

void create() {
   ::create();
   set_property("light", 0);
   set_property("indoors",1);
   set_short("Ruined stables");
   set_long(
      "%^BOLD%^%^BLACK%^This used to be the stables of %^RED%^Sanctuary%^BLACK%^."+
      " The stables are a dark and foreboding structure. You can see the"+
      " pegs that lanterns used to hang on throughout the building. Now the lanterns"+
      " lay in broken heaps on the floor."+
      " Many bodies and skeletons of horses are strewn about the stables."
   );
   set_exits( ([
     "west" : TOWN+"general",
     "south" : TOWN+"roadE2"
 ]) );
}