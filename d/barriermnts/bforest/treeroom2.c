//treeroom inherit
#include <std.h>
#define rdstuff "/d/common/daemon/randstuff_d"
#include "bforest.h"
inherit ROOM;
int searched;

void create(){


   ::create();
      set_property("light",2);
      set_travel(GAME_TRACK);
      set_terrain(HEAVY_FOREST);
      set_name("High in the trees");
      set_short("%^RESET%^%^GREEN%^High within a tree%^RESET%^");
      set_long((:TO,"ldesc":));
      set_smell("default","The smell of pine is overwhelming.%^RESET%^");
      set_listen("default","With the exception of the leaves rustling in the wind, it is deadly quiet.");
      set_items(([
      "mountains":(:TO,"lmountains":),
      ({"bushes","brambles"}):"%^GREEN%^Far below, the bushes and brambles grow out of control, densely covering the forest floor.  There are only a few visible game paths that manage to meander their way through it all.",
       "vines":"%^GREEN%^Thick, bushy vines seem to strangle the trees as they climb upward, leaving long tendrils of leafy curtains hanging everywhere and obscuring the view.",
      ({"trees","forest"}):(:TO,"lforest":),  
      "leaves":"%^RESET%^%^GREEN%^The leaves have been pulled tightly together into a little shelter that would provide both excellent camoflauge, and a great place to hide things.",    
]));
      set_search("leaves",(:TO,"search_pile":));
      set_pre_exit_functions(({"north","south","east","west","northeast","northwest","southeast","southwest"}),({"GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor","GoThroughDoor"}));
}
int GoThroughDoor() {
   if((random(24)-5) > TP->query_stats("dexterity")&&(random(5)+10) > TP->query_stats("strength")) {
	tell_object(TP,"%^RESET%^%^GREEN%^You make a flying leap for another tree but miss!");
      tell_room(TO,"%^RESET%^%^GREEN%^"+TPQCN+" takes a step back and makes a flying leap for another tree and misses!", TP);
      if (!TP->query_ghost()){
         tell_room(find_object_or_load(query_exit("down")),"%^BOLD%^%^GREEN%^A loud snap can be heard from somewhere high above you as "+TPQCN+" comes crashing down from the trees!%^RESET%^",TP);
         TP->move_player(query_exit("down"));
         TP->do_damage("torso",roll_dice(10,10));                 
      }
   return 0;
   } 
   else {
	tell_object(TP,"%^RESET%^%^GREEN%^You easily jump to another tree.");
      tell_room(TO,"%^RESET%^%^GREEN%^"+TPQCN+" jumps easily to another tree.", TP);
   return 1;
   }
}
string ldesc(string str){
   if(month(time())=="Winterstime"||month(time())=="Colddays"){
   return("%^RESET%^%^GREEN%^The %^BOLD%^%^WHITE%^snow-covered %^RESET%^%^GREEN%^branches of this magnificent"
" pine tree flatten out here, creating a fairly stable place to sit and rest.  The view of the surrounding forest"
" is absolutely amazing from up here.  %^BLUE%^Majestic %^BOLD%^%^WHITE%^snow-covered %^RESET%^%^BLUE%^mountains"
" loom %^GREEN%^off in the distance, completely surrounding the valley.  Most of the trees that grow here appear"
" to be evergreens of some sort or another, but a few leafless trees can be seen amongst them, indicating"
" that at least a few other varieties grow here as well.  All of the forest is covered in a thick blanket of"
" %^BOLD%^%^WHITE%^snow, %^RESET%^%^GREEN%^making it even more %^BOLD%^%^WHITE%^ch%^CYAN%^i%^WHITE%^lly"
" %^RESET%^%^GREEN%^than usual.%^RESET%^\n");
   }
   if(month(time())=="Renewal"||month(time())=="Springstime"||month(time())=="Plantingdays"){
   return("%^RESET%^%^GREEN%^The branches of this magnificent pine tree flatten out here, creating a fairly stable"
" place to sit and rest.  The view of the surrounding forest is absolutely amazing from up here.  %^BLUE%^Majestic"
" mountains %^GREEN%^loom off in the distance, their %^RESET%^snow-covered peaks %^GREEN%^"
"completely surround this valley.  Most of the trees that grow here appear to be evergreens, but a few dapples"
" of %^BOLD%^%^MAGENTA%^pink buds %^RESET%^%^GREEN%^and %^BOLD%^new leaves %^RESET%^%^GREEN%^on the"
" barer trees would indicate that at least a few other varieties call this valley home as well.%^RESET%^\n");
   }
   if(month(time())=="Sundays"||month(time())=="Summerstime"){
   return("%^RESET%^%^GREEN%^The branches of this magnificent pine tree flatten out here, creating a fairly"
" stable place to sit and rest.  The view of the surrounding forest is absolutely stunning from up here.  "
"%^BLUE%^Majestic mountains %^GREEN%^loom off in the distance, their %^BOLD%^%^WHITE%^snow-covered peaks %^RESET%^"
"%^GREEN%^completely surround this valley.  Most of the trees that grow here appear to be evergreens, but a few"
" other types call this valley home as well.%^RESET%^\n");
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"){
   return("%^RESET%^%^GREEN%^The branches of this magnificent pine tree flatten out here, creating a fairly stable"
" place to sit and rest.  The view of the surrounding forest is absolutely amazing from up here."
"  %^BLUE%^Majestic mountains %^GREEN%^loom off in the distance, their %^BOLD%^%^WHITE%^snow-covered peaks %^RESET%^"
"%^GREEN%^completely surround this valley.  Most of the trees that appear to be evergreens, but splashes of"
" %^ORANGE%^orange, %^RED%^red, %^GREEN%^and %^YELLOW%^yellow %^RESET%^%^GREEN%^can be seen covering a couple of the"
" other trees, indicating that at least a few other varieties call this valley home as well.%^RESET%^\n");
   }
}
string lforest(string str){
   if(month(time())=="Winterstime"||month(time())=="Colddays"){
   return("%^GREEN%^The forest is thick and dense, but unusually quiet.  From here, the nearby trees glisten in"
" %^BOLD%^%^WHITE%^newly fallen snow. %^RESET%^%^GREEN%^A few of them are completely leafless and look like"
" %^RESET%^shining %^BOLD%^%^BLACK%^silhouettes %^RESET%^%^GREEN%^against the backdrop of the predominately"
" pine forest, and surrounding %^BOLD%^%^WHITE%^snow-covered %^RESET%^%^BLUE%^mountains.");
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"){
   return("%^RESET%^%^GREEN%^The forest is thick and dense.  A few dapples of"
" %^RED%^c%^ORANGE%^o%^YELLOW%^l%^RED%^o%^RESET%^%^ORANGE%^r %^GREEN%^can be seen within the predominately pine"
" forest, indicating that a few of the trees at least are of a different sort and getting ready for the upcoming"
" winter.");
   }
   else{
   return("%^GREEN%^The forest is thick and dense, but unusually quiet.  Most of the surrounding trees are some"
" sort of pine, but a glimpse of different sorts of leaves can be seen here and there, indicating that at"
" least a few other varieties grow here as well.");
   }
}
string lmountains(string str){
   if(month(time())=="Winterstime"||month(time())=="Colddays"){
   return("%^BOLD%^%^WHITE%^Snow covered %^RESET%^%^BLUE%^mountains loom high overhead on all sides of this forest.");
   }
   else{
   return("%^RESET%^%^BLUE%^Mountains loom high overhead on all sides of this forest with their %^BOLD%^%^WHITE%^snow-covered peaks %^RESET%^%^BLUE%^shining against the horizon.");
   }
}

