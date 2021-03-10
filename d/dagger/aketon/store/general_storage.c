#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set("short","Aketon General Store Storage Room");
   set("long","Only supplies and such here.");
}

void reset() {
   ::reset();
   if(!present("chest"))
      new(MISCPATH+"chest")->move(TO);
   if(!present("schest"))
      new(MISCPATH+"schest")->move(TO);
   if(!present("sack"))
      new(MISCPATH+"sack")->move(TO);
   if(!present("ssack"))
      new(MISCPATH+"ssack")->move(TO);
   if(!present("pouch"))
      new(MISCPATH+"pouch")->move(TO);
   if(!present("spouch"))
      new(MISCPATH+"spouch")->move(TO);
   if(!present("climb_tool"))
      new(MISCPATH+"climb_tool")->move(TO);
   if(!present("basket"))
      new(MISCPATH+"basket")->move(TO);
   if(!present("sbasket"))
      new(MISCPATH+"sbasket")->move(TO);
   if(!present("torch"))
      new(MISCPATH+"torch")->move(TO);
   if(!present("lantern"))
      new(MISCPATH+"lantern")->move(TO);
   if(!present("oil"))
      new(MISCPATH+"oil")->move(TO);
   if(!present("beacon"))
      new(MISCPATH+"beacon")->move(TO);
   if(!present("bullseye"))
      new(MISCPATH+"bullseye")->move(TO);
   if(!present("flint"))
      new(MISCPATH+"flint")->move(TO);
   if(!present("lkchest"))
      new(MISCPATH+"lkchest")->move(TO);
}
