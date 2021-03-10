#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^The path becomes a bit wider here as you enter from the thick forest."+
      " The peaceful sounds of village life begin to fill the air around you, but the growth"+
      " of the forest seems unhindered. The builders of this village built around"+
      " and within the trees. There are a few platforms sticking out from a couple of trees"+
      " far above your head. This path leads east to a tall tree,"+
      " west into the village, and to the paths that go back into the thick of the forest."
   );
   set_items( ([
      "tree":"This is the furthest occupied tree to the east by far. There is a small path leading to it.", 
   ]) );
   set_exits( ([
      "west" : TOWN+"road03",
      "east" : TOWN+"road02",
      "northeast" : PATH+"path12",
      "southeast" : PATH+"path13",
   ]) );
}

void reset()
{
   ::reset();
   if(!present("guard")) {
    new(MON+"elguard")->move(TO);
    new(MON+"elguard")->move(TO);
   }
   if(random(10) <4)
   if(!present("laucian")) {
   find_object_or_load(MON+"laucian")->move(TO);
   }
}

