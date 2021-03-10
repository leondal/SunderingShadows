//rroom.c
#include <std.h>
#include "../yntala.h"
inherit PIER;
int searched;

void create(){
   ::create();
      set_property("outdoors",0);
      set_property("light",2);
      set_travel(RUTTED_TRACK);
      set_water_body("river");
      set_terrain(SHALLOW_WATER);
      set_pre_exit_functions(({"east","west"}),({"go_out","go_out"}));
      set_name("%^BLUE%^A swiftly flowing r%^BOLD%^%^BLUE%^i%^CYAN%^v%^BLUE%^e%^RESET%^%^BLUE%^r%^RESET%^");
      set_short("%^BLUE%^A swiftly flowing river%^RESET%^");
      set_long((:TO,"ldesc":));
      set_smell("default","%^RESET%^It smells fresh.%^RESET%^");
      set_listen("default","%^BOLD%^%^BLUE%^The sounds of r%^WHITE%^u%^RESET%^s%^BLUE%^h%^BOLD%^%^BLUE%^i%^BOLD%^%^WHITE%^n%^BLUE%^g water can be heard.");
      set_items(([
      ({"rocks","rock"}):"%^BOLD%^%^BLACK%^The rocks lining the bottom of the river look to be quite slick.%^RESET%^",
      ({"bottom","river bottom"}):"RESET%^%^ORANGE%^The river bottom is lined with %^BOLD%^%^BLACK%^slick rocks %^RESET%^%^ORANGE%^that gently move with the flow of the %^CYAN%^water.%^RESET%^",
      ({"forest","trees"}):"%^RESET%^%^GREEN%^The forest grows all the way up to the edge of the %^BLUE%^r%^CYAN%^i%^BOLD%^%^BLUE%^v%^RESET%^%^CYAN%^e%^BLUE%^r %^ORANGE%^banks, %^GREEN%^casting %^BOLD%^%^BLACK%^shadows %^RESET%^%^GREEN%^in the shallow depths.%^RESET%^",
      ({"shadows","shadow"}):"%^BOLD%^%^BLACK%^The shadows created from the trees and undergrowth dance in the moving waters.%^RESET%^",
      ({"banks","bank","riverbanks","riverbank"}):"%^RESET%^%^ORANGE%^The river banks don't seem close enough for your liking.%^RESET%^",
      "undergrowth":"%^BOLD%^%^GREEN%^The undergrowth spills out of the forest and tumbles over the edge of the river.%^RESET%^",
]));
   set_exits(([
"west":INRMS+"river4",
"east":INRMS+"river3"
]));
}
int go_out(object targ) { 
   if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
      if(random(20) < 3){
         tell_object(TP,"%^RESET%^%^BLUE%^You slip on a rock and hit your head hard on a rock!.%^RESET%^");
         tell_room(TO,""+TPQCN+" slips on a rock and falls down hard!%^",TP);
         TP->set_paralyzed(20,"Your ears are still ringing, and things still look fuzzy.");
         TP->do_damage("torso",roll_dice(1,4));
      }
   }
   return 1;
}

string ldesc(string str){
   return("%^BOLD%^%^BLUE%^You are wading across a shallow,"
" but %^WHITE%^swiftly %^BLUE%^moving r%^CYAN%^i%^RESET%^%^CYAN%^"
"v%^BOLD%^%^CYAN%^e%^BLUE%^r that flows around your ankles at a"
" rapid pace.  You can feel the pull against you as you struggle"
" to make it to the other side without slipping on the"
" %^BLACK%^dark, slick rocks %^BLUE%^that line the river"
" %^RESET%^%^ORANGE%^bottom.  %^BOLD%^%^BLUE%^The"
" %^RESET%^%^GREEN%^forest %^BOLD%^%^BLUE%^closes in all around"
" you, and reaches up to the very banks of the river, casting"
" %^BLACK%^shadows %^BLUE%^within the shallow depths.%^RESET%^\n");
} 

