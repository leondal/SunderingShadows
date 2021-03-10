#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",3);
   set_property("indoors",1);
   set("short","Aketon Archery Storage Room");
   set("long","Only supplies and such here.");
}

void reset() {
   ::reset();
   if(!present("shortbow"))
      new(LRPATH+"shortbow")->move(TO);
   if(!present("arrows"))
      new(LRPATH+"arrows")->move(TO);
      new(LRPATH+"arrows")->move(TO);
   if(!present("longbow"))
      new(LRPATH+"longbow")->move(TO);
   if(!present("larrows"))
      new(LRPATH+"larrows")->move(TO);
      new(LRPATH+"larrows")->move(TO);
   if(!present("crossbow"))
      new(OPATH+"crossbow")->move(TO);
   if(!present("carrows"))
      new(OPATH+"carrows")->move(TO);
      new(OPATH+"carrows")->move(TO);
   if(!present("dcrossbow"))
      new(OPATH+"dcrossbow")->move(TO);
   if(!present("dcarrows"))
      new(OPATH+"dcarrows")->move(TO);
      new(OPATH+"dcarrows")->move(TO);
   if(!present("tcrossbow"))
      new(OPATH+"tcrossbow")->move(TO);
   if(!present("tcarrows"))
      new(OPATH+"tcarrows")->move(TO);
      new(OPATH+"tcarrows")->move(TO);
}
