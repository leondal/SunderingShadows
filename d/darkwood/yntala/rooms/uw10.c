//uw10
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"underwater.c";
int searched;

void create(){
::create();
   set_air_pocket(15);
   set_long("%^RESET%^%^BLUE%^You've come to the end of a long, "
"%^BOLD%^%^BLACK%^dark, %^RESET%^%^BLUE%^underwater cavern system."
" The room here ends in what seems to be a dead end, leaving you"
" no way out but back the way you came. The %^BOLD%^%^CYAN%^"
"b%^RESET%^u%^CYAN%^b%^RESET%^b%^CYAN%^l%^RESET%^e%^BOLD%^"
"%^CYAN%^s %^RESET%^%^BLUE%^in this room are unusually large, "
"probably due to the fact that this room has a large amount"
" of %^ORANGE%^cracks %^BLUE%^compared to the rest of the tunnel."
"%^RESET%^");
   set_exits(([
"north":INRMS+"uw9"
]));
   set_items(([
      ({"crack","cracks"}):"%^BOLD%^%^BLACK%^There seems to be a slight %^CYAN%^glow %^BLACK%^coming from one of the cracks.%^RESET%^",
]));
   set_search("crack", (: TO, "search_pile" :) );
   set_search("cracks", (: TO, "search_pile" :) );
}

void reset() {
  object ob;
  ::reset();
  searched = 1 ;
}
void search_pile() {
  object ob;
  if(searched <= 0) {               
	 tell_object(TP,"It looks like this area has been searched already.");
        return ;
  }

  if (searched == 1) {  
     switch(random(5)){
        case 0:
          tell_object(TP,"%^BOLD%^%^WHITE%^Bubbles %^RESET%^f%^BOLD%^%^WHITE%^l%^CYAN%^o%^WHITE%^a%^RESET%^t up as a %^BOLD%^%^CYAN%^ring %^RESET%^pops out of the %^BOLD%^%^BLACK%^crack!%^RESET%^\n");
          tell_room(TO,""+TPQCN+" searches around and finds a %^BOLD%^%^CYAN%^ring %^RESET%^in one of the %^BOLD%^%^BLACK%^cracks!%^RESET%^", TP);
        new(OBJD+"aring.c")->move(TO);
          searched = 0;
          break;
        case 1:
          tell_object(TP,"%^BOLD%^%^WHITE%^Bubbles %^RESET%^f%^BOLD%^%^WHITE%^l%^CYAN%^o%^WHITE%^a%^RESET%^t up as a pair of %^BOLD%^%^CYAN%^leggings %^RESET%^pops out of the %^BOLD%^%^BLACK%^crack!%^RESET%^\n");
          tell_room(TO,""+TPQCN+" searches around and finds a pair of %^BOLD%^%^CYAN%^leggings %^RESET%^in one of the %^BOLD%^%^BLACK%^cracks!%^RESET%^", TP);
          new(OBJD+"leggings.c")->move(TO);
          searched = 0;
          break;
        case 2..4:
          tell_object(TP,"%^BOLD%^%^BLACK%^You dig your fingers around in the crack, but alas, nothing is there%^RESET%^.\n");
          tell_room(TO,"%^BOLD%^%^BLACK%^"+TPQCN+" digs a finger into the crack, but finds nothing!%^RESET%^", TP);

          searched = 0;
          break;
      }
  return 1;
   }
}
