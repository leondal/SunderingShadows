#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(STAIRWAY);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Tunnel leading down%^RESET%^"  );
  set_long(
  "%^RED%^Tunnel leading down%^RESET%^\n"
  "  This tunnel leads up and down from here."
  "  Far below you can see the lava bubble and churn and above you are the twin dark holes you climbed down."
  "  The walls are rough and offer easy purchase but a fall would be fatal if you hit the lava below!\n"
  );
  set_smell("default",  "Something smelly clings to the walls."  );
  set_listen("default",  "The lava bubbles below you."  );
  set_items(([
  "lava":"Glitters swirls and bubbles.  The heat from them is tremendous.",
  "walls":"Crudely carved as if an afterthought to the construction of the complex.   Dark waste clings to the walls in places making it slipperier that first thought.",
  ]));
  set_exits(([
  "down":ROOMS"c40",
  ]));
  set_climb_exits(([
  "climb":({ROOMS"c26",20,100,100}),
  ]));
}
