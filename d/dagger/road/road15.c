#include <std.h>
#include "/d/dagger/road/short.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(OLD_MOUNTS);
   set_travel(DIRT_ROAD);
   set_light(2);
   set_indoors(0);
   set_short("The Dagger Sea coast road");
   set_long("%^CYAN%^You are very near the seaport of Torm.  You can "
      "see the city to the northeast, and a little to the north of it "
      "is Daggerdale, where the road turns inland and away from the cape of "
      "Gailden and the seaport Torm sitting within it.  To the northeast "
      "you can still see the emerald Yniam plains.  To the southeast, "
      "a grand temple stands upon an outcropping along the "
      "cliffs and overlooking the sea.\n%^RESET%^");
   set_smell("default", "You can smell the salt of the sea on the cool breeze.");
   set_listen("default", "The sound of the waves on the cliffs below float up to your ears.");
   set_items(([
      "beaches" : "Golden sand lines the beaches along the Dagger Sea.",
      "sea" : "The great waves crash against the cliffs hundreds of feet below.",
   ]));
   set_exits(([
      "northeast" : RPATH "road16",
      "southwest" : RPATH "road14",
      "temple" : "/d/magic/temples/cevahir/cevahir"
   ]));
}
