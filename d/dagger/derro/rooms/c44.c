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
  set_short(  "%^RED%^Outcrop of rock over the lava sea%^RESET%^"  );
  set_long(
  "%^RED%^Outcrop of rock over the lava sea%^RESET%^\n"
  "  This small outcropping of rock over looks a massive underground chamber."
  "  You can't see the far wall and the walls beside you curve up to a domed ceiling 300 feet above you."
  "  Lava stretches as far as you can see in the chamber, but you can see a small island of dark, glassy obsidian jutting out of the lava to the west near the what must be the middle of the sea."
  "  A small path leads to the island but goes off to the west and is lost in the haze of rising heat."
  "\n"
  );
  set_smell("default",  "The harsh vapors from the lava burn your lungs"  );
  set_listen("default",  "You hear a sound almost like waves as the lava churns about."  );
  set_items(([
  "walls":"Naturally formed from the action of lava through the earth, these passageways twist and turn through the rock leading into these rooms which were just pockets at one time filled with lava.",
  "ceiling":"Naturally formed from the action of lava through the earth, these passageways twist and turn through the rock leading into these rooms which were just pockets at one time filled with lava.",
  "floor":"Shiny and black in places and crumbling and grey in others.   The floor seems partially unstable and you wonder how far a fall through them to the lava would take.",
  ]));
  set_exits(([
  "southeast":ROOMS"c43",
  ]));
  set_climb_exits(([
  "descend":({ROOMS"c32",20,10,100}),
  ]));
}
