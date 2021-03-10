#include "../tormdefs.h"
inherit TOWN;
void create(){
  ::create();
  set_short(
  "Beneath the Torm townhall"
  );
  set_property("indoors",1);
  set_long(
  "  This is a storage room below the mansion."
    "  It's in perfect order, with all the crates, sacks and barrels here in their own place and carefully catalogued."
  );
  set_exits(([
  "south":TCITY+"c151",
  ]));
  set_items(([
  "walls":"The walls are made of dull grey stone.",
   "floor":"The floors are made of dull grey stone.",
  ({"ceiling","roof"}):"The ceiling is made of dull grey stone and roughly finished.",
  "barrels":"Full of flour.",
  "crates":"Full of clothes and old building supplies.",
  "sacks":"They only contain dry grains and the like.",
  ]));
}
