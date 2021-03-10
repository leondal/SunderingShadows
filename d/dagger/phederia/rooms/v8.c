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
  "  To your north a great barn stands with the doors closed."
 "  To the east and west are small houses."
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
  "houses":"These small houses are well built and recently construced.  The door to the house to the west has been kicked off its hinges.",
  "paving stones":"Uniformily rounded and placed with care.   Looks like someone put alot of money into its their construction and upkeep.",
  "pig pen":"Its a small fenced pen for keeping pigs from wandering.  A large pool of cracked dry mud is in its center.",
  "barn":"A large structure to store hay and weather animals in the colder days.",
  ]));
  set_exits(([
  "north":ROOMS"v7.c",
  "west":ROOMS"v56.c",
  "east":ROOMS"v57.c",
  "south":ROOMS"v9.c",
  ]));
}
