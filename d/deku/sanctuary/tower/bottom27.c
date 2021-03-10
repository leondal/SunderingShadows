#include <std.h>
#include "../dragon.h";

inherit BBVAULT;

int items;

void create() {
items = 1;
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^This room is completely empty. There is nothing"+
      " here except the floor, walls, ceiling, and the small signs of"+
      " inhabitance by small filthy creatures."
   );
   set_items( ([
      "floor" : "The floor is cold, damp, and bare. The only thing there is a grate to stop flooding.",
      "walls" : "The walls are smooth and without features.",
      "ceiling" : "The ceiling is just as empty as the walls.",
      "grate" : "When you look into the grate you think you see something sparkle.",
   ]) );
   set_exits( ([
      "door" : TOWER+"bottom13",
   ]) );
   set_door("door",TOWER+"bottom13","door","cellar key");
   set_search("grate", (: TO, "searching" :) );
}

void searching() {
object ob;
   if(!items) {
      write("You find nothing.");
      return;
   }
   write("%^BOLD%^%^YELLOW%^You find some gold coins!");
   tell_room(TO,"%^BOLD%^%^YELLOW%^"+TPQCN+" finds some gold coins!",TP);
   ob = new("/std/obj/coins");
   ob->set_money("gold", random(10000)+2000);
   ob->move(TO);
   items = 0;
   return;
}

void reset() {
   ::reset();
   if(!present("goblin")) {
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
      new(GOBO)->move(TO);
   }
}
