//ptrail19.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   add_item("rocks", "The rubble to the west looks very unstable.");
   set_exits(([
      "west" : ROOMS"ptrail18",
      "southeast" : ROOMS"ptrail20"
      ]));

set_trap_functions(({"west"}),({"landslide"}),({"west"}));
}

int landslide(){
   if(TP->query_true_invis()) return 0;
   if((int)TP->query_stats("dexterity") > random(21)){
      tell_room(TO,"%^YELLOW%^"+TPQCN+" carefully picks "+TP->QP+" way along "+
         "the rocks as "+TP->QS+" moves west.",TP);
      tell_object(TP,"%^YELLOW%^You carefully make your way west.\n");
      TP->move(ROOMS"ptrail18");
      TP->force_me("look");
      return 1;
   }
    if(interactive(TP)){
   tell_object(TP,"%^BOLD%^%^RED%^As you start up the trail to the west, "+
      "the rocks break free, sending you skidding off the trail!%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" starts to walk away but disappears in a rockslide!",TP);
    TP->move(ROOMS"lslide2");
    toggle_trap("west");
    return 1;
    }
}
void reset(){
    ::reset();
    if(!trapped("west")){
        toggle_trap("west");
    }
}
