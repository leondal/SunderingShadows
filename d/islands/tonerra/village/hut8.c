#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_terrain(HUT);
  set_travel(DIRT_ROAD);
  set_short("Enchanter");
  set_long(
@DESC
%^BOLD%^The village enchanter%^RESET%^
This is the house of the village enchanter. Here resides much of 
the power in the village forces. Many enchantments are added to
the village weapons to allow the village itself to survive the horrid 
onslaughts from the jungle.
DESC
  );
  set_listen("default","The sounds of the village reach through the walls.");
  set_smell("default","You smell burning candles.");
  set_exits(([
    "east":I_VILLAGE+"vil15",
    "west":I_VILLAGE+"vil68",
    
    
  ]));
}

void reset(){
  ::reset();
  if(!present("innara"))
    new(MON+"enchanter")->move(TO);
  if(!present("hut guard"))
    new(MON+"nativeG")->move(TO);
}
