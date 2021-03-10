#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_terrain(HUT);
  set_travel(DIRT_ROAD);
  set_short("King's Hut");
  set_long(
@DESC
%^BOLD%^The King's Hut%^RESET%^
You are inside the great hut where the native king lives.
Animal skins cover the floor and plants and trees surround
the room. The walls are covered with decorative weavings.
A large throne sits centered on one wall.
DESC
  );
  set_listen("default","The sounds of the village reach through the walls.");
  set_smell("default","You smell burning candles.");
  set_exits(([
    "east":I_VILLAGE+"bighut1",
  ]));
}

void reset(){
  ::reset();
  if(!present("native king"))
    new(MON+"nativek")->move(TO);
}
