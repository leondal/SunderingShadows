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
  "  To your north a great barn stands with the doors closed."
  "  To your west is a pig pen and to the east are hay fields."
  "  To the south you can see the buildings of the populous of the hamlet."
  "\n"
  );
  set_smell("default",
  "The smell of slaughter comes from the barn to the north."
  );
  set_listen("default",
  "The town is strangly silent and even the animals seem to be trying to keep quiet."
  );
  set_items(([
  "road":"Hard packed paving stones line the well kept road.",
  "buildings":"Small buildings of a farming communtity.  A larger barn is in the northen end of the hamlet and a winery to the south.",
  "paving stones":"Uniformily rounded and placed with care.   Looks like someone put alot of money into its their construction and upkeep.",
  "pig pen":"Its a small fenced pen for keeping pigs from wandering.  A large pool of cracked dry mud is in its center.",
  "pasture":"You can see listless looking animals meandering about.",
  "barn":"A large structure to store hay and weather animals in the colder days.",
  "hayfield":"Its a hayfield that looks like its in need of being worked on.",
  ]));
  set_exits(([
  "northwest":ROOMS"v6.c",
  "north":ROOMS"v27.c",
  "south":ROOMS"v8.c",
  "east":ROOMS"v37.c",
  "west":ROOMS"v42.c",
  ]));
}
void init(){
  ::init();
  do_random_encounters(({
  MON"pig.c",MON"cow.c",MON"horse.c",MON"pskeleton.c",
  }),50,1);
}
