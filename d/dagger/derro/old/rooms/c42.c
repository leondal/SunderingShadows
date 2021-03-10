#include <std.h>
#include "../derrodefs.h"

inherit ROOM;

void create(){
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(LEDGE);
  set_property("no teleport",1);
  set_property("light",2);
  set_property("indoors",1);
  set_short(  "%^RED%^Natural lava tunnel%^RESET%^"  );
  set_long(
  "%^RED%^Natural lava tunnel%^RESET%^\n"
  "  This simple passageway was formed by the passage of lava eons ago, at least you hope so and that it ain't coming back while you are still here."
  "   Steam billows through this room from the west making it hard to see and the rocks slippery to walk on."
  "  Lava glows dimly to the southeast and you wonder which way would be hotter.\n"
  );
  set_smell("default",  "Steam clears your sinuses."  );
  set_listen("default", "The sound of bubbling comes from both the directions."  );
  set_items(([
  "walls":"Naturally formed from the action of lava through the earth these passageways twist and turn through the rock leading into these rooms which were just pockets at one time filled with lava.",
  "ceiling":"Naturally formed from the action of lava through the earth these passageways twist and turn through the rock leading into these rooms which were just pockets at one time filled with lava.",
  "floor":"Shiny and black in places and crumbling and grey in others.   The floor seems partially unstable and you wonder how far a fall through them to the lava would take.",
  "steam":"The gaseous form of water.   It's a pale mist that glows red from the lights to the southwest,",
  ]));
  set_exits(([
  "west":ROOMS"c43",
  "southeast":ROOMS"c40",
  ]));
}
