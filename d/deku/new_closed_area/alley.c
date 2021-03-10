#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
   set_terrain(VILLAGE);
   set_travel(BACK_ALLEY);
    set_property("light",1);
    set_property("indoors",0);
    set_short("Town of Solace");
    set_long(
@KAYLA
You are in an alleyway within the city. It is dark and very nasty.
KAYLA
    );
    set_exits(([
       "north" : "/d/deku/new/town3"
    ] ));
set_listen("default","You hear some faint music to the west.");
    set_items(([
    ] ));
}

void init() {
  ::init();
  do_random_encounters(({"/d/deku/monster/rat"}),100,15);
}
