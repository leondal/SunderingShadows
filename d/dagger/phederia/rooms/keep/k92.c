#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_property("indoors",1);
  set_short(
  "Short"
  );
  set_long(
  "Long"
  "\n"
  );
  set_smell("default",
  "Smell"
  );
  set_listen("default",
  "Listen"
  );
  set_items(([
  ]));
  set_exits(([
  "spiral staircase":KEEP"k77.c",
  "north":KEEP"k88.c",
  "south":KEEP"k96.c",
  "west":KEEP"k91.c",
  "east":KEEP"k93.c",
  ]));
}
