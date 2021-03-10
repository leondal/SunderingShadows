//brush room inherit
#include <std.h>
#include "/d/barriermnts/bforest/bforest.h"
inherit CROOM;
int picked;



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
      "mountains":(:TO,"lmountains":),
      ({"bushes","brambles"}):"%^GREEN%^Bushes and brambles lay low on the forest floor, spilling out into the pathway that you walk along while vines cling to the trees, their bushy leaves creating an overhanging that nearly blocks out all sunlight.  A few berry bushes grow wildly amongst the rest, creating a rather thorny barrier to move through.",
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
   return("%^RESET%^%^GREEN%^The undergrowth of the forest is especially thick away from the path, as the"
" lack of noticeable animal life to keep it in check has allowed the forest to grow wildly and out of control."
"  Everything is covered in a thick blanket of %^BOLD%^%^WHITE%^snow.  %^RESET%^%^GREEN%^Multitudes of %^BOLD%^"
"%^WHITE%^snow-covered %^RESET%^%^GREEN%^trees grow all around here, blocking out most of the sunlight.  Though"
" most of the trees appear to be evergreens, a few scattered leafless ones would indicate that at least some"
" other species consider this valley home as well.  Vines twist their way around the tree trunks, allowing"
" their leaves to hang down all around you like dense, leafy curtains.  Ferns of all sorts peak up through the "
"%^BOLD%^%^WHITE%^snow-covered %^RESET%^%^GREEN%^ground, and thick brambles and varied berry bushes that are"
" leafless and %^ORANGE%^hardened %^GREEN%^from the cold winter further hamper attempts to make it through this"
" area without putting forth alot of effort.%^RESET%^\n");
   }
   if(month(time())=="Renewal"||month(time())=="Springstime"||month(time())=="Plantingdays"){
   return("%^RESET%^%^GREEN%^The undergrowth of the forest is especially thick away from the path, as the"
" lack of noticeable animal life to keep it in check has allowed the forest to grow wildly and out of control."
" New %^BOLD%^saplings %^RESET%^%^GREEN%^seem to be springing up all around, fighting the multitudes of already"
" established trees for that precious sunlight.  Though most of the trees appear to be evergreens, a few"
" leafless ones teaming with %^BOLD%^%^MAGENTA%^pink buds %^RESET%^%^GREEN%^and %^BOLD%^new leaves %^RESET%^%^GREEN%^"
" would indicate that some other varieties consider this valley home as well.  Vines twist their way around"
" the tree trunks, allowing their leaves to hang down all around you like dense, leafy curtains.  Ferns of all"
" sorts fan their leafy branches outward, making it impossible to pass through her without brushing against them."
" Amongst the ferns, saplings and other new growth, the brambles and berry bushes that went dormant for the winter"
" are now teaming with new life.%^RESET%^\n");
   }
   if(month(time())=="Sundays"||month(time())=="Summerstime"){
   return("%^RESET%^%^GREEN%^The undergrowth of the forest is especially thick away from the path, as the"
" lack of noticeable animal life to keep it in check has allowed the forest to grow wildly and out of control."
"  Multitudes of trees grow in abundance here, all fighting for the precious light.  Most of the trees appear"
" to be evergreens of some sort, though a few other varieties can be seen growing amongst them.  Vines twist"
" their way around the tree trunks, allowing their leaves to hang down all around you like dense, leafy curtains."
"  Ferns of all sorts fan their leafy branches outward, making it impossible to pass through here without"
" brushing against them.  Amongst the ferns, brambles and berries grow in abundance, making travel through this"
" area especially difficult.%^RESET%^\n");
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"){
   return("%^RESET%^%^GREEN%^The undergrowth of the forest is especially thick away from the path, as the lack of"
" noticeable animal life to keep in check has allowed the forest to grow wildly out of control.  Multitudes"
" of trees grow in abundance here, all fighting for the precious light.  Most of the trees appear to be"
" evergreens of some sort, though the splashes of %^RED%^red, %^ORANGE%^orange %^GREEN%^and %^YELLOW%^yellow"
"%^RESET%^%^GREEN%^, on the turning leaves of others would indicate that at least a few other varieties call this"
" valley home as well.  Vines twist their way around the tree trunks of all the trees with little prejudice, "
" allowing their leaves to hang down all around you like dense, leafy curtains.  Ferns of all sorts fan their"
" own leafy branches outward, making it impossible to pass through here without brushing against them.  Amongst"
" the ferns, %^ORANGE%^brambles %^RESET%^%^GREEN%^and %^RED%^b%^MAGENTA%^e%^BOLD%^r%^RED%^r%^RESET%^%^RED%^y"
" %^RESET%^%^GREEN%^bushes now ripe for the picking grow in abundance, making travel through this"
" area especially difficult.%^RESET%^\n");
   }
}
string lmountains(string str){
   if(month(time())=="Winterstime"||month(time())=="Colddays"){
   return("%^BOLD%^%^WHITE%^Snow covered %^RESET%^%^BLUE%^mountains loom high overhead on all sides of this forest.");
   }
   else{
   return("%^RESET%^%^BLUE%^Mountains loom high overhead on all sides of this forest with their %^BOLD%^%^WHITE%^snow-covered %^RESET%^%^BLUE%^peaks shining against the horizon.");
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
   return("%^BOLD%^%^BLACK%^A few %^RESET%^%^GREEN%^pine needles %^BOLD%^%^BLACK%^and %^RESET%^%^ORANGE%^broken twigs %^BOLD%^%^BLACK%^lay loosely over the muddy earth.");
   }
   if(month(time())=="Sundays"||month(time())=="Summerstime"){
   return("%^RESET%^%^ORANGE%^Fallen leaves, pine needles and other debris litter the ground.");
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"){
   return("%^RESET%^%^RED%^M%^ORANGE%^u%^YELLOW%^l%^RED%^t%^RESET%^%^ORANGE%^i-c%^RED%^o%^YELLOW%^l%^RED%^o%^RESET%^%^ORANGE%^r%^RED%^e%^YELLOW%^d %^RESET%^%^ORANGE%^fallen leaves, %^GREEN%^pine needles %^RESET%^%^ORANGE%^and other debris litter the ground.");
   }
}
void reset() {
   ::reset();
   picked = random(3);
}

void init(){
   ::init();
   add_action("pick", "pick");
}
int pick(string str){
   if(!str) {
      tell_object(TP,"Pick what?");
      return 1;
   }
   if(str != "berries" && str != "wildberries") {
      write("You do not see that here.");
   return 1;
   }
   if(month(time())=="Winterstime"||month(time())=="Colddays"){
	tell_object(TP,"%^RESET%^%^ORANGE%^Are you nuts?  The berry vines are completely bare of any leaves, let alone ripe berries!%^RESET%^");
      return 1;
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"&&(picked <= 0)) {               
	tell_object(TP,"%^GREEN%^There are no more berries on the vines.%^RESET%^");
   return 1;
   }
   if(month(time())=="Growingdays"||month(time())=="Harvestdays"||month(time())=="Autumnstime"&&(picked > 0)) {               
   tell_object(TP,"%^GREEN%^You pick a wonderful a juicy handful of %^RESET%^%^RED%^berries.%^RESET%^");
   tell_room(ETP,""+TPQCN+" picks a large handful of %^RED%^berries%^RESET%^.",TP);
   new(OBJD+"wildberries.c")->move(TP);
   picked --;
   return 1;
   }
   else{
   tell_object(TP,"%^GREEN%^You look through all the berry bushes and realize there are not any ripe ones.%^RESET%^");
   tell_room(ETP,""+TPQCN+" searches through the berry bushes%^RESET%^.",TP);
   return 1;
   }
}

