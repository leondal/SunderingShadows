#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Office"
  );
  set_property("indoors",1);
  set_long(
  "Office\n"
  "  This is the office of the winery."
  "   From here the documents and arangments are made for the trasnportation and production involved with the running of this winery."
  "\n"
  );
  set_smell("default",
  "You smell sweet wine in the air."
  );
  set_listen("default",
  "Its silent in here"
  );
  set_items(([
  ]));
  set_exits(([
  "south":ROOMS"v45.c",
  ]));
}
