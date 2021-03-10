#include <std.h>

inherit ROOM;
object ob;

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("Cave-in");
    set_long(
      "This used to be the main meeting room of the Legion, now it is a pile of rubble.  You can see what used to be furniture under the cave-in, but now it is crumbled and destroyed beyond any hope of repair.  The once glorious room this was is now nothing more than a pile of rubble."
    );
    set_smell("default", "You think you can smell old smoke through the dust.");

    set_items( ([
      ]) );

    set_exits( ([
	"south" : "/d/guilds/legion/hall/hub"
      ]) );

}

