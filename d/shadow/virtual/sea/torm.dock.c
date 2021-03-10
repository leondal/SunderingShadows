#include <std.h>

inherit "/d/shadow/virtual/sea/dock";

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
 ::create();
   set_indoors(0);
   set_property("no teleport",1);
   set_light(2);
  set_terrain(BARREN);
  set_travel(FOOT_PATH);
   set_short("Torm's public dock");
   set_long("You have reached Torm's public dock for smaller boats.  It is"
   " lower than the rest of the Boardwalk to match the level of the smaller"
   " boats' decks.  The larger ships dock all along the raised Boardwalks. "
   " The Dagger Sea stretches out to the eastern horizon while Torm's"
   " cityline is dotted with spires to the west.  Small birds fly about,"
   " hunting for scraps from meals, or preferably a tasty fish.  Sailors"
   " wander about the boardwalk mingling with the citizens of Torm out"
   " here for their own reasons, whatever they might be.  Many ships are"
   " in the process of docking, unloading or leaving along the Boardwalk"
   " west and the longer one to the south."
  );
  set("night long", "%^BLUE%^You have reached Torm's public dock for small"
    " boats.  It is lower than the rest of the Boardwalk to match the level"
    " of the smaller boats' decks.  The larger ships dock all along the raised"
    " Boardwalks.  The Dagger Sea is covered in a light fog that sends wispy"
    " tendrils out into the city.  Beneath your feet are the dark waters of"
    " the sea that seem almost to be a bottomless black void.  You can't even"
    " make out the tallest of the waves.  The boardwalk west is quiet at"
    " night, with most of the citizens already gone to bed and few"
    " ships daring to brave the rocks that are hidden by the fog to"
    " dock here at night.  The planks beneath your feet are slightly"
    " damp, and you must be careful of your footing."
  );
set_exits(([
	 "west":"/d/dagger/Torm/city/dock_taxes"
  ]));
  set_smell("default","You smell salt in the air from the Dagger Sea.");
  set_listen("default","The waves of the sea wash against the docks.");
// per T we don't want the ferry here - Styx 8/24/01
// find_object_or_load("/d/shadow/virtual/sea/obj/ferryboat")->move(TO);
}
