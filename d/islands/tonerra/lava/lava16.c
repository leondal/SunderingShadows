//Changed gold vial drops to rose - Octothorpe 1/30/10
//Lowered vial uses from 50 to 10.  Seemd pretty excessive. - Octothorpe 2/17/10

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_short("Piles of Junk");
  set_long(
@DESC
   %^RED%^%^BOLD%^Piles of collected junks%^RESET%^
This room is full of piles of stuff. Stone work, bits of
broken sculpture. Mixed in you might find some supplies,
but what else might be in this room? Who put this stuff here?
DESC
  );
  set_items(([
   "piles":"These are piles of broken stone and wood. Wonder what's burried in them."
   ]));
  set_search("default","Search what");
  set_search("piles",(:TO,"search_em":));
  
  
  set_exits(([
    "south":LAVA+"lava15"
  ]));
}

int found;

int search_em(string str){
   if(!found){
      tell_room(TO,"BOLD%^"+TPQCN+" has found something",TP);
      write("You find a single slightly chipped silver ring.");
      new(OBJ+"ring1")->move(TO);
      found = 1;
   } else {
      write("You find nothing");
   }
   return 1;
}

void reset(){
   object ob;
   ::reset();

   found = 0;

   if(!present("follower")){
      new(MON+"followerg")->move(TO);
       new(MON+"followerg")->move(TO); 
       new(MON+"followerg")->move(TO); 
      new(MON+"followerg")->move(TO);
   }

   if(!present("vial")){
     ob = new("/d/common/obj/potion/advanced_heal");
        ob->set_uses(10);
     ob->move(TO);
     }
   if(!present("vial 2")){
     ob = new("/d/common/obj/potion/advanced_heal");
        ob->set_uses(10);
     ob->move(TO);
   }


}
