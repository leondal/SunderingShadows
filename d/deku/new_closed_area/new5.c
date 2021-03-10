#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
    set_property("light",1);
    set_property("indoors",0);
    set_short("Town of Solace");
    set_long(
@KAYLA
You seem to have entered a small town.  The small forest trail you were
on continues towards the west into a dense forest and branches off to
the north into what seems to be a small village.  The light within the
forest towards the west seems to dwindle into nothingness.
%^RED%^There is a large sign here.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/new/town1",
       "west" : "/d/deku/new/new6",
       "east" : "/d/deku/new/new4"
    ] ));
    set_items(([
       "sign":"The sign reads:  Toward the north is the lovely town of Solace.\n"+
              "Further toward the west is the everlasting Kobold Forest.\n"
    ] ));
}

void reset() {
  ::reset();
  if(!present("gnome")) {
  new("/d/deku/monster/gnome1")->move(this_object());
  return 1;
  }
}
