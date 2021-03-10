//Changed gold vial drops to rose - Octothorpe 1/30/10
//Lowered vial uses from 50 to 10.  Seemed pretty excessive. - Octothorpe 2/17/10

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit LAVAH;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  
  set_long(
@DESC
   %^BOLD%^%^RED%^Some type of storage room
This seems to be some form of storage room. Crates line the rooms
Most are decaying slightly. There are sacks that have split. You
can't figure out what or who would need a storage area of this
type. You still feel the lava flowing beneath you, but the rock
here seems solid.
DESC
  );
  set_items(([
  "crates":"These are full of some basic healing supplies, and some smokes goods.",
  "sacks":"Tese have some stange herbs and such, possibly for making potions.",
  ]));
 set_search("crates",(:TO,"search":));

  
  
  set_exits(([
    "north":LAVA+"lava93",
    "southwest":LAVA+"lava170",
    "southeast":LAVA+"lava91"
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

