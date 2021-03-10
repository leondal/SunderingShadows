#include <std.h>
#include "yntala.h"
inherit CROOM;

void create(){
   switch(random(19)){
      case 0..9:
      break;
      case 10..12:
         set_monsters(({TMONDIR +"yuan-tip.c"}),({2}));
      break;
      case 13..14:
         set_monsters(({TMONDIR +"yuan-tih.c"}),({1}));
      break;
      case 15..16:
         set_monsters(({TMONDIR +"greenhag.c"}),({1}));
      break;
      default:
         set_monsters(({TMONDIR +"direwolf.c"}),({3}));
       break;
   }
   set_repop(35);

::create();
  set_property("light",1);
  set_travel(RUTTED_TRACK);
  set_terrain(HEAVY_FOREST);
  set_pre_exit_functions(({"north","south","east","west","northeast","northwest","southeast","southwest"}),({"go_out","go_out","go_out","go_out","go_out","go_out","go_out","go_out"}));
  set_name("An ancient forest");
  set_short("%^GREEN%^A %^BOLD%^%^BLACK%^dark %^RESET%^%^GREEN%^and ancient forest%^RESET%^");
      set_long((:TO,"ldesc":));
      set("night long","%^RESET%^%^BLUE%^This %^GREEN%^forest %^BLUE%^is even"
" %^BOLD%^%^BLACK%^darker %^RESET%^%^BLUE%^at night, with"
" absolutely no moonlight touching the forest floor around you. "
" %^BOLD%^%^BLACK%^Shadows %^RESET%^%^BLUE%^dance seductively in"
" the darkness, beckoning you to come further into their midst,"
" and the trees even seem to take on a more eerie twist as they"
" hover overhead.%^RESET%^\n");
  set_smell("default","You smell dank vegetation.%^RESET%^");
  set_listen("default","The wind whistles through the trees.");
  set_items(([
     ({"floor","forest floor"}):"%^BOLD%^%^BLACK%^Shadows dance across the forest floor, making it difficult to see much.%^RESET%^",
     ({"forest","tree","trees"}):"%^RESET%^%^ORANGE%^The trees here are old and gnarled, twisted in deformed ways that give off a %^BOLD%^%^BLACK%^spooky %^RESET%^%^ORANGE%^feeling.%^RESET%^",
     ({"light","lights"}):"%^RESET%^%^BLUE%^The only %^RESET%^light %^BLUE%^that manages to make its way through the dense %^GREEN%^canopy %^BLUE%^looks more like fine %^RESET%^spiderwebs %^BLUE%^falling from the sky.",
      "fallen trees":"%^GREEN%^Many fallen trees litter the ground here, most are %^ORANGE%^rotting %^GREEN%^and covered with moss.%^RESET%^",
]));
}

int go_out() {
if(!objectp(TP)){ return 1; } 
if((int)TP->query_highest_level()>=23){
      if(random(1000) < 3){
         new(TMONDIR+"gfigure.c")->move(TO);
         TP->set_paralyzed(2,"You are trying to get to your feet.");
       return 0;
      }
   }
   if(!"daemon/saving_d"->saving_throw(TP,"paralyzation_poison_death")) {
      if(random(1000) < 3){
         switch(random(3)){
         case 0:
            tell_object(TP,"%^RESET%^%^GREEN%^You trip over a %^ORANGE%^root!.%^RESET%^");
            tell_room(TO,""+TP->QCN+" trips over a %^RESET%^%^ORANGE%^root!%^RESET%^",TP);
            TP->set_paralyzed(15,"You are trying to get to your feet.");
            break;
         case 1:
            tell_object(TP,"%^RESET%^%^ORANGE%^A little brown lizard darts out in front of you and you trip over it!%^RESET%^");
            tell_room(TO,""+TP->QCN+" trips over a %^RESET%^%^ORANGE%^lizard!%^RESET%^",TP);
           TP->set_paralyzed(20,"You are trying to get to your feet.");
           new(TMONDIR+"brownlizard.c")->move(TO);
           break;
         case 2:
            tell_object(TP,"%^RESET%^%^GREEN%^A little green lizard darts out in front of you and you trip over it!%^RESET%^");
            tell_room(TO,""+TP->QCN+" trips over a lizard!%^RESET%^",TP);
            TP->set_paralyzed(25,"You are trying to get to your feet.");
            new(TMONDIR+"greenlizard.c")->move(TO);
            break;
         }
      return 0;
      }
   }
   return 1;
}

string ldesc(string str){
   return("%^GREEN%^You find yourself in a very %^BOLD%^"
"%^BLACK%^dark %^RESET%^%^GREEN%^part of the forest.  Very little"
" light finds its way through the %^BOLD%^%^BLACK%^gnarled"
" %^RESET%^%^GREEN%^old trees that twist their way eerily towards"
" the unseen sky above.  %^RESET%^%^ORANGE%^Fallen trees"
" %^GREEN%^litter the ground around you, and a heavy,"
" %^BLUE%^oppressive %^GREEN%^feeling seems to fill the air here."
"%^RESET%^\n");
} 



 
