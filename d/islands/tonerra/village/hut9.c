#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_terrain(HUT);
  set_travel(DIRT_ROAD);
  set_short("Witch Doctor");
  set_long(
@DESC
%^BOLD%^The Tonerra Witch Doctor%^RESET%^
	This dark hut, is dimly lit with dancing flames. The walls are
covered with paintings that carry a common theme of death and fire. 
The rough tapestries are dark and fearful. This is a richly
ornate hut. The native here is important but very religious
DESC
  );
  set_listen("default","The sounds of the village reach through the walls.");
  set_smell("default","You smell burning candles.");
  set_exits(([
    "west":I_VILLAGE+"vil74",
    
  ]));
}

void reset(){
  ::reset();
  if(!present("doctor"))
    new(MON+"nativewd")->move(TO);
  if(!present("hut guard"))
    new(MON+"nativeG")->move(TO);
}
