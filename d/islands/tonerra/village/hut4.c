#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_terrain(HUT);
  set_travel(DIRT_ROAD);
  set_short("Water Storage");
  set_long(
@DESC
%^BOLD%^The village water storage%^RESET%^
This is where the water of the village is stored. You
may be able to buy some water here. 
DESC
  );
  set_listen("default","The sounds of the village reach through the walls.");
  set_smell("default","You smell cooking food.");
  set_exits(([
    "north":I_VILLAGE+"vil63",
  ]));
}

void reset(){
  ::reset();
  if(!present("wamba"))
    new(MON+"wamba")->move(TO);
}
