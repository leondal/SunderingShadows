// by Styx 5/2003

#include <std.h>
#define FERRYOBJ1 "/d/shadow/virtual/river/obj/riverferry4"
#define FERRYOBJ2 "/d/shadow/virtual/river/obj/riverferry5"  // to Deku or coast....

inherit "/d/shadow/virtual/river/river_dock";

void create() {
  object ob;
  ::create();
  set_indoors(0);
  set_terrain(BARREN);
  set_travel(FOOT_PATH);
  set_light(2);
  set_name("Tharis ferry dock");
  set_short("Tharis ferry dock");
  set_long("%^YELLOW%^Tharis ferry dock%^RESET%^\n"
	"Just east of a narrow section in the river where a bridge passes over "
	"it, the river widens again.  A slight eddy forms along the northern "
	"bank, creating an upstream current for the ferries to slip into and "
	"a calm enough spot for them to dock.  A pier juts out from the bank "
	"for the ferries to pull alongside and allow passengers to board.\n"
   );
   set_exits(([ "northwest":"/d/tharis/road/road7"  ]));

   set_smell("default","You can smell the famous Tharis cooking and other less appealing city scents.");
   set_listen("default","You hear the bustle of the city and local travelers."); 
   find_object_or_load("/d/shadow/virtual/river/shadow.dock");
   if(!objectp(FERRYOBJ1)) {
      ob = find_object_or_load(FERRYOBJ1);
      ob->set_dir("tabor");
      ob->move(TO);
   }
}
