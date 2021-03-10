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
%^BOLD%^Entrance to the King's Hut%^RESET%^
You are inside the great hut where the native king lives.
There are guards who seem to be looking everywhere at once,
even while they are watching your every move. As you look
toward the doors leading farther into the hut, they appear
ready to move to block your way.
DESC
  );
  set_listen("default","The sounds of the village reach through the walls.");
  set_smell("default","You smell burning candles.");
  set_exits(([
    "out":I_VILLAGE+"vil85",
    "west":I_VILLAGE+"bighut2"
  ]));
  set_pre_exit_functions(({"west"}),({"go_west"}));
}

void reset(){
  ::reset();
  if(!present("hut guard"))
    new(MON+"nativeG")->move(TO);
  if(!present("hut guard 2"))
    new(MON+"nativeG")->move(TO);
  if(!present("hut guard 3"))
    new(MON+"nativeG")->move(TO);
  if(!present("hut guard 4"))
    new(MON+"nativeG")->move(TO);
}

int go_west(){
  object ob;
  int i=4;
  
  if(!ob = present("hut guard")) return 1;
  else{
    tell_room(TO,"%^BOLD%^The guard moves to block "+TPQCN+"'s way.",TP);
    tell_object(TP,"%^BOLD%^The guard moves to block your way.");
    while(ob = present("hut guard "+i--))
      ob->force_me("kill "+TPQCN);
    return 0;
  }
}
