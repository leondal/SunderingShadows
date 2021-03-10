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
  "  To the east is the hamlets center and to the west are two more houses."
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
  "houses":"These small houses are well built and recently construced.  Some of the houses you can see from here have had the doors kicked in.",
  "paving stones":"Uniformily rounded and placed with care.   Looks like someone put alot of money into its their construction and upkeep.",
  ]));
  set_exits(([
  "west":ROOMS"v16.c",
  "east":ROOMS"v9.c",
  ]));
}
