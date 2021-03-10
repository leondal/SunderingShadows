#include <std.h>
#include "../dragon.h";

inherit BSTUDY;

int items;

void create() {
items = 1;
   ::create();
   set_exits( ([
      "door" : TOWER+"balcony01",
   ]) );
   set_door("door",TOWER+"balcony01","door","tower key");
   set_search("papers", (: TO, "searching" :) );
}

void searching () {
object ob;
   if(!items) {
      write("You find nothing.");
      return;
   }
   write("You find a sheet of paper that looks intresting.");
   tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" picks up a sheet of paper from the stack.",TP);
   ob = new(OBJ+"paper03")->move(TO);
   items = 0;
   return;
}

void reset() {
   ::reset();
   if(!present("apprentice")) {
      new(MON+"apprentice")->move(TO);
      new(MON+"apprentice")->move(TO);
   }
}
