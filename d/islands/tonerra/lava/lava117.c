//Changed gold vial drops to rose - Octothorpe 1/30/10

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_short("Tiled Chamber");
  set_long(
@DESC
   %^BOLD%^%^RED%^Tiled Chamber%^RESET%^
This room was crisscrossed with thin streams of lava, carving
almost perfect squares in tile like form. The black rock is cut
and molded, looking much like some grand hall.
DESC
  );
  set_items(([
   "tiles":"One, upon closer inspection looks like it is a separate piece of rock, perhaps you could pry it open."
   ]));
  
  
  set_exits(([
    "south":LAVA+"lava118",
    "southeast":LAVA+"lava116"
  ]));
}

void init(){
   ::init();
   add_action("pry","pry");
}

int found;
int pry(string str){
   if(!str || str != "tile"){
      return notify_fail("Pry what?\n");
   }

   if(found)
      return notify_fail("There is nothing in there\n");
   found = 1;
   tell_room(TO,TPQCN+" pries the tile-rock up and finds something.",TP);
   write("You find a silver ring.");
   new(OBJ+"ring4")->move(TO);
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
