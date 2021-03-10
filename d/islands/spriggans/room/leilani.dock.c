//dock for Leilani ~Circe~ 5/27/07
#include "/d/islands/spriggans/spriggan.h"
#include <std.h>
#include <objects.h>

inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
  ::create();
  set_property("light",3);
  set_property("no teleport",1);
  set_property("indoors",0);
  set_terrain(BARREN);
  set_travel(DECAYED_FLOOR);
  set_short("A well-kept dock on the isle of Leilani");
  set_long(
    "%^RESET%^%^ORANGE%^Jutting out into the %^GREEN%^serene "
      "%^CYAN%^bl%^GREEN%^u%^CYAN%^e%^GREEN%^-%^CYAN%^gre%^GREEN%^en "
      "%^CYAN%^waters %^ORANGE%^is well-made and preserved dock.  "
      "There seems to be ample space for a few boats to dock at once, "
      "though a huge ship would have trouble navigating the shallows "
      "this close to the shore.  A faint %^YELLOW%^footpath %^RESET%^"
      "%^ORANGE%^leads eastward away from the dock but seems to "
      "disappear quickly into the sand.  Just ahead, a huge "
      "flat-topped %^RESET%^mountain%^ORANGE%^ rises high above "
      "the shore.%^RESET%^\n");
   set_items(([
      ({"sea","ocean","water"}) : "%^CYAN%^The sparkling waters of the "
         "sea are a soothing blue-green, and they seem to be teeming "
         "with sealife.%^RESET%^",
      ({"mountain","sides","slopes","rocky sides"}) : "Butting close against "
         "the shore, the rocky slopes of the mountain are a deep gray "
         "in color, dusted with brown.  They seem to offer no handholds "
         "or ready means up.  The top of the mountain itself looks to "
         "be flattened, rather like a dormant volcano.",
      "dock" : "%^ORANGE%^To the west lies a well-made wooden "
         "dock.  The supports have been tarred to help prevent "
         "rot, and there seems to be ample room for two or three boats "
         "to dock at once.%^RESET%^"
   ]));
   set_listen("default","You hear the waves crashing against the shore.");
   set_smell("default","The light scent of salt and seaweed hangs in the air.");
   set_exits(([
      "east" : PATHEXIT"s1"
   ]));
}
