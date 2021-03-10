#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Avenue of Magiciana");
   set_long("%^GREEN%^Avenue of Magiciana%^RESET%^\n"+
   "You are walking on one of the main broad avenues of the city of"+
   " Aketon. The branch of this tree connects to the adjacent tree"+
   " to the northwest. To the southeast is the residential section"+
   " of Aketon, where most of the elves live.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["northwest":RPATH1+"1one65",
      "southeast":RPATH3+"3one11"]) );
}
