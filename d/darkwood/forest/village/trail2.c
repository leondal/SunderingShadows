#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("light",2);
  set_property("indoors",0);
  set_climate("temperate");
  set_short("Merchant Trail");
  set_long("%^ORANGE%^Merchant Trail to Stormpemhauder%^RESET%^\n"
           "You travel along the Merchant Trail to Stormpemhauder. "
           "It is well traveled judging by the wagon ruts and "
           "footprints here. Darkwood's trees and underbrush line "
           "either side of the road and hinder vision into the "
           "forest.");
  set_smell("default","Its dusty along the trail.");
  set_listen("default","Birds caw and leapords scream.");
  set_items( ([
     "ruts" : "Some of the ruts carve deep into the dirt while others "
              "just skim the surface.",
     "footprints" : "They vary in size but you also notice other tracks.",
     "tracks" : "You can make out large cat prints, bird prints and prints "
                "you dont recognize.",
     "trees" : "They grow tall and thick and block your view of the "
               "deep forest.",
     "underbrush" : "Its so thick along the road side that thought of "
                    "travel into the forest at this point is dismissed."
	       ]) );
  set_exits( ([
     "north" : "/d/darkwood/forest/village/trail1",
     "south" : "/d/darkwood/forest/village/trail3"
	       ]) );
  }

