// /d/guilds/alliance/archers.c

#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_indoors(0);
   set_light(2);
   set_property("no teleport",1);
   set_short("Castle tower");
   set_long(
@DESC
Alliance Archer tower.  You shouldn't be here.
DESC
   );
   set_exits(([
      "north":"/d/guilds/alliance/hall/hall",
      "south":"/d/guilds/alliance/hall/gate",
      "east":"/d/guilds/alliance/hall/yard",
   ]));
}

void reset() {
   object mon;

   ::reset();
    while(!present("archer 5")) {
        mon = new("/d/guilds/alliance/mon/archer");
        mon->move(this_object());
    }
}
