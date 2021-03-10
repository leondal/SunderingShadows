#include <std.h>
#include "/realms/dinji/sanctuary/dragon.h";

inherit ROOM;

void create() {
   ::create();
   set_smell("default","The stench of decay and sulfur is strong in the air.");
   set_listen("default","%^RESET%^%^CYAN%^It is eerily silent all around you.");
   set_terrain(RUINS);
   set_travel(RUBBLE);
}

void reset(){
   ::reset();
   if(random(10) < 2)
   if(!present("skeleton")) {
   new(MON+"skeleton")->move(TO);
   new(MON+"skeleton")->move(TO);
   }
   if(random(10) < 2)
   if(!present("zombie")) {
   new(MON+"zombie")->move(TO);
   new(MON+"zombie")->move(TO);
   }
}