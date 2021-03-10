//city_outside - inheritable file for Seneca's city streets.
//Hopefully this will make upgrades to the city easier.  ~Circe~ 5/31/07
#include <std.h>
#define MONS "/d/attaya/newseneca/mon/"+

inherit ROOM;

void create(){
   ::create();
   set_name("An Unnamed Room!");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_listen("default","The call of a seagull rises above the bustle of the streets.");
   set_smell("default","A faint hint of the sea stirs on the breeze.");
}

void reset(){
   ::reset();
   if(!present("worker") && !random(6)){
      switch(random(4)){
         case 0:  new(MONS"worker1")->move(TO);
                  break;
         case 1:  new(MONS"worker2")->move(TO);
                  break;
         case 2:  new(MONS"worker3")->move(TO);
                  break;
         default: new(MONS"worker4")->move(TO);
                  break;
      }
   }
}