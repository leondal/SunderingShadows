#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set("short","Aketon Garment Outlet Storage Room");
   set("long","Only supplies and such here.");
}

void reset() {
   ::reset();
   if(!present("cloak"))
      new(OPATH+"cloak")->move(TO);
   if(!present("embroidered robe"))
      new(OPATH+"e_robe")->move(TO);
   if(!present("fur cloak"))
      new(OPATH+"f_cloak")->move(TO);
   if(!present("hose leggings"))
      new(OPATH+"h_leggings")->move(TO);
   if(!present("leather girdle"))
      new(OPATH+"l_girdle")->move(TO);
   if(!present("leather gloves"))
      new(OPATH+"l_gloves")->move(TO);
   if(!present("leather pants"))
      new(OPATH+"l_pants")->move(TO);
   if(!present("riding boots"))
      new(OPATH+"r_boots")->move(TO);
   if(!present("soft boots"))
      new(OPATH+"s_boots")->move(TO);
   if(!present("silk jacket"))
      new(OPATH+"s_jacket")->move(TO);
   if(!present("sandals"))
      new(OPATH+"sandals")->move(TO);
   if(!present("shoes"))
      new(OPATH+"shoes")->move(TO);
   if(!present("tunic"))
      new(OPATH+"tunic")->move(TO);
}
