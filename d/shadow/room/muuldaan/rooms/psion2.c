#include <std.h>
#include "../defs.h"
inherit INH+"town";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^WHITE%^A side cavern\n"
"%^RESET%^You have reached a dead-end to this corridor, that appears to be only recently cut from the "
"%^BOLD%^%^BLACK%^stone %^RESET%^itself, rather than naturally formed like the rest of the cavern.  "
"The usual piles of %^ORANGE%^trash %^RESET%^and %^BLUE%^debris %^RESET%^that cover the ground are "
"not present here, leaving the area relatively clean.  Instead, set within various niches in "
"the rock are displayed various %^BOLD%^%^CYAN%^cr%^WHITE%^y%^CYAN%^stals %^RESET%^of all shapes and colors.  "
"While quiet here, you can hear the echo of noises from the main cavern to the east.\n");
   set_listen("default","A constant stream of chatter, screeching, grumbling and general rabble drifts in from the main cavern.");

   set_exits(([
     "southeast":ROOMS"cavern11",
     "south":ROOMS"psion",
   ]));
}

void reset(){
   if(!present("grafkai"))
     find_object_or_load(MON"grafkai")->move(TO);
   switch(random(6)) {
     case 0:
     tell_room(TO,"%^ORANGE%^A small, grubby goblin passes you at a run, taking a swipe at your purse as he "
"goes.  He disappears into the cavern beyond before you can even react.%^RESET%^");
     break;
     case 1:
     tell_room(TO,"%^RED%^Grafkai watches a passing bugbear with a baleful glare.%^RESET%^");
     break;
     case 2..3:
     tell_room(TO,"%^BLACK%^%^BOLD%^Grafkai runs his gnarled hands over a crystalline shard, and then places "
"it carefully within a niche in the wall.%^RESET%^");
     break;
     case 4..5:
     tell_room(TO,"%^GREEN%^A goblin trots out of the room clutching a purchased crystal, only to be accosted "
"by a small gathering of his companions in the corridor outside.%^RESET%^");
     break;
   }
}