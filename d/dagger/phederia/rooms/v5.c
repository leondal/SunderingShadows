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
  "  To the south you can see a pig pen and the backs of a few buildings."
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
  "pig pen":"Its a small fenced pen for keeping pigs from wandering.  A large pool of cracked dry mud is in its center.",
  "pasture":"You can see listless looking animals meandering about.",
  "barn":"A large structure to store hay and weather animals in the colder days.",
  ]));
  set_exits(([
  "northwest":ROOMS"v4.c",
  "southeast":ROOMS"v6.c",
  ]));
}
