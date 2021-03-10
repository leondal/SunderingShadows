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
%^BOLD%^\tVillage guard meeting room%^RESET%^
This room is littered with the scrappings of food and rubbish the
seem typical of guard houses every where. Here the village guards
however are quite alert and never lax about their duty. They know that
failure means being fed to the voice of the volcano.
DESC
  );
  set_listen("default","The sounds of the village reach through the walls.");
  set_smell("default","You smell burning candles.");
  set_exits(([
    "west":I_VILLAGE+"vil36",
    "east":I_VILLAGE+"vil55"
    
  ]));
}

void reset(){
  ::reset();
  if(!present("hut guard"))
    new(MON+"nativeG")->move(TO);
  if(!present("hut guard 2"))
    new(MON+"nativeG")->move(TO);
}
