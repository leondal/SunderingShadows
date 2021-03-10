#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
 "Storage shed under the walls of the Rose Keep."
  );
  set_long(
  "Storage shed under the walls of the Rose Keep.\n"
  "  This stone structure built into the interior of the walls is meant to store dry goods."
  "  A few crates and sack are visible but their contents have been ransacked and there is nothing left of apparent value."
  "\n"
  );
  set_smell("default",
  "Mold seems to have set into the spilt grain with unnatural speed."
  );
  set_listen("default",
  "Bugs skitter across the floor."
  );
  set_items(([
  "bugs":"Gruesome black beetles skitter across the floor with no visible reason for their mad ramblings.",
  "crates":"Old crates seemed to have once housed horse tack.  Now rooted through and torn apart.",
  "sacks":"Horse feed lies scattered about from the slits in the sides of the sacks.",
  ]));
  set_exits(([
  "north":KEEP"k43.c",
  ]));
}
