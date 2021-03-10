#include <std.h>
#include "../dragon.h";

inherit BSTUDY;

int items;

void create() {
items = 1;
   ::create();
   set_exits( ([
      "door" : TOWER+"balcony02",
   ]) );
   set_door("door",TOWER+"balcony02","door","tower key");
   set_search("default", "There is not much difference, between this study and the other studys, except the daggers on the target behind the door.");
   set_search("papers", "None of the papers look important.");
   set_search("target", (: TO, "searching" :) );
}

void searching () {
object ob;
   if(!items) {
      write("You find nothing.");
      return;
   }
   write("%^BOLD%^%^BLUE%^You find a nice dagger!");
   tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" finds a nice dagger!",TP);
   ob = new(OBJ+"dagger")->move(TO);
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

