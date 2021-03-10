//bcliff
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit ROOM;
int safe;


void create(){
::create();
   set_property("light",2);
   set_travel(GAME_TRACK);
   set_terrain(ROCKY);
   set_name("%^RESET%^The bottom of a %^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^WHITE%^i%^BLACK%^f%^%RESET%^f");
   set_short("%^RESET%^The bottom of a %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^k%^RESET%^y c%^BOLD%^%^WHITE%^l%^BLACK%^i%^RESET%^f%^BOLD%^%^BLACK%^f%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","It smells of %^BOLD%^%^BLACK%^d%^RESET%^u%^BOLD%^%^BLACK%^st, %^RESET%^%^ORANGE%^dirt %^RESET%^and %^BOLD%^%^BLACK%^grime.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLACK%^The nearby howls of wolves can be heard from somewhere on the cliffs above you.");
   set_items(([
   "cliff":"%^BOLD%^%^BLACK%^The cliff towers more than five hundred feet above you and gives off an eerie feeling.  Once in a while a very large shadow can be seen up there, but you have no idea what that is.%^RESET%^",
   "shadow":"%^BOLD%^%^BLACK%^The shadow of the cliff gives this area plenty of shade.%^RESET%^",
   "rocks":"Large rocks line the path, making it difficult to maneuver around here.  Some are merely a few feet in diameter, while others stand to nearly six feet tall.  One of the rocks to the southwest looks strange.",
   "path":"%^RESET%^%^ORANGE%^The path is worn out and looks to be seldom used.  In fact, it down right looks abandoned.%^RESET%^",
   ({"trees","pine trees","tree","pines"}):"%^RESET%^%^GREEN%^A few pine trees cling to life here as they attempt to grow amongst the rocks.  Their needles are weak and the branches fairly bare, but somehow they still grow to be quite tall.%^RESET%^",
   ({"rock","pebble"}):"One small pebble seems to be in the way.  It's not large nor does it look dangerous, but you could probably move it if you wanted to.",
   ]));
   set_search("default", "%^ORANGE%^Nothing here really looks interesting.%^RESET%^");
   set_exits((["southwest":INRMS+"bcliff2","north":INRMS+"t7"]));
   set_pre_exit_functions(({"southwest"}),({"pebble"}));
   safe=0;
}
string ldesc(string str){
   return("%^RESET%^This is the bottom of a tall cliff that hovers over five hundred"
" feet above you.  The %^BOLD%^%^BLACK%^shadow %^RESET%^of the cliff lends plenty of"
" %^BOLD%^%^BLACK%^shade %^RESET%^to the area, but also gives you an eerie feeling."
"  Large rocks line the path and a few %^GREEN%^pine trees %^RESET%^cling to life"
" amongst them.  The path itself looks worn out and unused but continues to the"
" southwest, hugging the side of the mountain.  Once in a while a strange breeze"
" blows through, carrying an equally strange smell that makes you wonder where you"
" are headed.  Little life exists here as not many creatures would find this place"
" inviting.%^RESET%^\n");
} 
int pebble(){
   if(safe){
    return 1;
   }
      tell_object(TP,"%^BOLD%^%^BLACK%^As you attempt to continue, you trip over a small rock and send it rolling down the path.  The noise from the rock seems to have alerted something above you as shouting along with the howling of wolves can now be heard%^RESET%^.");
      tell_room(ETP,""+TPQCN+" tries to continue but trips over a small rock, sending it rolling down the path.  The noise apparently alerted something above you, as shouting and the sounds of howling wolves can now be heard above you.%^RESET%^",TP);
      find_object_or_load(INRMS+"kgroom")->set_open("gate",1);
      find_object_or_load(INRMS+"wolfpen")->set_open("gate",1);
   return 1;
}
void init(){
  ::init();
  add_action("move","move");
}
int move(string str){
   if(str == "pebble"||str=="rock"||str=="small rock"){
      if(safe == 0) {  
         tell_object(TP,"%^RESET%^%^ORANGE%^You very carefully reach down and move the rock out of the way.%^RESET%^");
         tell_room(TO,"%^RESET%^%^ORANGE%^"+TPQCN+" very carefully moves the rock out of the way%^RESET%^.",TP);
         safe=1;
      return 1;
      }
      if(safe == 1) {  
         tell_object(TP,"%^RESET%^%^ORANGE%^There doesn't seem to be any other rocks in the way.%^RESET%^");
      return 1;
      }
   }
}

void reset() {
  ::reset();
  if (safe) safe=0;
}
