#include <std.h>
#include "/d/barriermnts/bforest/bforest.h"
inherit CROOM;
void create(){


   ::create();
      set_property("light",2);
      set_travel(GAME_TRACK);
      set_terrain(HEAVY_FOREST);
      set_pre_exit_functions(({"north","south","east","west","northeast","northwest","southeast","southwest"}),({"go_out","go_out","go_out","go_out","go_out","go_out","go_out","go_out"}));
      set_post_exit_functions(({"north","south","east","west","northeast","northwest","southeast","southwest"}),({"go_in","go_in","go_in","go_in","go_in","go_in","go_in","go_in"}));
      set_name("A path within the forest");
      set_short("%^RESET%^%^ORANGE%^A winding path within the forest%^RESET%^");
      set_long((:TO,"ldesc":));
      set_smell("default","You smell the fresh scent of pine.%^RESET%^");
      set_listen("default","With the exception of the leaves rustling in the wind, it is deadly quiet.");
      set_items(([
      ({"path","forest path","trail","game trail"}):(:TO,"lpath":),
      "mountains":(:TO,"lmountains":),
      ({"bushes","brambles"}):"%^GREEN%^Bushes and brambles lay low on the forest floor, spilling out into the pathway that you walk along while vines cling to the trees, their bushy leaves creating an overhanging that nearly blocks out all sunlight.",
       "vines":"%^GREEN%^Thick, bushy vines seem to strangle the trees as they climb upward, leaving long tendrils of leafy curtains hanging all around the path.",
      ({"trees","forest"}):(:TO,"ltrees":),  
      "leaves":(:TO,"lleaves":),    
]));
   //set_search("trees",(:TO,"search_trees":));
   //set_search("bushes",(:TO,"search_bushes":));
}
void search_trees(){  
   tell_object(TP,"%^RESET%^%^GREEN%^Looking more closely at all the trees, you notice that you can climb several of them.");
   tell_room(TO,"%^RESET%^%^GREEN%^"+TPQCN+" peers up into the trees.%^RESET%^",TP);
   return ;
}
void search_bushes(){               
   tell_object(TP,"%^RESET%^%^GREEN%^As you study the bushes carefully, you notice that you might actually be able to enter them.");
   tell_room(TO,"%^RESET%^%^GREEN%^"+TPQCN+" seems to be staring at the bushes rather intently.%^RESET%^",TP);
   return ;
}

int go_out() { 
   if(!"daemon/saving_d"->saving_throw(TP,"paralyzation_poison_death")) {
      if(random(1000) < 3){
         switch(random(2)){
         case 0:
            tell_object(TP,"%^RESET%^%^GREEN%^You slip on the fallen leaves!%^RESET%^");
            tell_room(TO,"%^RESET%^%^GREEN%^"+TPQCN+" slips on the fallen leaves!%^RESET%^",TP);
            TP->set_tripped(3,"You are trying to get to your feet.");
            break;
         case 1:
            tell_object(TP,"%^RESET%^%^ORANGE%^You snag yourself on one of the nearby bushes!%^RESET%^");
            tell_room(TO,"%^RESET%^%ORANGE%^"+TPQCN+" snags "+TP->query_objective()+"self on one of the nearby bushes!%^RESET%^",TP);
           TP->set_tripped(4,"You are still trying to get yourself free of the bush.");
           break;
         }
      return 0;
      }
   }
   return 1;
}
int go_in() { 
   if(!TP->is_class("ranger")) {
      if(random(10) < 7){
         switch(random(2)){
         case 0:
            message("info","%^RESET%^%^ORANGE%^Twigs and debris creak and snap.",nearbyRoom(ETP,1));
            break;
         case 1:
            message("info","%^RESET%^%^ORANGE%^Bushes rustle more than usual and the crunching of leaves can be heard.",nearbyRoom(ETP,2));
           break;
         }
      return 0;
      }
   }
   return 1;
}
string ldesc(string str){
   if(month(time())=="Winterstime"||month(time())=="Colddays"){
   return("%^RESET%^%^GREEN%^This %^ORANGE%^forest path %^GREEN%^can hardly be called a path at all, in fact,"
" it resembles something more along the lines of a game trail.  Huge, %^BOLD%^%^WHITE%^snow-covered %^RESET%^%^GREEN%^"
" pine trees tower above you and sway slightly in the breeze that makes its way through this mountainous valley."
" A wide array of bushes, vines and brambles spill out onto the path, some of which are almost completely bare"
" of any leaves while others are just as thick and full as ever, making it that much more difficult to get"
" through without catching yourself on them.  Despite the thickness of the forest here, a certain unease"
" proliferates throughout the air, clinging to the area like a %^BOLD%^%^BLACK%^dense fog %^RESET%^%^GREEN%^that"
" will not go away.%^RESET%^\n");
   }
   if(month(time())=="Renewal"||month(time())=="Springstime"||month(time())=="Plantingdays"){
   return("%^RESET%^%^GREEN%^This %^ORANGE%^forest path %^GREEN%^can hardly be called a path at all, in fact,"
" it resembles something more along the lines of a game trail.  Huge pine trees tower above you and sway slightly"
" in the breeze that makes its way through this mountainous valley, while young %^BOLD%^saplings %^RESET%^%^GREEN%^"
"fight for light in the thick forest floor.  A wide array of bushes, vines and brambles spill out onto the path and"
" are full of new %^BOLD%^budding leaves%^RESET%^%^GREEN%^, making it nearly impossible to get through without"
" catching yourself on one.  Despite the thickness and %^BOLD%^new growth %^RESET%^%^GREEN%^of the forest here,"
" a certain unease proliferates throughout the air, clinging to the area like a %^BOLD%^%^BLACK%^"
"dense fog %^RESET%^%^GREEN%^that will not go away.%^RESET%^\n");
   }
   if(month(time())=="Sundays"||month(time())=="Summerstime"){
   return("%^RESET%^%^GREEN%^This %^ORANGE%^forest path %^GREEN%^can hardly be called a path at all, in fact,"
" it resembles something more along the lines of a game trail.  Huge pine trees tower above you and sway slightly"
" in the breeze that makes its way through this mountainous valley, and a wide array of bushes, vines and brambles"
" spill out onto the path, making it that much more difficult to get through cleanly.  Despite the thickness"
" of the forest here, a certain unease proliferates throughout the air, clinging to the area like a %^BOLD%^%^BLACK%^"
"dense fog %^RESET%^%^GREEN%^that will not go away.%^RESET%^\n");
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"){
   return("%^RESET%^%^GREEN%^This %^ORANGE%^forest path %^GREEN%^can hardly be called a path at all, in fact,"
" it resembles something more along the lines of a game trail.  Huge pine trees tower above you and sway slightly"
" in the breeze that makes its way through this mountainous valley, while various other trees are changing %^RED%^c"
"%^ORANGE%^o%^YELLOW%^l%^RED%^o%^RESET%^%^ORANGE%^r %^GREEN%^and shedding their leaves for the upcoming winter."
"  A wide array of bushes, vines and brambles spill out onto the path, making it that much more difficult to get"
" through cleanly.  Despite the thickness of the forest here, a certain unease proliferates throughout the air,"
" clinging to the area like a %^BOLD%^%^BLACK%^dense fog %^RESET%^%^GREEN%^that will not go away.%^RESET%^\n");
   }
}
string lpath(string str){
   if(month(time())=="Winterstime"||month(time())=="Colddays"){
   return("%^RESET%^%^ORANGE%^The forest path is covered in a thick layer of %^BOLD%^%^WHITE%^snow.");
   }
   if(month(time())=="Renewal"||month(time())=="Springstime"||month(time())=="Plantingdays"){
   return("%^RESET%^%^ORANGE%^The forest path is littered with fallen leaves and is quite %^BOLD%^%^BLACK%^muddy %^RESET%^%^ORANGE%^from all the %^RESET%^melted snow %^ORANGE%^and fresh %^CYAN%^rain.");
   }
   if(month(time())=="Sundays"||month(time())=="Summerstime"){
   return("%^RESET%^%^ORANGE%^The forest path is dry and full of pine needles, making it quite slippery.");
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"){
   return("%^RESET%^%^ORANGE%^The forest path is littered with fallen leaves and is quite slippery.");
   }
}
string lmountains(string str){
   if(month(time())=="Winterstime"||month(time())=="Colddays"){
   return("%^BOLD%^%^WHITE%^Snow covered %^RESET%^%^BLUE%^mountains loom high overhead on all sides of this forest.");
   }
   else{
   return("%^RESET%^%^BLUE%^Mountains loom high overhead on all sides of this forest.");
   }
}
string ltrees(string str){
   if(month(time())=="Winterstime"||month(time())=="Colddays"){
   return("%^GREEN%^The %^BOLD%^%^WHITE%^snow covered %^RESET%^%^GREEN%^trees here grow proud and tall and are covered with thick vines whose loose leaves hang over the pathway.");
   }
   if(month(time())=="Renewal"||month(time())=="Springstime"||month(time())=="Plantingdays"){
   return("%^RESET%^%^GREEN%^The older trees here grow tall and proud and are covered with thick vines whose"
" loose leaves hang over the pathway.  The %^BOLD%^younger saplings %^RESET%^%^GREEN%^look as though they are"
" just getting a start on life and are a %^BOLD%^bright green %^RESET%^%^GREEN%^in comparison as they struggle"
" for some of that precious light.");
   }
   if(month(time())=="Sundays"||month(time())=="Summerstime"){
   return("%^RESET%^%^GREEN%^The trees here grow proud and tall and are covered with thick vines whose loose leaves hang over the pathway.");
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"){
   return("%^RESET%^%^GREEN%^Tall pine trees grow proudly in this forest and remain always green.  A few other trees though are just now beginning to change %^RED%^c%^ORANGE%^o%^YELLOW%^l%^RED%^o%^RESET%^%^ORANGE%^r %^GREEN%^and drop their leaves as the winter approaches.");
   }
}
string lleaves(string str){
   if(month(time())=="Winterstime"||month(time())=="Colddays"){
   return("%^BOLD%^%^WHITE%^You cannot see any fallen leaves through all of the snow on the ground.");
   }
   if(month(time())=="Renewal"||month(time())=="Springstime"||month(time())=="Plantingdays"){
   return("%^BOLD%^%^BLACK%^A few %^RESET%^%^GREEN%^pine needles %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^broken twigs %^BOLD%^%^BLACK%^are trampled into the muddy path.");
   }
   if(month(time())=="Sundays"||month(time())=="Summerstime"){
   return("%^RESET%^%^ORANGE%^Fallen leaves, pine needles and other debris litter the pathway, making it nearly impossible to distinguish where exactly the path is.");
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"){
   return("%^RESET%^%^RED%^M%^ORANGE%^u%^YELLOW%^l%^RED%^t%^RESET%^%^ORANGE%^i-c%^RED%^o%^YELLOW%^l%^RED%^o%^RESET%^%^ORANGE%^r%^RED%^e%^YELLOW%^d %^RESET%^%^ORANGE%^fallen leaves, %^GREEN%^pine needles %^RESET%^%^ORANGE%^and other debris litter the pathway, making it nearly impossible to distinguish where exactly the path is.");
   }
}


