//road6.c

#include <std.h>
#include "../../newbie.h"

inherit "/d/newbie/rooms/inherit/roadrats";
object ob;

void create(){
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_terrain(SCRUB_LANDS);
   set_travel(PAVED_ROAD);
   set_short("A wide gravel trail");
   set_long(
@JAVAMAKER
You are on a wide trail leading to the city to the northwest and
some small hills to the southeast. Open land stretches out to the
north and there is a path leading into the forest that is off to
the southwest.
JAVAMAKER
   );
   set_smell("default","You smell the fresh air of the open land.");
   set_listen("default","You hear the sound of the wind rushing across the open land.");
   set_exits(([
      "northwest":ROAD"road5",
      "east":ROAD"road7",
      "southwest":ROAD"efroad1",
   ]));
   ob = new("/d/newbie/obj/misc/1sign");
   ob->set_file("/d/newbie/obj/misc/sign3.txt");
   ob->move(TO);
}
