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
  "  To the west the small hamlet sits in desolation."
  "  To the east you can see a fortress hidden behind a great maze of hedges."
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
  "house":"Its a small house that once housed a family of the hamlet.   Shutters bang in the open windows and it looks deserted.",
  "paving stones":"Uniformily rounded and placed with care.   Looks like someone put alot of money into its their construction and upkeep.",
  "fortress":"A rose colored stone fortress sits behind a great hedge maze.",
  "hedge maze":"A great overgrown hedge surrounds the fortress to the east.",
  ]));
  set_exits(([
  "east":ROOMS"h1.c",
  "west":ROOMS"v19.c",
  ]));
}
