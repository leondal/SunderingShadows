//bcave3
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;
int searched;
int knocked;

void create(){
   set_monsters(({TMONDIR +"orcc.c",TMONDIR +"rorc.c"}),({random(2)+1,random(2)+5}));
::create();
   set_property("light",1);
   set_property("indoors",1);
   set_travel(FOOT_PATH);
   set_terrain(NAT_CAVE);
   set_name("%^BOLD%^%^BLACK%^The messhall%^RESET%^");
   set_short("%^RESET%^Inside a cave");
   set_smell("default","A foul smell permeates the air here.");
   set_long((:TO,"ldesc":));
   set_items((["walls":"The walls of the corridor are carved out of the natural rock of the cliffs.  The rocks are loose and look as though they are ready to fall at any time.  The only thing helping to hold them in place are the few spindly tree trunks that have been propped up against the walls.",
    "ceiling":"The ceiling of the cave is high above you.  The way some of the loose rock hangs make you feel very nervous.",
    ({"tree trunks","trunks","trunk","trees","pine trees","pine tree trunks"}):"%^RESET%^%^ORANGE%^Rather than shoring the walls like in the rest of the cave, the trees here just lay around on the ground, leaving the walls to crumble.%^RESET%^",
   ({"archway","arch"}):"%^RESET%^%^BLUE%^There is an archway carved into the wall that looks odd.", 
   "tables":"%^RESET%^The tables here line the walls and are covered with stinking furs and the occassion pile of rock that have fallen from the walls.",
   "furs":"%^RESET%^%^ORANGE%^Now you know where that horrid smell is coming from."
"  The furs here stink... there are no ands, ifs or buts about it.  With rotting"
" flesh still attached, it looks like whoever left them here figured the"
" %^RESET%^maggots %^ORANGE%^would do the job of cleaning the leather for them."
"%^RESET%^",
   "maggots":"%^BOLD%^%^WHITE%^Squirming little maggots crawl all over the furs and leather, cleaning the last pieces of flesh from them.%^RESET%^",
   ]));
   set_search("archway","After studying the archway closely, you realize that it use to be an opening to another part of the cave that has now been sealed off.  You get the bright idea that you might be able to knock it down.");
   set_search("arch","After studying the archway closely, you realize that it use to be an opening to another part of the cave that has now been sealed off.  You get the bright idea that you might be able to knock it down.");
   set_search("furs",(:TO,"search_furs":));
   set_exits((["northeast":INRMS+"bcave2",
               "south":INRMS+"bcave4"]));
}

string ldesc(string str){
   return("%^RESET%^%^BLUE%^The corridor widens here into a very large gathering"
" room.  A few %^RESET%^s%^BOLD%^%^BLACK%^t%^RESET%^o%^BOLD%^%^BLACK%^n%^RESET%^e"
" tables %^BLUE%^line the walls and are covered with piles of %^ORANGE%^stinking"
" furs.  %^BLUE%^There is an archway carved in the wall to the west that is"
" inconsistent with the rest of the cave.  Constant %^BOLD%^%^BLACK%^rumbles"
" %^RESET%^%^BLUE%^from above you make you think that you may be under something,"
" or that the ceiling isn't to far below ground.  Dead %^ORANGE%^trees %^BLUE%^lay"
" abandoned on the ground here and the walls are left unattended.%^RESET%^ \n");
} 
void reset() {
   ::reset();
   if(query_exit("west")){
   remove_exit("west");
   }
   searched = 1 ;
   knocked = 1;
}
void search_furs() {
   object ob;
   if(searched <= 0) {               
      write("%^RESET%^%^ORANGE%^You search through the furs but manage to find nothing but the %^BOLD%^%^WHITE%^squirming maggots %^RESET%^%^ORANGE%^that are now crawling on your arms.%^RESET%^");
      tell_room(TO, "%^RESET%^%^ORANGE%^"+TPQCN+" makes a face as "+TP->query_subjective()+" reaches into the furs and comes up with nothing but a handful of %^BOLD%^%^WHITE%^squirming maggots.%^RESET%^",TP);
      return ;
   }
   if (searched == 1) {  
      switch(random(100)){
         case 0:
            write("You dig through the furs and find a scroll mixed in with them.\n");
            tell_room(TO,""+TPQCN+" digs through the furs and finds a scroll.",TP);
            ob = new("/d/magic/scroll");
            ob->set_spell(random(4)+1);
            ob->move(TO);
            searched = 0;
            break;
         case 1..70:
            write("%^RESET%^%^ORANGE%^You search through the furs but manage to find nothing but the %^BOLD%^%^WHITE%^squirming maggots %^RESET%^%^ORANGE%^that are now crawling on your arms.%^RESET%^");
            tell_room(TO, "%^RESET%^%^ORANGE%^"+TPQCN+" makes a face as "+TP->query_subjective()+" reaches into the furs and comes up with nothing but a handful of %^BOLD%^%^WHITE%^squirming maggots.%^RESET%^",TP);
            searched = 0;
            break;
         case 71..99:
            write("You dig through the furs and pull out the first interesting thing you find.");
           tell_room(TO,""+TPQCN+" digs through the furs and pulls something out.",TP);
            RANDGEAR->armor_me(TO,"armorlt",100,3,0);
            searched = 0;
      }
   }
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
         add_exit(INRMS+"redge","west");
         find_object_or_load(INRMS+"redge")->add_exit(INRMS+"bcave3","east");
         tell_room(find_object_or_load(INRMS+"redge"),"%^BOLD%^%^BLACK%^A large THUD resounds from the other side of the eastern wall and the wall crumbles to the ground.%^RESET%^");
         knocked = 0;
         return 1;
      }
      if(knocked == 0) {  
         tell_object(TP,"%^BOLD%^%^BLACK%^It's already been knocked down!%^RESET%^");
      return 1;
      }             
   }
}


