#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Communal bathhouse of the Rose Keep."
  );
  set_long(
  "Communal bathhouse of the Rose Keep.\n"
  "  This long low structure has a number of large wooden tubs set up about it."
  "  Low stone kilns with grates atop them hold great pots of cold water."
  "  Lines strung across the ceiling to which drapes are hung cross the center of the room but other than that its wide open."
  "\n"
  );
  set_smell("default",
  "Mold is started to set it."
  );
  set_listen("default",
  "Water drips onto stone somewhere in the shadows."
  );
  set_items(([
  "lines":"Cords strung against the support posts with drapes hung from them could be pulled across the room to insure some small amount of privacy.",
  "drapes":"Simple but strong canvas well treated to resist the vapors in the air hang on the lines.",
  "kilns":"Low stone fireplaces to heat the water for the baths.",
  "tubs":"Many wooden tubs are in lines along the edges of the room.  A few still hold still stagnant water.",
  "water":"The water has scum floating at the top.  You doubt a bath here would help you much.",
  ]));
  set_exits(([
  "north":KEEP"k18.c",
  "west":KEEP"k23.c",
  ]));
}
