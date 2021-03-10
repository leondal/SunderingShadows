//bcliff6
#include <std.h>
#include <rooms.h>
#include <daemons.h>
#include "../bpeak.h"
inherit ROOM;




void create(){
::create();
   set_property("light",2);
   set_travel(GAME_TRACK);
   set_terrain(ROCKY);
   set_name("%^RESET%^The bottom of a %^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^WHITE%^i%^BLACK%^f%^%RESET%^f");
   set_short("%^RESET%^The bottom of a %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^k%^RESET%^y c%^BOLD%^%^WHITE%^l%^BLACK%^i%^RESET%^f%^BOLD%^%^BLACK%^f%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^GREEN%^The scent of pine from the forest below wafts up here.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLUE%^The roar of the waterfall can be heard%^RESET%^.");
   set_items(([
   "cliff":"%^BOLD%^%^BLACK%^The cliff towers more than four hundred feet above you and gives off an eerie feeling.",
   "shadow":"%^BOLD%^%^BLACK%^The shadow of the cliff falls over the ravine below.%^RESET%^",
   "rocks":"Large rocks line the path, making it difficult to maneuver around here.  Some are merely a few feet in diameter, while others stand to nearly six feet tall.",
   "path":"%^RESET%^%^ORANGE%^The path is worn out and looks to be seldom used.  In fact, it down right looks abandoned.%^RESET%^",
   ({"trees","pine trees","tree","pines"}):"%^RESET%^%^GREEN%^A few pine trees cling to life here as they attempt to grow amongst the rocks.  Their needles are weak and the branches fairly bare, but somehow they still grow to be quite tall.%^RESET%^",
   "valley":"%^RESET%^%^GREEN%^The valley is filled with a lush forest that grows around a winding river.%^RESET%^",
   "forest":"%^RESET%^%^GREEN%^The forest grows around a winding river and looks to be quite healthy and peaceful.%^RESET%^",
   "river":"%^BOLD%^%^BLUE%^A river winds its way through the base of the valley.%^RESET%^",
   "waterfall":"%^BOLD%^%^CYAN%^The waterfall pours out of the cliff nearly fifty feet above you and drops over one hundred feet before it finally hits the ground below you.%^RESET%^",
   "bridge":"%^RESET%^%^ORANGE%^The bridge here crosses the ravine created by the waterfall and connects the two sides of the path.  It looks to be quite sturdy.%^RESET%^",
   "pool":"%^BOLD%^%^BLUE%^The waterfall plummets down into a deep, turning pool below you.  The overflow feeds a river that winds its way through the forest.%^RESET%^",
   ]));
   set_exits((["northeast":INRMS+"bcliff5","bridge":INRMS+"bridge"]));
   set_pre_exit_functions(({"bridge"}),({"go_out"}));
   find_object_or_load(INRMS+"bledge");
}
string ldesc(string str){
   return("%^RESET%^The path abruptly stops here.  A %^BOLD%^%^CYAN%^waterfall"
" %^RESET%^pours out of the cliff above you and drops down more than one hundred"
" and fifty feet to the %^BLUE%^deep pool %^RESET%^at the bottom of the cliff"
" below.  A %^ORANGE%^wooden bridge %^RESET%^is built here to cross over to the"
" other side and looks to be fairly sturdy.  On the other side of the fall the"
" path continues to hug the mountainside and seems to wrap around to the northwest,"
" giving you the indication that you are now at the southernmost tip of this cliff."
"\n");
}
//ouch function gets called by two giants in another room if the check for living people here is successful
void ouch(){
   object *livings,*inven;
   int i,j;     
   inven = all_inventory(TO);
   livings = filter_array(inven,"is_non_immortal_player",FILTERS_D);
   j= sizeof(livings);
   tell_room(TO,"%^BOLD%^%^BLACK%^The shadow of movement can be seen on the cliff above you and then all of the sudden rocks start pummeling down towards you!%^RESET%^");
   for(i=0;i<j;i++){
      if((random(4)+16) > livings[i]->query_stats("dexterity")){
         tell_room(TO,"%^BOLD%^%^BLACK%^"+livings[i]->query_cap_name()+" is hit by the rocks!",livings[i]);
         tell_object(livings[i],"%^BOLD%^%^BLACK%^Ouch ouch ouch!  Rocks are being thrown down at you from the cliff above and you are getting hit!");
         livings[i]->do_damage("torso",roll_dice(3,15));
         livings[i]->add_attacker(TO);
         livings[i]->continue_attack();
         livings[i]->remove_attacker(TO);                 
       }
       else
       {
       tell_room(TO,"%^BOLD%^%^BLACK%^"+livings[i]->query_cap_name()+" ducks out of the way of the falling rocks!",livings[i]);
       tell_object(livings[i],"%^BOLD%^%^BLACK%^Damn, run run run!  Rocks are falling everywhere and you are doing everything in your power to not get hit!");
       }
    }
}
int go_out() { 
   if(present("hill giant")){
      write("%^BOLD%^%^BLACK%^The giant blocks the passage to the bridge!");
   return 0;
   }
   else{
   return 1;
   }  
}
void reset() {
  ::reset();
  if(!present("giant")){
     new(TMONDIR+"hillg3.c")->move(TO);
     new(TMONDIR+"hillg3.c")->move(TO);
  }
}


