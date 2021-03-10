#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(BUILT_CAVE);
    set_travel(RUBBLE);
    set_short("Ogre's Den");
    set_long(
@KAYLA
This room appears to have seen a great deal of fighting recently.  Great 
gouges have been taken out of the packed-dirt floor, a large table lies 
overturned in the center of the room, and bits of splintered wood and 
torn cloth from the destroyed beds lay litter the floor.  Several torch 
brackets have been ripped from the walls and now lay scattered around a 
large upturned empty barrel near the west wall.
KAYLA
    );
    set_exits(([
       "south" : "/d/deku/open/ogre"
    ] ));
    set_items(([
      "table" : "The large crude wooden table has been overturned in the "
         "middle of the floor.  One of its legs has been broken off and "
         "splintered into pieces, perhaps from being used as a weapon.",
      ({"barrel", "torch", "brackets" }) : "Most of the torch brackets which "
         "once lined the walls of this room now lay twisted and bent, "
         "scattered around the iron-bound wooden barrel.  A few drops of "
         "bitter smelling alcohol are all that remain within the overturned "
         "barrel.",
    ] ));
}

void reset() {
  ::reset();
  if(!present("ogre")) {
    new("/d/deku/monster/ogre1")->move(TO);
  }
  if(!present("captain")) {
    new("/d/deku/monster/ogre_cap")->move(TO);
  }
}
