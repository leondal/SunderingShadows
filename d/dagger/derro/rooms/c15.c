#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Paths end on the lava sea%^RESET%^"  );
  set_long(
  "%^RED%^Paths end on the lava sea.%^RESET%^\n"
  "  The rocky path through the pools of lava leads out here onto a lava sea that stretches out past sight to all directions but the way you came."
  "  More giant bodies are clustered here with a lone shattered Derro as well."
  "  The path leads out of this passageway into an immense cavern to the east onto a sea of lava."
  "\n"
  );
  set_smell("default",
  "Your lungs burn with the heat and harsh vapors."
  );
  set_listen("default",
  "Wind moans as it echoes in this vast chamber."
  );
  set_items(([
  "floor":"The path you stand on is not high above a lake of lava.",
  "walls":"You can see the wall far to the west but the others are lost in the haze.  Everything is shiny and black but the red light makes it difficult to see anything clearly over distance.",

  ({"corpse","bodies","body","corpses"}):"Shattered and broken with burn marks and huge punctures that are all cauterized.  The lone derro was crushed into the path and is barely recognizable as once being such.",
  "derro":"Shattered and broken with burn marks and huge punctures that are all cauterized.  The lone derro was crushed into the path and is barely recognizable as once being such.",
  "ceiling":"200 feet above you the black glistening glass reflects light in a million facets.",
  "path":"The path continues out over the sea of lava.",
  "lava":"The lava swirls about lethargically.  The top has hardened in places near the walls and the path but your gaze keeps being drawn back to the slow eddies of red light that glow through.\n It calls to you, should you jump?",
  ]));
  set_exits(([
  "west":ROOMS"c10",
  "east":ROOMS"c28",
  ]));
}
  init(){
  ::init();
  add_action("jump_fun","jump");
}
int jump_fun(){
   tell_room(TO, "%^BOLD%^%^RED%^"+TPQCN+" stares into the lava then jumps off the path with a blank look in "+TP->query_possessive()+" eyes!", TP);
  write("You jump down off the edge into the lava sea!");
  TP->move_player(ROOMS"lavapit");
  return 1;
}
