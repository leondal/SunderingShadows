#include <std.h>
#include "../dragon.h";

inherit ROOM;

int getmobs;

void create() {
   if(!random(3)) getmobs = 1;
   ::create();
   set_smell("default","The stench of decay and sulfur is strong in the air.");
   set_listen("default","%^RESET%^%^CYAN%^It is eerily silent all around you.");
   set_terrain(RUINS);
   set_travel(RUBBLE);
}

void reset(){
   ::reset();
   if(base_name(TO) == "/d/deku/sanctuary/inherit/btown") return;
   if(!getmobs) return;
   if(present("sanctmob")) return;
   if(random(10) < 2)   {
      new(MON+"skeleton")->move(TO);
      if(!random(3))
         new(MON+"skeleton")->move(TO);
   }
   if(random(10) < 2)   {
      new(MON+"zombie")->move(TO);
      if(!random(3))
         new(MON+"zombie")->move(TO);
   }
   if(random(10) < 2)   {
      new(MON+"skeleton")->move(TO);
      if(!random(3))
         new(MON+"mage")->move(TO);
   }
   if(random(10) < 2)   {
      new(MON+"zombie")->move(TO);
      if(!random(3))
         new(MON+"priest")->move(TO);
   }
   if(random(10) < 1)   {
   new(MON+"steel_construct")->move(TO);
   }
   if(random(10) < 1)   {
   new(MON+"bodak")->move(TO);
   }
}
