#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set("short","Aketon Armoury Storage Room");
   set("long","Only supplies and such here.");
}

void reset() {
   ::reset();
   if(!present("chain"))
      new(ARMORPATH+"chain")->move(TO); 
   if(!present("banded"))
      new(ARMORPATH+"banded")->move(TO); 
   if(!present("scale"))
      new(ARMORPATH+"scale")->move(TO); 
   if(!present("bronze"))
      new(ARMORPATH+"bronze")->move(TO); 
   if(!present("plate"))
      new(ARMORPATH+"plate")->move(TO); 
   if(!present("ring"))
      new(ARMORPATH+"ring")->move(TO); 
   if(!present("padded"))
      new(ARMORPATH+"padded")->move(TO); 
   if(!present("helm"))
      new(ARMORPATH+"helm")->move(TO); 
   if(!present("shield"))
      new(ARMORPATH+"shield")->move(TO); 
   if(!present("buckler"))
      new(ARMORPATH+"buckler")->move(TO); 
   if(!present("sshield"))
      new(ARMORPATH+"sshield")->move(TO); 
   if(!present("mshield"))
      new(ARMORPATH+"mshield")->move(TO); 
   if(!present("leather"))
      new(ARMORPATH+"leather")->move(TO); 
   if(!present("big fullplate"))
      new(ARMORPATH+"fullplate")->move(TO); 
   if(!present("robe"))
      new(ARMORPATH+"robe")->move(TO); 
}
