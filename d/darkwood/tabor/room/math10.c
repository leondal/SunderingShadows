#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create() {
  ::create();
  set_travel(DIRT_ROAD);
  set_terrain(CITY);
  set_light(2);
  set_name("Mathowvy Road, Tabor");
  set_short("Mathowvy Road, Tabor");
  set_long(
@DAI
%^BOLD%^Mathowvy Road, Tabor%^RESET%^
You are on a fairly steep upward slope on Mount Tabor, approaching the
fortress of %^YELLOW%^Caer Tabor%^RESET%^.  The road is starting to narrow here and
you see it curve around a bend to the northwest.  Directly east
is a large, rounded building made of what looks to be crystalline
walls.  To the west is a small empty lot that appears to be a work in progress.  To the south, you see the slope become gentler and the
road get wider as it leads straight into town.

%^RESET%^%^MAGENTA%^Mathowvy Road %^RESET%^continues to the northwest and south.
DAI
    );
  set_exits(([
   "south" : ROOMDIR+"math9",
    "northwest" : ROOMDIR+"math11",
    "enter" : ROOMDIR+"psientry"
  ]));
  set_listen("default","You hear the muted sounds of a large town to the south.");
  set_smell("default","The air here is clean with only faint "+
     "scents of the town below.");
  set_items(([
    "town" : "You can see the buildings of the town from here.",
    "castle" : "You see the thick, ancient walls of the fortress loom above you.",
    "building" : "The building seems to be made of crystal!  Its walls "+
       "and roof are rounded and seem to reflect light at all times."
  ]));
  set_pre_exit_functions(({"enter"}),({"GoThroughDoor"}));
 }

void reset(){
  ::reset();
  if(!present("street_light",TO))
    new("/d/common/obj/misc/street_light")->move(TO);
}

int GoThroughDoor(){
   if(TP->is_class("psion") || avatarp(TP)) {
      tell_object(TP, "As you walk through the archway, you feel a "+
         "slight prickling sensation pass over your skin.");
      tell_room(ETP, "The air within the archway shimmers briefly "+
         "as "+TPQCN+" passes through it.", TP);
        return 1;
   }
   return 1;
}
