// Coded by ~Circe~ 3/29/13 for Tarrasque plot/return
// of the druids. Will be reverted after the plot and a 
// short rebuilding.

#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(RUINS);
   set_travel(RUBBLE);
   set_name("Ruins of Asgard");
   set_short("Ruins of Asgard");
   set_long("You are standing in the ruins of Asgard.  All around you, "
      "buildings have been toppled, leaving rubble strewn about the "
      "streets.  In some places, walls have been reduced to piles of "
      "tiny stones, while in others, they stand largely untouched.  "
      "Here and there, the ground seems compressed, giving the only "
      "clue as to what could have caused such total destruction.\n");
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The air is filled with dust and smoke from the rubble.");
    set_listen("default","The city seems eerily quiet, missing the chatter of daily life.");
}
