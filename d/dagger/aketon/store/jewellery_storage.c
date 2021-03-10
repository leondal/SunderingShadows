#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set("short","Aketon Jewellery Storage Room");
   set("long","Only supplies and such here.");
}

void reset() {
   ::reset();
   if(!present("king's platinum band"))
      new(OPATH+"kp_band")->move(TO);
   if(!present("diamond engagement ring"))
      new(OPATH+"de_ring")->move(TO);
   if(!present("heavily jeweled ring"))
      new(OPATH+"hj_ring")->move(TO);
   if(!present("slight gold band"))
      new(OPATH+"sg_band")->move(TO);
   if(!present("silver ornate ring"))
      new(OPATH+"so_ring")->move(TO);
   if(!present("gem"))
      new("/d/islands/tonerra/obj/gem")->move(TO);
   if(!present("gem 2"))
      new("/d/islands/tonerra/obj/gem")->move(TO);
   if(!present("gem 3"))
      new("/d/islands/tonerra/obj/gem")->move(TO);
   if(!present("gem 4"))
      new("/d/islands/tonerra/obj/gem")->move(TO);
   if(!present("gem 5"))
      new("/d/islands/tonerra/obj/gem")->move(TO);
   if(!present("pouch"))
      new("/d/islands/tonerra/obj/gpouch")->move(TO);
   if(!present("pouch 2"))
      new("/d/islands/tonerra/obj/gpouch")->move(TO);
}
