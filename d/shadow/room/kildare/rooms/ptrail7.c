//ptrail7.c
#include "../kildare.h"

inherit PTRAIL;

void create()
{
   ::create();
   add_item("rocks", "The rubble to the northeast looks very unstable.");
   set_exits(([
      "south" : ROOMS"ptrail6",
      "northeast" : ROOMS"ptrail8"
      ]));

set_trap_functions(({"northeast"}),({"landslide"}),({"northeast"}));
}

int landslide(){
   if(TP->query_true_invis()) return 0;
   if((int)TP->query_stats("dexterity") > random(21)){
      tell_room(TO,"%^YELLOW%^"+TPQCN+" carefully picks "+TP->QP+" way along "+
         "the rocks as "+TP->QS+" moves northeast.",TP);
      tell_object(TP,"%^YELLOW%^You carefully make your way northeast.\n");
      TP->move(ROOMS"ptrail18");
      TP->force_me("look");
      return 1;
   }
    if(interactive(TP)){
    tell_object(TP,"%^BOLD%^%^RED%^As you start up the trail to the northeast, "+
      "the rocks break free, sending you skidding off the trail!%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^RED%^"+TPQCN+" starts to walk away but disappears in a rockslide!",TP);
    TP->move(ROOMS"lslide1");
    toggle_trap("northeast");
    return 1;
    }
}
void reset(){
    ::reset();
    if(!trapped("northeast")){
        toggle_trap("northeast");
    }
}
