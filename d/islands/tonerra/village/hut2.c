#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_terrain(HUT);
  set_travel(DIRT_ROAD);
  set_short("Food Storage");
  set_long(
@DESC
%^BOLD%^The village food storage%^RESET%^
This is where the food of the village is prepared. You
may be able to buy something to eat here. There are two
large pots filled with food.
DESC
  );
  set_listen("default","The sounds of the village reach through the walls.");
  set_smell("default","You smell cooking food.");
  set_items(([
    "pots":"There are two pots filled with food.",
    "pot":"A tasty <leg of aurumvorax> is cooking here.",
    "pot 1":"A tasty <leg of aurumvorax> is cooking here.",
    "pot 2":"A <gargantua stew> is cooking here. It looks very good."
  ]));
  set_exits(([
    "west":I_VILLAGE+"vil49",
  ]));
}

void reset(){
  ::reset();
  if(!present("chumba"))
    new(MON+"chumba")->move(TO);
}
