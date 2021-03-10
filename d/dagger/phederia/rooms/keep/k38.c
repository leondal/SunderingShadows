#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
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
  "north":KEEP"k31.c",
  "south":KEEP"k46.c",
  "east":KEEP"k39.c",
  "west":KEEP"k37.c",
  ]));
}
