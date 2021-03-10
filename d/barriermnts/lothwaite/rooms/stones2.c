//stones2.c - Lothwaite's ring of stones.  Circe 9/18/04
//adjusted the code for observing the stones to use academics rather than the study nwp ~Circe~ 2/20/13
//added druids to the people who can study the stones ~Circe~ 3/25/13
#include <std.h>
#include "../lothwaite.h"
inherit ROOM;

int step1,step2,step3;
int failure();

void create(){
   ::create();
   set_indoors(0); 
   set_property("light",2);
   set_terrain(OLD_MOUNTS);
   set_travel(RUTTED_TRACK);
   set_name("An imposing ring of stones");
   set_short("An imposing ring of stones");
   set_long("%^CYAN%^This solemn valley is filled with vibrant "+
      "%^GREEN%^grass %^CYAN%^that grows tall against the bases "+
      "of the twelve ancient %^RESET%^standing stones%^CYAN%^ arranged "+
      "in a great circle in the center.  Each of the %^RESET%^"+
      "stones %^CYAN%^stands over thirty feet tall, casting their "+
      "great %^BOLD%^%^BLACK%^shadows %^RESET%^%^CYAN%^all over "+
      "the valley below.  %^BOLD%^Runes %^RESET%^%^CYAN%^have "+
      "been inscribed on each of the stones, though none of them "+
      "match.  In the very heart of the valley, a great flat "+
      "%^RESET%^stone lid %^CYAN%^has been set, its top rising only "+
      "a foot off the ground.  It is said to lead to the firbolg "+
      "%^BOLD%^%^BLACK%^crypts %^RESET%^%^CYAN%^below, though it "+
      "is clear that not even the entire village of firbolgs together "+
      "could lift the great stone from the ground.\n");
   set_items(([
      ({"grass","ground"}) : "%^GREEN%^All around the stones grows "+
         "vibrant, healthy grass that looks soft to the touch and "+
         "sways lightly on the ever-present breeze in this valley.",
      ({"stones","standing stones"}) : "The standing stones have "+
         "an impressive girth to match their height.  Though not "+
         "perfectly round, each stone is mostly cylindrical in "+
         "design.  They are clearly marked and browned with age, "+
         "and each stone bears a single rune.  The stones are "+
         "arranged in a perfect circle surrounding the stone "+
         "lid in the floor, and their height easily doubles that "+
         "of even most firbolgs.",
      ({"rune","runes"}) : "%^BOLD%^%^CYAN%^Each of the stones "+
         "bears a large rune that appears to have been inscribed "+
         "when the stones were still young.  You could %^WHITE%^<"+
         "%^CYAN%^observe runes%^WHITE%^>%^CYAN%^ to find out more about them.",
      ({"shadow","shadows"}) : "%^BOLD%^%^BLACK%^The massive stones "+
         "create deep shadows that play upon the ground even at noon.",
      ({"lid","stone lid"}) : "The massive stone lid is circular "+
         "in design with a flat top.  Inscribed upon its surface "+
         "are twelve runes that match those on the stones."
   ]));
   set_smell("default","Clean, fresh mountain air wafts on the breeze.");
   set_listen("default","The sound of the wind muffles most other noises in the valley.");
   set_exits(([
      "northwest" : PATHEXIT"stones1",
   ]));
   set_pre_exit_functions(({"northwest"}),({"leavering"}));
   step1 = 0;
   step2 = 0;
   step3 = 0;
}

void init(){
   ::init();
   add_action("observe","observe");
   add_action("trace","trace");
}

void reset(){
   ::reset();
   if(query_exit("barrows") != "/d/shadowgate/void"){
      tell_room(TO,"%^BLUE%^The great stone lid scrapes and creaks "+
         "as a mystical force moves it back in place, sealing the "+
         "barrows.");
      remove_exit("barrows");
   }
   add_item(({"lid","stone lid"}),"The massive stone lid is circular "+
         "in design with a flat top.  Inscribed upon its surface "+
         "are twelve runes that match those on the stones.");
   step1 = 0;
   step2 = 0;
   step3 = 0;
}

int leavering(){
   if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() || TP->query_tripped()) {
      TP->send_paralyzed_message("info",TP);
      return 0;
   }
   tell_object(TP,"You feel a great weight lift from your shoulders "+
      "as you leave the ring of stones.");
   if(!TP->query_invis()){
      tell_room(TO,""+TPQCN+" steps between two stones and leaves "+
         "the ring of stones.",TP);
   }
   return 1;
}

//only firbolgs, those with study, clerics, paladins, mages, thieves  
//greater than 18th level understand the runes.  
//Firbolgs & those with study for obvious reasons, clerics, paladins
//and mages for their time spent in arcane/divine study and thieves for
//their affinity for read magic

int observe(string str){
   string race = TP->query_race();
   int study = TP->query_skill("academics");
   if(!str){
      tell_object(TP,"Try to <observe runes> here.");
      return 1;
   }
   if(str != "runes" && str != "rune"){
      tell_object(TP,"Try to <observe runes> here.");
      return 1;
   }
   if(race == "firbolg" || study > 14 || avatarp(TP) || (TP->is_class("mage") && (int)TP->query_lowest_level() > 18) || (TP->is_class("cleric") && (int)TP->query_lowest_level() > 18) || (TP->is_class("paladin") && (int)TP->query_lowest_level() > 18) ||  (TP->is_class("thief") && (int)TP->query_lowest_level() > 18) || (TP->is_class("sorcerer") && (int)TP->query_lowest_level() > 18) || (TP->is_class("druid") && (int)TP->query_lowest_level() > 18)){
      tell_object(TP,"%^BOLD%^%^MAGENTA%^You walk slowly around the circle, "+
         "carefully noting the runes.  You discover they mean the "+
         "following:\n");
      tell_room(ETP,"%^BOLD%^"+TPQCN+" walks slowly around the "+
         "circle, looking at the runes.",TP);
      TP->more(OBJ"rune_layout");
      tell_object(TP,"\n%^BOLD%^%^RED%^What's more, it seems you "+
         "could probably activate the runes by tracing them, "+
         "but surely there is an order.  Which rune should you "+
         "trace?");
      return 1;
   }
   tell_object(TP,"You cannot quite make out the runes' meanings.");
   tell_room(ETP,""+TPQCN+" studies the runes but looks confused.",TP);
   return 1;
}

int failure(){
   tell_object(TP,"You trace the rune with your fingertip, but "+
      "there is no response from the stone.");
   tell_room(ETP,""+TPQCN+" traces a rune with "+TP->QP+" fingertip.",TP);
   step1 = 0;
   step2 = 0;
   step3 = 0;
   return 1;
}

int trace(string str){
   string seas = season(time());
   if(!str){
      tell_object(TP,"You must choose a rune to trace!");
      return 1;
   }
   if(!step1){
      switch(str){
         case "snow":  
         case "snow rune":  if(seas == "winter"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step1 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "rain":  
         case "rain rune":  if(seas == "spring"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step1 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "sun":
         case "sun rune":  if(seas == "summer"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step1 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "leaves":
         case "leaves rune":  if(seas == "autumn"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step1 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         default:  failure();
                   return 1;
                   break;
      }
   return 1;
   }
   if((step1) && (!step2)){
      switch(str){
         case "covers":
         case "covers rune":  if(seas == "winter"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step2 = 1;
                          return 1;
                    }else{
                          failure();
                          return 1;
                       }
                       break;
         case "brings":
         case "brings rune":  if(seas == "spring"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step2 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "shines":
         case "shines rune":  if(seas == "summer"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step2 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "turn":
         case "turn rune":  if(seas == "autumn"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step2 = 1;
                          return 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         default:  failure();
                   return 1;
                   break;
      }
   return 1;
   }
   if((step1) && (step2) && (!step3)){
      switch(str){
         case "all":
         case "all rune":  if(seas == "winter"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step3 = 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "flowers":
         case "flowers rune":  if(seas == "spring"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step3 = 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "bright":
         case "bright rune":  if(seas == "summer"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step3 = 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         case "golden":
         case "golden rune":  if(seas == "autumn"){
                          tell_object(TP,"%^BOLD%^The rune glows with "+
                             "a %^BLUE%^blue light %^WHITE%^as you "+
                             "trace it.");
                          tell_room(ETP,"%^BOLD%^"+TPQCN+" traces a "+
                             "rune, causing it to glow %^BLUE%^blue"+
                             "%^WHITE%^.",TP);
                          step3 = 1;
                       }else{
                          failure();
                          return 1;
                       }
                       break;
         default:  failure();
                   return 1;
                   break;
      }
   tell_object(TP,"%^BOLD%^%^BLUE%^As you touch the final rune, "+
      "all the stones begin to %^CYAN%^glow%^BLUE%^.  The stone "+
      "lid creaks and begins to slowly lift.");
   tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" steps away from the "+
      "rune and all the stones begin to %^CYAN%^glow%^BLUE%^.  "+
      "The stone lid creaks and begins to slowly lift.",TP);
   call_out("liftem",4);
   return 1;
   }
   tell_object(TP,"You must choose the name of a rune to trace!");
   return 1;
}

int liftem(){
   tell_room(TO,"%^BOLD%^The stone lid lifts fully away from the "+
      "ground and slides to the side, revealing a spiral staircase "+
      "leading down into the dark below!");
   add_item(({"lid","stone lid"}),"The stone lid has somehow been "+
      "moved to the side, revealing a spiral staircase leading down.");
   add_exit(PATHEXIT"b_start","barrows");
   return 1;
}
