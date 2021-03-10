//forest171
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
      set_long("%^GREEN%^You are walking through a thick forest"
" whose dense canopy allows only a few rays of %^RESET%^surreal"
" light %^GREEN%^through, creating an almost magical presence"
" around you. The underbrush is thick and full of life here,"
" and the ivy and vines look especially thick, their slender"
" lengths hanging from the trees above like a magical curtain"
" around you.%^RESET%^\n");
      set("night long","%^RESET%^%^GREEN%^You've wandered into a"
" the deeper part of the Yntala Forest. Very little"
" %^RESET%^moonlight %^GREEN%^makes its way through the dense"
" canopy above, giving this forest a very %^RESET%^surreal"
" %^RESET%^feeling. %^GREEN%^Crickets chirp from somewhere in"
" the thick underbrush, and %^BOLD%^%^BLACK%^shadows"
" %^RESET%^%^GREEN%^dance around you, creating the illusion"
" of movement amongst the thick vines that hang down around you"
".%^RESET%^\n");
      set_items(([
      ({"light","lights"}):"%^RESET%^A few rays of light filter down through the %^GREEN%^dense forest canopy %^RESET%^above, giving the %^ORANGE%^forest floor %^RESET%^an almost surreal feeling.",
      "underbrush":"%^GREEN%^The underbrush here is very thick, consisting of %^BOLD%^%^GREEN%^ferns, %^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^y, and other various %^BOLD%^%^GREEN%^flora.%^RESET%^",
      ({"ferns","fern"}):"%^BOLD%^%^GREEN%^The ferns here are as varied as they are numerous, seemingly covering the entire forest floor and more. They grow at the base of trees, out of rotting vegetation, and just about every other spare space they can find.%^RESET%^",
      "ivy":"%^GREEN%^The ivy hangs down all around you and is so thick that you think you might be able to actually climb the vines.%^RESET%^",
      ({"tree","trees"}):"%^GREEN%^The tree's here all grow to be at least one hundred feet tall and are covered in %^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^v%^BOLD%^%^GREEN%^y.%^RESET%^",
      "fallen trees":"%^ORANGE%^A few fallen trees covered in %^GREEN%^moss %^ORANGE%^litter the forest floor.%^RESET%^",
      ({"floor","forest floor"}):"%^ORANGE%^The %^GREEN%^forest floor %^ORANGE%^is littered with rotting %^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^v%^RESET%^%^ORANGE%^e%^GREEN%^s, %^BOLD%^%^GREEN%^ferns, %^RESET%^%^GREEN%^moss, %^ORANGE%^and %^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^v%^BOLD%^%^GREEN%^y.%^RESET%^",
      "moss":"%^GREEN%^The moss seems to be everywhere, blanketing the forest in a nice, warm fuzzy green hue.%^RESET%^", 
      "vines":"%^GREEN%^The ivy and other vines hang down all around you and is so thick that you think you might be able to actually climb them.%^RESET%^",
]));
   set_exits(([
"west":INRMS+"forest172",
"southeast":INRMS+"forest170"
]));
  set_pre_exit_functions(({"north","south","east","west","northeast","northwest","southeast","southwest"}),({"go_out","go_out","go_out","go_out","go_out","go_out","go_out","go_out"}));

   set_search("default", "%^ORANGE%^You can't help but to think perhaps there is something hidden somewhere in this dense foliage.%^RESET%^");
    set_search("ivy", (: TO, "search_pile" :) );
    set_search("undergrowth", (: TO, "search_pile" :) );
    set_search("forest floor", (: TO, "search_pile" :) );
    set_search("vines", (: TO, "search_pile" :) );
    set_search("foliage", (: TO, "search_pile" :) );
}
int go_out() { 
   if(!"daemon/saving_d"->saving_throw(TP,"paralyzation_poison_death")) {
      if(random(1000) < 3){
         switch(random(3)){
         case 0:
            tell_object(TP,"%^RESET%^%^GREEN%^You trip over a %^ORANGE%^root!.%^RESET%^");
            tell_room(TO,""+TPQCN+" trips over a %^RESET%^%^ORANGE%^root!%^RESET%^",TP);
            TP->set_paralyzed(15,"You are trying to get to your feet.");
            break;
         case 1:
            tell_object(TP,"%^RESET%^%^ORANGE%^A little brown lizard darts out in front of you and you trip over it!%^RESET%^");
            tell_room(TO,""+TPQCN+" trips over a %^RESET%^%^ORANGE%^lizard!%^RESET%^",TP);
           TP->set_paralyzed(20,"You are trying to get to your feet.");
           new(TMONDIR+"brownlizard.c")->move(TO);
           break;
         case 2:
            tell_object(TP,"%^RESET%^%^GREEN%^A little green lizard darts out in front of you and you trip over it!%^RESET%^");
            tell_room(TO,""+TPQCN+" trips over a lizard!%^RESET%^",TP);
            TP->set_paralyzed(25,"You are trying to get to your feet.");
            new(TMONDIR+"greenlizard.c")->move(TO);
            break;
         }
      return 0;
      }
   }
   return 1;
}
void reset() {
  object ob;
  ::reset();
  searched = 1 ;
}
void search_pile() {
  if(searched <= 0) {               
	 tell_object(TP,"It looks like this area has been searched already.");
        return ;
  }

  if (searched == 1) {  
     switch(random(103)){
        case 0..3:
          write("You found a dress in the vast forest foliage!\n");
          tell_room(TO,""+TPQCN+" searches around and finds a dress in the forest foliage.",TP);
          new(OBJD+"forestdress.c")->move(TO);
          searched = 0;
          break;
               case 4..98:
          write("You don't seem to find anything.");
          tell_room(TO, ""+TPQCN+" doesn't seem to find anything.", TP);
          searched = 0;
          break;
          case 99..101:
          tell_room(TO,"A wasps nest has been disturbed!");
          waspswarm();
          searched = 0;
          break;
          case 102..103:
           tell_room(TO,"The rustling of the bushes disturbs a sleeping bear!");
          new(TMONDIR+"brownbear.c")->move(TO);

          searched = 0;

      }
   }
}
 void waspswarm (){
   switch(random(4)){
        case 0:
               new(TMONDIR+"wasp.c")->move(TO);
               new(TMONDIR+"wasp.c")->move(TO);              
               new(TMONDIR+"wasp.c")->move(TO);                            
        case 1:
               new(TMONDIR+"wasp.c")->move(TO);
               new(TMONDIR+"wasp.c")->move(TO);              
               new(TMONDIR+"wasp.c")->move(TO);               
        case 2:
               new(TMONDIR+"wasp.c")->move(TO);
               new(TMONDIR+"wasp.c")->move(TO);              
               new(TMONDIR+"wasp.c")->move(TO);               
        case 3:
               new(TMONDIR+"wasp.c")->move(TO);
               new(TMONDIR+"wasp.c")->move(TO);              
               new(TMONDIR+"wasp.c")->move(TO);
               new(TMONDIR+"wasp.c")->move(TO);
               new(TMONDIR+"wasp.c")->move(TO);               
               new(TMONDIR+"wasp.c")->move(TO);               
               new(TMONDIR+"wasp.c")->move(TO);               
               new(TMONDIR+"wasp.c")->move(TO);               
               new(TMONDIR+"wasp.c")->move(TO);               
               new(TMONDIR+"wasp.c")->move(TO);               
               new(TMONDIR+"wasp.c")->move(TO);               
               new(TMONDIR+"wasp.c")->move(TO);               
               break;
               searched = 0;               
   }
}
void init(){
  ::init();
  add_action("climb","climb");
}
int climb(string str){
   if(str == "vines"){
   tell_object(TP,"%^BOLD%^%^GREEN%^You grab hold of the vines and climb up.%^RESET%^");
   tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" grabs hold of the vines and climbs up.",TP);
   this_player()->move_player(INRMS+"treeroom");
   return 1;
   }
}
