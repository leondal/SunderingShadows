#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Churchyard");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",2);
   set_long(
@DESC
This is the rear yard behind the %^CYAN%^Cathedral of Seneca%^RESET%^. It is a 
beautiful garden with a stone path that winds its way around 
various flowering trees and bushes. A small pond glistens and 
reflects the colors around it. A magnificent white gazebo stands 
at the center of the churchyard. It is large enough for a fine 
gathering and is often used in weddings. It is surrounded by 
pink dogwood trees in bloom.
DESC
   );
   set_exits(([
      "east" : "/d/attaya/seneca/church",
      "gazebo" : "/d/attaya/seneca/gazebo",
   ]));
   set_items(([
      "trees" : "The trees represent species gathered from every corner of this world.  Many are flowering and they provide a mystical touch all around you.",
      "bushes" : "Tropical hibiscus and other bushes make natural walls in places and soften the walls of the cathedral and the fences that surround the yard.",
      "gazebo" : "The white gazebo is a favorite spot for weddings on sunny days.  It is large and surrounded by pink flowering dogwood trees.",
      "pond" : "The crystal clear waters of the pond cast your reflection back at you.",
      "cathedral" : "The rear of the cathedral is as ominous as the front.",
      "staircase" : "The stairs are made from wood planks and bound by metal wire.  An iron railing gives you some security.",
   ]));
}
