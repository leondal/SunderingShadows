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
void reset() {
   ::reset();
   searched = 1 ;
}
void search_pile() {
   if(searched <= 0) {               
	tell_object(TP,"%^RESET%^%^ORANGE%^It looks like the leaves have been recently gone through.");
      return ;
   }
   if (searched == 1) {  
      tell_object(TP,"%^RESET%^%^GREEN%^You begin to dig through the leaves.");
      tell_room(TO,"%^RESET%^%^GREEN%^"+TPQCN+" digs through the leaves.", TP);
      switch(random(108)){
         case 0..3:
            rdstuff->find_stuff(TO,"MAGIC",random(30));
            searched = 0;
            break;
         case 4..70:
            write("%^RESET%^%^ORANGE%^You carefully search through the thick leaves but do not seem to find anything.");
            tell_room(TO, "%^RESET%^%^GREEN%^"+TPQCN+" doesn't seem to find anything.", TP);
            searched = 0;
            break;
         case 71..80:
            rdstuff->find_stuff(TO,"STUFF");
            searched = 0;
            break;
         case 81..89:
            rdstuff->find_stuff(TO,"KIT");
            searched = 0;
            break;
         case 90..98:
            rdstuff->find_stuff(TO,"POTION");
            searched = 0;
            break;
         case 99..101:
            RANDGEAR->armor_me(TO,"armorlt",100,2,0);
            searched = 0;
            break;
         case 102..103:
            rdstuff->find_stuff(TO,"SCROLL");
            searched = 0;
            break;
         case 104..105:
            rdstuff->find_stuff(TO,"COINS");
            searched = 0;
            break;
         case 106..107:
            rdstuff->find_stuff(TO,"COMPONENT");
            searched = 0;
            break;
         case 108:
            rdstuff->find_stuff(TO,"MIDSCROLL");
            searched = 0;
            break;
      }
   }
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
" pine tree flatten out here, creating a fairly stable place to sit and rest.  Pine needles and"
" %^ORANGE%^branches %^RESET%^%^GREEN%^have been gathered around to make a simple shelter and camoflauge,"
" and would probably serve to protect anyone that was hiding within from the prying eyes of those below."
"  Far beneath the gently swaying limbs, the bushes and brambles grow in abundance, making it"
" nearly impossible for any except perhaps a skilled ranger to get through quietly.  Because of this, this would"
" probably serve as an excellent place to set up an ambush from.%^RESET%^\n");
   }
   if(month(time())=="Renewal"||month(time())=="Springstime"||month(time())=="Plantingdays"){
   return("%^RESET%^%^GREEN%^The branches of this magnificent pine tree flatten out here, creating a fairly"
" stable place to sit and rest.  Pine %^ORANGE%^needles %^GREEN%^and %^ORANGE%^branches %^GREEN%^have been"
" gathered around to make a simple shelter and camoflauge, and would probably serve to protect anyone that was"
" hiding within from the prying eyes of those below.  Far beneath the gently swaying limbs, the bushes,"
" brambles, and %^BOLD%^new growth %^RESET%^%^GREEN%^grow in abundance, making it nearly impossible for any"
" except perhaps a skilled ranger to get through quietly.  Because of this, this would probably serve as an"
" excellent place to set up an ambush from.%^RESET%^\n");
   }
   if(month(time())=="Sundays"||month(time())=="Summerstime"){
   return("%^RESET%^%^GREEN%^The branches of this magnificent pine tree flatten out here, creating a fairly"
" stable place to sit and rest.  Pine %^ORANGE%^needles %^GREEN%^and %^ORANGE%^branches %^GREEN%^have"
" been gathered around to make a simple shelter and camoflauge,"
" and would probably serve to protect anyone that was hiding within from the prying eyes of those below."
"  Far beneath the gently swaying limbs, the bushes and brambles grow in abundance, making it nearly impossible"
" for any except perhaps a skilled ranger to get through quietly.  Because of this, this would probably serve as"
" an excellent place to set up an ambush from.%^RESET%^\n");
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"){
   return("%^RESET%^%^GREEN%^The branches of this magnificent pine tree flatten out here, creating a fairly stable"
" place to sit and rest.  Pine %^ORANGE%^needles %^GREEN%^and %^ORANGE%^branches %^GREEN%^have been gathered"
" around to make a simple shelter and camoflauge, and would probably serve to protect anyone that was hiding within"
" from the prying eyes of those below.  Far beneath the gently swaying limbs, the bushes and brambles grow in"
" abundance, making it nearly impossible for any except perhaps a skilled ranger to get through quietly."
"  Because of this, this would probably serve as an excellent place to set up an ambush from.%^RESET%^\n");
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
   return("%^RESET%^%^BLUE%^Mountains loom high overhead on all sides of this forest.");
   }
}



