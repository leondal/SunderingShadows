#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Sanctuary Pub");
    set_long("%^BOLD%^%^BLUE%^
The floor of this building is littered with the remains of several broken
shelves and tables.  Strewn along the base of a repaired section of wall
are the sundered remnants of an old fireplace.  A heavy iron cauldron 
rests in the corner behind the door.  There are no furnishings, just pools
of water, warped floorboards, broken weapons, and holes.
    ");
    set_exits(([
       "west" : "/d/dragon/town/roadSW2"
    ] ));
    set_items(([
    ] ));
}

void reset() {
  ::reset();
  if(!present("drunk")) {
    new("/d/dragon/mon/drunk")->move(this_object());
  }
}
