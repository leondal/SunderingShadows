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
  "  To the a large building sits and to the east a grape vines stretch off."
  "  The road leads northeast and south and a house sits to the west."
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
  "sign":"Perhaps you could read it?",
  "large building":"A large low L-shaped structure.   Looks like its a place of buisiness.",
  "grape vines":"They stretch off into the distance and look saddly neglected and sickly.",
  ]));
  set_exits(([
  "northeast":ROOMS"v12.c",
  "south":ROOMS"v14.c",
  "west":ROOMS"v62.c",
  ]));
}
