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
  "  To the north lays the town center and its well."
  "  A house with a battered door lays to the west and the path continues to the south."
  "\n"
  );
  set_smell("default",
  "You can smell the faint iron smell of blood in the air."
  );
  set_listen("default",
  "The town is strangly silent and even the animals seem to be trying to keep quiet."
  );
  set_items(([
  "road":"Hard packed paving stones line the well kept road.",
  "house":"This small well build dwelling must of been the mayors or some officals house.  Its slightly larger and more ornate looking that the rest you've seen.",
  "paving stones":"Uniformily rounded and placed with care.   Looks like someone put alot of money into its their construction and upkeep.",
  ]));
  set_exits(([
  "north":ROOMS"v9.c",
  "west":ROOMS"v58.c",
  "south":ROOMS"v11.c",
  ]));
}
