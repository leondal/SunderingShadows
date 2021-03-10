//tree3
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit ROOM;
int searched;
object ob;

void create(){
::create();
   set_property("indoors",1);
   set_property("light",0);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^BOLD%^%^BLACK%^Within the bowls of a dark tree");
   set_short("%^BOLD%^%^BLACK%^Within the bowls of a dark tree%^RESET%^");
   set_smell("default","The smell of earth is strong here.");
   set_long((:TO,"ldesc":));
   set_climb_exits((["descend":({INRMS+"tree2",15,4,100})]));
  set_items(([
     "ledge":"%^BOLD%^%^BLACK%^The ledge looks to be fairly stable and a natural part of the inside of the tree.  Against the back part of the ledge though seems to be some sort of nest.%^RESET%^",
     "nest":"%^RESET%^%^ORANGE%^This is a very large pile of straw, rotted out tree pieces and other odds and ends.  Acorns litter the inside of the nest as well as a few odd glimpses of some shiny things.  A horrid, rank smell emits from the whole nest.",
]));
   set_search("nest",(:TO,"search_pile":));
   searched =1;
}
void reset() {
  ::reset();
  searched = 1;
}
void search_pile() {
  if(searched <= 0) {               
	 tell_object(TP,"It looks like the nest has been gone through already.");
        return ;
  }
  if (searched == 1) {  
     write("%^RESET%^%^ORANGE%^You carefully begin to sift through the nest, pulling out anything that may look interesting.%^RESET%^\n");
     tell_room(TO,"%^RESET%^%^ORANGE%^"+TPQCN+" begins sifting through the nest, pulling out any items of interest.%^RESET%^.", TP);
     switch(random(3)){
        case 0:
           ob = new("/std/obj/coins");
           ob->set_money("gold", random(200)+100);
           ob->move(TO);
           new(TMONDIR+"rsq.c")->move(TO);
           searched = 0;
           break ;
        case 1:
           ob = new("/d/magic/scroll");
           ob->set_spell(random(2)+3);
           ob->move(TO);
           new(TMONDIR+"rsq.c")->move(TO);
           searched = 0;
           break ;
        case 2:
           RANDGEAR->armor_me(TO,"armorlt",100,1,0);
           new(TMONDIR+"rsq.c")->move(TO);
           searched = 0;
           break ;
      }
     return ;     
   }
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^Higher up within the tree does not make you feel much better.  There is a small"
" ledge here that you can rest on, but not much more.  Darkness fills the voids both below and above you and"
" an overall, %^RESET%^%^BLUE%^oppressive, %^BOLD%^%^BLACK%^heavy feeling fills the %^RESET%^stale,"
" %^ORANGE%^musty %^BOLD%^%^BLACK%^air.  A strange smell fills the air here... One that you can't quite put"
" your finger on.%^RESET%^");
} 



