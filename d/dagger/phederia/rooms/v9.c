#include <std.h>
#include "/d/dagger/phederia/phedefs.h"

inherit ROOM;

void create(){
  ::create();
  set_property("light",2);
  set_short(
  "Hamlets center."
  );
  set_long(
  "Hamlets center.\n"
  "  This hard cobbled road looks like its had a lot of heavy use."
  "  Far to the north you can still see the barn, while to the south you can make out anothe large building."
  "  This is the crossroad in the center of the hamlet."
  "  A large pool of dried blood darkens the ground near a large well."
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
  "houses":"These small houses are well built and recently construced.  Some of the houses you can see from here have had the doors kicked in.",
  "paving stones":"Uniformily rounded and placed with care.   Looks like someone put alot of money into its their construction and upkeep.",
  "barn":"A large structure to store hay and weather animals in the colder days.",
  "well":"Its the center water supply for the people who lived here.",
  "blood":"A large pool of dried blood stains the cobbles.  Who ever lost that much blood is dead.",
  ]));
  set_exits(([
  "north":ROOMS"v8.c",
  "west":ROOMS"v10.c",
  "east":ROOMS"v17.c",
  "south":ROOMS"v63.c",
  ]));
}
