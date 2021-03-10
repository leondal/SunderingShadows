#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "The inner hedge garden."
  );
  set_long(
  "The inner hedge garden.\n"
  "  The dark hedges surround you again."
  "  You stand in the remnents of what was once a fine garden."
  "  Scattered grey petals are all that remain of the flowers that graced the teraces and small fountains, now overgrown with runners from the hedge."
  "  The path leads south and east to the rest of the garden."
  "\n"
  );
  set_smell("default",
  "Decay holds this garden in its grip."
  );
  set_listen("default",
  "The hedges rustle and move when you turn your back to them."
  );
  set_items(([
  "hedges":"You've just about had enough of these blood sucking hedges.",
  ({"flower petals","petals"}):"Dead, faded petals are strewn through the plants the runners of the hedges have choaked the life from.",
  "runners":"Roots and vines run from the hedges around the garden, killing the rest of the plants with their grip.  They quiver as you draw near sensing your blood.",
  ]));
  set_exits(([
  "north":KEEP"k23.c",
  "south":KEEP"k37.c",
  "east":KEEP"k31.c",
  ]));
}
