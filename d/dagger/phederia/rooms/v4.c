#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Cobbled road."
  );
  set_long(
  "Cobbled road.\n"
  "  This hard cobbled road looks like its had a lot of heavy use."
  "  Many wagons and travelers have passed this way and your happy its set with paving stones or else it would be a wreck like most roads you've seen."
  "  To the east you can see patures and a large barn."
  "\n"
  );
  set_smell("default",
  "The normal smell of farm animals has a faint hint of something else under it."
  );
  set_listen("default",
  "The sounds of your travel echo on the paving stones."
  );
  set_items(([
  "road":"Hard packed paving stones line the well kept road.",
  "buildings":"Small buildings of a farming communtity.  A larger barn is in the northen end of the hamlet and a winery to the south.",
  "paving stones":"Uniformily rounded and placed with care.   Looks like someone put alot of money into its their construction and upkeep.",
  "pasture":"You can see listless looking animals meandering about.",
  "barn":"A large structure to store hay and weather animals in the colder days.",
  ]));
  set_exits(([
  "northwest":ROOMS"v3.c",
  "southeast":ROOMS"v5.c",
  ]));
}
void init(){
  ::init();
  do_random_encounters(({
  MON"pig.c",MON"horse.c",MON"cow.c",
  }),25,1);
}
