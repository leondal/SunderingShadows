#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(2);
  set_terrain(HUT);
  set_travel(DIRT_ROAD);
  set_short("General Store");
  set_long(
@DESC
%^BOLD%^The Tonerra General Store%^RESET%^
Inside this spacious hut, there are many items scattered
around. Mostly items made locally, they appear to be very
well-made.
DESC
  );
  set_listen("default","The sounds of the village reach through the walls.");
  set_smell("default","You smell the dampness from the recent rain.");
  set_exits(([
    "west":I_VILLAGE+"vil40",
    "east":I_VILLAGE+"vil50"
  ]));
}

void reset(){
  ::reset();
  if(!present("clerk"))
    new(MON+"bathu")->move(TO);
}
