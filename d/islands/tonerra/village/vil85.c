#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_terrain(VILLAGE);
  set_travel(DIRT_ROAD);
  set_short("A jungle village");
  set_long(
@DESC
You are directly in front of the entrance to the largest
hut in the village. There are guards blocking the entrance,
and they are eying you warily but have not made a move. You 
notice that people are beginning to take more notice of you 
the closer you get to the entrance.
DESC
  );
  set_indoors(0);
  set_light(2);
  set_listen("default","As you approach the hut, everything goes quiet.");
  set_smell("default","You smell the recently fallen rain and the moisture in the air.");
  set_exits(([
	      "enter":I_VILLAGE+"bighut1",
	      "east":I_VILLAGE+"vil71"
  ]));
  set_pre_exit_functions(({"enter"}),({"go_enter"}));
}

void reset(){
  ::reset();
  if(!present("hut guard")){
    new(MON+"nativeG")->move(TO);
     new(MON+"nativeG")->move(TO);
  }
}

int go_enter(){
  if(!present("hut guard")) return 1;
  else{
    tell_object(TP,"%^BOLD%^The guards will not let you pass!");
    return 0;
  }
}
