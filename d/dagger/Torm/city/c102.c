#include <std.h>
#include "../tormdefs.h"
inherit whatever;
void create()
  {
  ::create();
   set_travel(PAVED_ROAD);
   set_terrain(STONE_BUILDING);
  set_short("Warehouse yard");
  set_property("light",2);
  set_door("gates",TCITY+"c76","east","Torm masterkey");
  set_long(
  "Warehouse yard.\n"
  "  You stand in a walled off complex of warehouses."
  "  It is fairly empty here, except for the guards.  Everything seems"+
  " to be neat and orderly."+
  "  You have the feeling a lot of money passes through the buildings here."
  );
  set("night long",
  "This area is fairly free from the fog that has settled over the rest"+
  " of the city.  It is a bit gloomier here at night.  You hear"+
  " something skitter on the the metal on the other side and you really hope you don't have to find out what it is."
    "  The warehouses all stand closed and forbidding and even the guards seem to have locked themselves safely inside."
  );
  set_exits(([
  "east":TCITY"c76",
  ]));
  set_smell("default","You smell the salt sea air of the Dagger Sea.");
  set_listen("default","Far away the breakers hit the docks.");
  set_items(([
  (({"compound","walled compound"})):"  Tall walls block all but the top of a spire of a grand mansion behind them.",
  "houses":"The houses of the citizens of Torm for the most part are simple but well made structures.  All their doors are closed and locked.",
  ]));
}
void reset(){
  ::reset();
  if(query_night()) return;
  if(!present("warehouse guard",TO)){
  new(MON+"warehouseg")->move(TO);
  }
}
