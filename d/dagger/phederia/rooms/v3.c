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
  "  You can start to see small well built buildings to the south and east."
  "\n"
  );
  set_smell("default",
  "You smell the far away smells of farm animals."
  );
  set_listen("default",
  "The sounds of your travel echo on the paving stones."
  );
  set_items(([
  "road":"Hard packed paving stones line the well kept road.",
  "buildings":"Small buildings of a farming communtity.  A larger barn is in the northen end of the hamlet and a winery to the south.",
  "paving stones":"Uniformily rounded and placed with care.   Looks like someone put alot of money into its their construction and upkeep.",
  ]));
  set_exits(([
  "north":ROOMS"v2.c",
  "southeast":ROOMS"v4.c",
  ]));
}
