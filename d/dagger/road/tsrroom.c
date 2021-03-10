#include <std.h>
inherit ROOM;

void create(){
    ::create();
   set_property("no teleport",1);
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);
    set_short("Thorby's room");
    set_long(
      "This is thorby's room.  You aren't supposed to be here, so if you are, leave."
    );
    set_exits( (["down" : "/d/shadowgate/adv_main"]) );
}
