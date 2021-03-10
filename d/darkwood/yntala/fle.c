#include <std.h>
#include "yntala.h"
inherit ROOM;
int searched;

void waspswarm();
void bearswarm();
void create(){
   ::create();
      set_property("outdoors",0);
      set_property("light",2);
      set_travel(GAME_TRACK);
      set_terrain(HEAVY_FOREST);
      set_pre_exit_functions(({"north","south","east","west","northeast","northwest","southeast","southwest"}),({"go_out","go_out","go_out","go_out","go_out","go_out","go_out","go_out"}));
      set_name("A dense forest");
      set_short("%^GREEN%^A dense forest%^RESET%^");
      set_long((:TO,"ldesc":));
      set("night long","%^RESET%^%^GREEN%^You've wandered onto the"
" edge of a %^BLUE%^lake %^GREEN%^here in the Yntala Forest. The"
" %^RESET%^moonlight %^GREEN%^reflects off of the calm waters in"
" an almost %^BOLD%^%^BLACK%^eerie %^RESET%^%^GREEN%^fashion,"
" making you think that perhaps you should head back instead."
" Trees grow out of the more shallow edges of the water, and the"
" underbrush seems to be as thick as ever, making it difficult"
" to move safely around.%^RESET%^\n");
      set_smell("default","You smell the fresh scent of pine.%^RESET%^");
      set_listen("default","A few birds can be heard singing somewhere above you.");
      set_items(([
      "vines":"%^GREEN%^Vines climb the trees here and a few of them even hang from branches out over the water.%^RESET%^",
      "underbrush":"%^GREEN%^The underbrush here is very thick, consisting of %^BOLD%^%^GREEN%^ferns, %^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^v%^RESET%^%^GREEN%^y, and other various %^BOLD%^%^GREEN%^flora.%^RESET%^",
      ({"ferns","fern"}):"%^BOLD%^%^GREEN%^The ferns here are as varied as they are numerous, seemingly covering the entire forest floor and more. They grow at the base of trees, out of rotting vegetation, and just about every other spare space they can find, right up to the %^RESET%^%^BLUE%^lakes %^BOLD%^%^GREEN%^edge.%^RESET%^",
      "ivy":"%^GREEN%^The ivy climbs everything in this forest, wrapping around every inch of its host, covering it with a leafy-green wall.%^RESET%^",
      ({"forest","tree","trees"}):"%^GREEN%^The trees here all grow to be at least one hundred feet tall and are covered in %^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^v%^BOLD%^%^GREEN%^y.%^RESET%^",
      "fallen trees":"%^ORANGE%^A few fallen trees covered in %^GREEN%^moss %^ORANGE%^litter the forest floor, and a few of these even managed to have fallen into the %^BLUE%^lake.%^RESET%^",
      ({"floor","forest floor"}):"%^ORANGE%^The %^GREEN%^forest floor %^ORANGE%^is littered with rotting %^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^v%^RESET%^%^ORANGE%^e%^GREEN%^s, %^BOLD%^%^GREEN%^ferns, %^RESET%^%^GREEN%^moss, %^ORANGE%^and %^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^v%^BOLD%^%^GREEN%^y.%^RESET%^",
      "moss":"%^GREEN%^The moss seems to be everywhere, blanketing the forest and shore edges in a nice, fuzzy green hue.%^RESET%^", 
      ({"water","lake"}):"%^BLUE%^The lake here is very calm and surreal looking. Not even one ripple moves across its %^RESET%^glass-like %^BLUE%^surface, and the algae growing in it gives it an almost %^GREEN%^greenish %^BLUE%^hue.%^RESET%^",
]));
    set_search("default", "%^BLUE%^Perhaps something is hidden in the water?%^RESET%^");
    set_search("water", (: TO, "search_pile" :) );
    set_search("lake", (: TO, "search_pile" :) );
 

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
void search_pile() {
   if(searched <= 0) {               
	tell_object(TP,"%^BLUE%^It looks like someone may have already searched the waters edge here.");
      return ;
   }
   if (searched == 1) {  
      switch(random(105)){
         case 0..3:
            write("%^BLUE%^As you bend down to pull something from the waters edge, you can't help but wonder if getting your hands all %^RESET%^slimey %^BLUE%^in the %^GREEN%^algae %^BLUE%^was worth it.\n");
            tell_room(TO,""+TPQCN+" gets a disgusted look on "+TP->query_possessive()+" face as "+TP->query_subjective()+"gets all slimey while trying to pull something from the water.", TP);
            RANDGEAR->armor_me(TO,"armorlt",100,1,0);
            searched = 0;
            break;
         case 4..104:
            write("You don't seem to find anything.");
            tell_room(TO,""+TPQCN+" doesn't seem to find anything.", TP);
            searched = 0;
      }
   }
}
void reset() {
   ::reset();
   searched = 1 ;
}
string ldesc(string str){
   return("%^GREEN%^The forest comes to the edge of a large"
" %^BLUE%^lake %^GREEN%^here.  The trees hover over it, casting"
" their %^BOLD%^%^BLACK%^shadows %^RESET%^%^GREEN%^into the"
" watery depths.  A few of the trees even grow out of the shallower"
" parts of the water, the roots looking more like a twisting set of"
" strange legs rather than a typical tree trunk.  %^BOLD%^"
"%^GREEN%^Vi%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^es %^RESET%^"
"%^GREEN%^climb the trees and the underbrush is as thick and"
" dense as in every other part of this forest, perhaps even more"
" so since more %^RESET%^light %^GREEN%^finds its way here."
"%^RESET%^\n");
} 

