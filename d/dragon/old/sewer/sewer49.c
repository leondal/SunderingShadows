#include <std.h>

inherit "/std/vault";

void create() {
  ::create();
  set_property("light", -1);
  set_property("indoors", 1);
  set_property("no teleport", 1);
  set_property("magic hold", 100);
  set_door("door","/d/dragon/sewer/sewer50","north","dsewer_key");
  set_locked("door",1);
  set_open("door",0);
  "/d/dragon/sewer/sewer50.c"->set_open("door",0);
  "/d/dragon/sewer/sewer50.c"->set_locked("door",1);
  set_short("Disgusting sewer");
  set_long("%^BOLD%^%^RED%^
This is a wider section os sewer under the city of Sanctuary.  This
section of tunnel is dry compared to the other sections in these old
sewers.  Faintly luminescent lichen clings to the walls, reflecting
lightly off the water that occasionally drip from the ceiling of the
tunnel.  There is a large iron door within the northern wall.
  ");
  set_items(([
     "sewers":"The disgusting tunnels of waste under Sanctuary.",
     "door": (: this_object(), "look_at_door" :) ]));
  set_exits(([
     "south":"/d/dragon/sewer/sewer48",
     "north":"/d/dragon/sewer/sewer50"]));
}

void look_at_door() {
  if(query_open("door")) {
    write("This is an old and rusty iron door.  You wonder what in the 9 \n"+
          "levels of hell a door would be doing in these forgotten sewers.");
    write("The iron door is opened.");
    } else {
    write("This is an old and rusty iron door.  You wonder what a door would\n"+
          "be doing in the sewers.  The door is closed.");
  }
}

void reset() {
  ::reset();
}
