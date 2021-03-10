//Changed gold vial drops to rose - Octothorpe 1/30/10

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_short("Immense cavern");
  set_long(
@DESC
   %^BOLD%^%^RED%^Immense cavern%^RESET%^
This is an extremely large cavern. It is basically empty
except for a large pillar in the middle. The pillar reach
high to the top of the cavern. Who or what would build such
a pillar in the middle of a lava tube?
DESC
  );
  set_items(([
   "pillar":"This is an ornately carved pillar, in the center about 20 feet up you see a silver ring embedded in the pillar.",
   "ring":"The ring is about 20 feet up, more then likely you will have to climb the pillar."
   ]));
  
  
  set_exits(([
    "northeast":LAVA+"lava133",
    "east":LAVA+"lava135"
  ]));
}

void init(){
   ::init();
   add_action("climb","climb");

}

int taken;
int climb(string str){
   if(!str || str != "pillar")
      return notify_fail("Climb What?");

   if(taken){
      write("You climb the pillar but discover the ring is gone.");
      return 1;

   }

   taken = 1;
   write("You climb the pillar, and reach to grab the ring.");
   write("You manage to knock it loose but you fall to the ground in the process");
   TP->do_damge("torso",roll_dice(4,5));
   new(OBJ+"ring2")->move(TO);
   return 1;

}

void reset(){
   object ob;
   ::reset();
   taken = 0;

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
