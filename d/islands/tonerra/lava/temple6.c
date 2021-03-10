#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_property("no teleport",1);
  set_property("used sticks",1);
  set_short("A choice offered");
  set_long(
@DESC
   %^BOLD%^%^RED%^A choice offered%^RESET%^
You see a portal here that looks like the entrance to the
monestary. Looks as if there is an exit from this place.
Should you take it or move deeper into the temple?
DESC
  );
  set_listen("default","The sound of Lava has stopped here.");
  set_smell("default","some must is in the air here");
  set_exits(([
    "out":LAVA+"temple5",
    "deeper":LAVA+"temple7",
    "escape":MONASTERY+"stairs"

  ]));


}

