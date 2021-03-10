//Changed gold vial drops to rose - Octothorpe 1/30/10
//Lowered vial uses from 50 to 10.  Seemd pretty excessive. - Octothorpe 2/17/10
//fixed typos ~Circe~ 8/16/2020

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  set_long(
@DESC
   %^BOLD%^%^RED%^Storage room of some form.%^RESET%^
This appears to a be a storage room of some form. The rock
here is higher set. There are some crude crates and sacks
here filled with suppies. It is curious, for the residents
of this place surely have no need for these things.

DESC
  );
  set_items(([
   "crates":"These are full of some basic healing supplies and smoked goods.",
   "sacks":"These have some stange herbs and such, possibly for making potions.",
   ]));
  set_search("crates",(:TO,"search":));
  
  
  set_exits(([
    "east":LAVA+"lava42"
  ]));
}

void reset(){
    object ob;
   ::reset();

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


int search(string str){
   write("You find a note reading:");
   write(
@OLI
	 These should serve our lord while he heals and recovers.
OLI
   );
   return 1;
}
