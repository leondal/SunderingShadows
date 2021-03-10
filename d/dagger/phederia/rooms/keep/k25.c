#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Pantry of the Rose Keep"
  );
  set_long(
  "Pantry of the Rose Keep\n"
  "  This is dry storage for the kitchens of the Rose Keep."
  "  Shelves filled with goods line the walls while barrels and sacks are stacked in the corners."
  "  A narrow staircase in the northeast corner leads down into darkness."
  "\n"
  );
  set_smell("default",
  "The smells from the kitchen drift in through the open door."
  );
  set_listen("default",
  "Something scurries about the corners."
  );
  set_items(([
  "barrels":"The barrels are filled with flour, barley and wheat.  Nothing of interest to you.",
  ]));
  add_item("shelves","Stacked hight with spices and dry goods.");
  add_item("barrels","The barrels are filled with flour, barley and wheat.  Nothing of interest to you as you look them over.");
  set_exits(([
  "east":KEEP"k26.c",
  ]));
}
