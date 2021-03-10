#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Avenue of Priestoka");
   set_long("%^GREEN%^Avenue of Priestoka%^RESET%^
You are walking on one of the main broad avenues of the city of Aketon. "
      "Many shops and houses are built around the branches on top of the "
       "tree. Citizens, travelers and all kinds of traders are passing by "
       "you each second. Guards of all kinds holding weapons are here to "
      "keep this city safe and peaceful.");
   set_items( ([ ({"avenue","road"}):"A broad road built on the branches "
      "of the tree.",
      "branch":"This branch is connected to the adjacent tree.",
      "citizens":"Of different age, some are rich and some are poor.",
      "travellers":"People coming from all over the realm to visit this "
      "famed elven city.",
      "traders":"These are merchants who wish to trade their goods for a "
      "reasonable repay here in Aketon.",
      "guards":"They keeps this place safe and peaceful."]) );
   set_exits( (["north":RPATH1+"1one21",
      "northeast":RPATH1+"1one22",
      "east":RPATH1+"1one30",
      "southwest":RPATH1+"1one1"]) );
}
