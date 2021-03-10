#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_property("no teleport",1);
  set_short(
  "Northern end of the courtyard of the Rose Keep."
  );
  set_long(
  "Northern end of the courtyard of the Rose Keep.\n"
  "  Gloom surrounds you here."
  "  A dim building is to the east and to the south you can see the faint outlines of a small hedge surrounding a garden."
  "\n"
  );
  set_smell("default",
  "The smell of blood grows stronger to the south."
  );
  set_listen("default",
  "You hear muted rustling as if something brushing through dried vegitaion."
  );
  set_items(([
  ]));
  set_exits(([
  "north":KEEP"k19.c",
  "east":KEEP"k24.c",
  "west":KEEP"k22.c",
  "south":KEEP"k30.c",
  ]));
}
