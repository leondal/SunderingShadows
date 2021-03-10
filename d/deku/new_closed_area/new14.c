#include <std.h>
#include <objects.h>

inherit ROOM;

int open;
void create() {
    room::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",0);
    set_short("Kobold Forest");
    set_long(
@KAYLA
You have stumbled upon a dead end.  Although the path seems to stop
the forest seems to extend in all directions.  The light tries
to penetrate through the dark leaves of the overpowering trees.
There is a large beehive within one of the trees here.
KAYLA
    );
    set_exits(([
       "west" : "/d/deku/new/new13"
    ] ));
    set_listen("default","Peculiar, the forest is deadly quiet.");
    set_items(([
        "beehive":"Its looks like an enormous hive for lots of killer bees."
    ] ));
  open = 0;
}

void reset() {
  ::reset();
  if(!present("bear")) {
    new("/d/deku/monster/bear")->move(this_object());
  }
  if(open) {
    open = 0;
    return 1;
  }
}

void init() {
  ::init();
  add_action("search_hive","search");
}

int search_hive(string str) {
  object bottle;
  if(!str) {
    write("Search what!");
    return 0;
  }
  if(str != "beehive") {
    return 0;
  }
  if(open) {
   write("You search the beehive and notice that the honey has been removed.");
    return 0;
  }
  write("You search the beehive and there are bees still within the hive.");
  write("You manage to retrieve some honey which you make a healing potion.");
  write("But you also awaken a swarm of killer bees.");
  bottle = new("/d/common/obj/potion/heal");
  bottle->move(this_player());
  new("/d/deku/monster/bee")->move(this_object());
  new("/d/deku/monster/bee")->move(this_object());
  new("/d/deku/monster/bee")->move(this_object());
  open = 1;
}
