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
  "north":KEEP"k86.c",
  "east":KEEP"k91.c",
  "west":KEEP"k112",
  "south":KEEP"k94.c",
  ]));
}
