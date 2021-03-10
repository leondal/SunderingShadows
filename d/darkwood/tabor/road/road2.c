#include <std.h>
#include "road.h"
inherit ROAD;

void create() {
   ::create();
   set_short("Bridge on the Northern Highway");
   set_long("%^BOLD%^Bridge on the Northern Highway%^RESET%^\n"
     "%^GREEN%^You are traveling along the Northern Highway of the Tsarven Empire. The road is large enough for two wagons to travel side by side and it has obviously had a lot of use. This wood and stone bridge allows you to continue your journey along the road to the north or south. A well-traveled path to the west leads to a ferry dock along the river."
   );
   set_exits(([
      "north" : PATH+"road1",
      "south" : PATH+"road3",
      "west" : "/d/shadow/virtual/river/tabor.dock",
   ]));
}
