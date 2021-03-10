//Shore around the island Leilani ~Circe~ 5/26/07
#include <std.h>
#include "../spriggan.h"
inherit SBEACH;

void create(){
   ::create();
   add_item("dock","%^ORANGE%^To the west lies a well-made wooden "
      "dock.  The supports have been tarred to help prevent "
      "rot, and there seems to be ample room for two or three boats "
      "to dock at once.%^RESET%^");
   set_long(::query_long()+"\n%^ORANGE%^Jutting out into the water "
      "to the west is a well-kept wooden dock.%^RESET%^\n");
   set_exits(([
      "west" : "/d/shadow/virtual/sea/leilani.dock",
      "north" : PATHEXIT"s2",
      "south" : PATHEXIT"s52",
      "east" : PATHEXIT"g1"
   ]));
}
