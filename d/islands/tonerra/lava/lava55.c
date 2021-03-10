#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_property("no teleport",1);
   set_property("used sticks",1);
  set_light(1);
  set_short("%^BOLD%^%^RED%^Meeting area for some fire newts%^RESET%^");

  set_long("Firenewts have gathered here. You see the strider droppings You see the well cooked remains piled in a corner.");


  set_exits(([
    "northeast":LAVA+"lava54",
    "south":LAVA+"lava56"
  ]));
}

void reset(){
   ::reset();
   if(!present("firenewt")){
      new(MON+"fnewt")->move(TO);
   }
   if(!present("firenewt 2") && random(5)){
      new(MON+"fnewt")->move(TO);
   }
   if(!present("firenewt 3") && random(4)){
      new(MON+"fnewt")->move(TO);
   }
   if(!present("firenewt 4") && random(3)){
      new(MON+"fnewt")->move(TO);
   }
   if(!present("firenewt 5") && random(2)){
      new(MON+"fnewt")->move(TO);
   }
   if(!present("firenewt 6") && random(2)){
      new(MON+"fnewt")->move(TO);
   }
  }
