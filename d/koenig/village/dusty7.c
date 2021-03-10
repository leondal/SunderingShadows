#include <std.h>
#include <objects.h>
#include "kai.h"

inherit ROOM;

void create() {
    ::create();
   set_terrain(GRASSLANDS);
   set_travel(DIRT_ROAD);
    set_property("light",2);
    set_property("indoors",0);
    set_short("Along a dusty road");
    set_long(
@KAYLA
This is a long dusty road, leaving Koenig to the north and leading
to a small grove, where a large stream runs through.  On the other
side of the stream you can see a large hill, perhaps even a small
mountain.
KAYLA
    );
     set_listen("default","The sound a gentle stream trickles from the south.");
    set_exits(([
       "north" : "/d/koenig/village/dusty6",
       "east" : "/d/koenig/village/house2",
       "south" : "/d/koenig/stream/stream1"
    ] ));
    set_items(([
       "mountain" : "You can't make any details out.",
       "stream" : "You can't make any details out."
    ] ));
}

void init() {
  ::init();
  do_random_encounters( ({
    MONDIR+"orc"
  }), 50,2);
}
