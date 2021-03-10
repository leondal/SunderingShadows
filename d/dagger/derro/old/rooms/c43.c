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
  set_short(  "%^RED%^Boiling spring%^RESET%^"  );
  set_long(
  "%^RED%^Boiling spring%^RESET%^\n"
  "  Steam fills this room preventing you from seeing very far across it."
  "  The sound of bubbling and boiling water is overpowering here and the rocks of the floor and walls are slick with moisture."
  "  A pool of water has formed at the foot of a crack in the wall where the steam issues forth from a tunnel in the wall."
  "\n"
  );
  set_smell("default",  "Steam clears your sinuses."  );
  set_listen("default",  "Boiling water makes popping sounds from the crack."  );
  set_items(([
  "crack":"A crack in the wall leads to a tunnel that is filled with steam billowing up from below where a underground water source must be in contact with the lava.   The tunnel leads far up into the bedrock but is too narrow and filled with scalding steam to be accessible.",
  "walls":"Naturally formed from the action of lava through the earth these passageways twist and turn through the rock leading into these rooms which were just pockets at one time filled with lava.",
  "ceiling":"Naturally formed from the action of lava through the earth these passageways twist and turn through the rock leading into these rooms which were just pockets at one time filled with lava.",
  ({"water","pool","pool of water"}):"  A small pool of warm water has collected on the floor.  You assume that the steam that leads up feeds the cistern you passed coming down here and must vent to the surface somewhere as well.",
  "floor":"Shiny and black in places and crumbling and grey in others.   The floor seems partially unstable and you wonder how far a fall through it to the lava would take.",
  ]));
  set_exits(([
  "east":ROOMS"c42",
  "northwest":ROOMS"c44",
  ]));
}
