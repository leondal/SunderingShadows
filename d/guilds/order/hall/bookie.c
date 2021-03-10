#include <std.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(STONE_BUILDING);
   set_travel(RUTTED_TRACK);
    set_property("indoors", 1);
    //set_property("no teleport", 1);
    set_property("light", 2);
    set_property("night light", 2);
    set_short("%^BOLD%^Guild Bookie");
    set_long(
@DESC
  %^BOLD%^%^YELLOW%^Broken room  %^RESET%^
It is obvious that this was once the office of a scribe or accountant 
of some form. The half burned remains of a desk are still in the room. 
The walls show obvious evidence that once shelves lined this room.
DESC
    );

    set_items(([
               "desk":"This desk was more a large counter. It is charred and burned now.",
       ]));
    set_exits( ([
         "west":"/d/guilds/order/hall/main.c"
      ]) );
}

void init() {
    room::init();
}
