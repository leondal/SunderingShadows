//redge.c
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit INRMS+"bcave1";
int searched;
int knocked;

void create(){
::create();
   set_property("no teleport",1);
   set_property("indoors",1);
   set_smell("default","%^BLUE%^The moisture hangs in the air here.");
   set_listen("default","%^BOLD%^%^BLUE%^The sound of rushing water is almost deafening.");
   set_long((:TO,"ldesc":));
   set_items((["river":"%^BOLD%^%^BLUE%^The river here is a natural underground river whose source is unknown.  It moves through here at a frantic pace and you wonder if it would be wise to try to cross it.%^RESET%^",
   "treasure":"It looks as though whatever dwells above may use this area to dump their loot.  The only way to get to it is to cross the river.",
   ({"archway","arch"}):"%^RESET%^%^BLUE%^There is an archway carved into the wall that looks odd.", 
   ]));
   set_exits((["river":INRMS+"criver"]));
   set_search("archway","After studying the archway closely, you realize that it use to be an opening to another part of the cave that has now been sealed off, but you might be able to knock it down.");
}

string ldesc(string str){
   return("%^RESET%^%^BLUE%^You can now see why this part of the cave had been"
" blocked off.  A large underwater river courses through here and it looks to be"
" flowing quite rapidly.  Across the river you can see the other side of the cave"
" and everything that lies there.  %^RESET%^Light %^BLUE%^filters down through an"
" opening in the ceiling, %^YELLOW%^illuminating %^RESET%^%^BLUE%^the piles upon"
" piles of %^YELLOW%^treasures %^RESET%^%^BLUE%^that are stored there.  Carved in"
" the wall to the east is a strange archway that seems out of place."
"%^RESET%^ \n");
} 
void reset() {
   ::reset();
   if(query_exit("east")){
   remove_exit("east");
   }
   searched = 1 ;
   knocked = 1;
}
void init(){
  ::init();
  add_action("knock","knock");
}
int knock(string str){
   if(str == "wall"||str=="down wall"||str=="archway"||str=="down archway"||str=="arch"||str=="down arch"){
      if(knocked == 1) {               
         tell_object(TP,"%^BOLD%^%^BLACK%^You take a deep breath and move back a few paces.  You run shoulder first into the wall and watch it crumble before you realize how much that really hurt.%^RESET%^");
         tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" steps back and takes a deep breath before running shoulder first into the wall of the archway.  It crumbles to the floor.%^RESET%^",TP);
         TP->do_damage("torso",random(40)+10);
         add_exit(INRMS+"bcave3","east");
         find_object_or_load(INRMS+"bcave3")->add_exit(INRMS+"redge","west");
         tell_room(find_object_or_load(INRMS+"bcave3"),"%^BOLD%^%^BLACK%^A large THUD resounds from the other side of the western wall and the wall crumbles to the ground.%^RESET%^");
      knocked = 0;
      return 1;
      }
      if(knocked == 0) {  
         tell_object(TP,"%^BOLD%^%^BLACK%^It's already been knocked down!%^RESET%^");
      return 1;
      }             
   }
}
