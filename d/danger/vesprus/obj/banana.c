inherit "/std/food.c";

#include <std.h>
#include "../vesprus.h"
int peeled;

void create(){
   ::create();
  set_name("%^YELLOW%^Banana%^RESET%^");
  set_id(({"banana","fruit","food"}));
  set_strength(7);
  set_weight(1);
  set_short("%^YELLOW%^A ripe banana%^RESET%^");
  set_destroy();
  set_long("%^YELLOW%^This piece of fruit is long, yellow and curved slightly.  The outer peel of it looks to be quite thick.%^RESET%^");
  set_your_mess("%^YELLOW%^takes one big bite of the banana, peel and all, before making a most disgusting face.%^RESET%^");
  set_my_mess("%^YELLOW%^Yuck!! The peel of the fruit is horribly thick and sour tasting.  Next time you might want to peel it before eating it.%^RESET%^");
  }
void init(){
  ::init();
  add_action("peel","peel");
}
int peel(string str){ 
   tell_object(TP,"%^RESET%^You carefully pull back the %^YELLOW%^peel %^RESET%^of the %^YELLOW%^banana %^RESET%^to expose the soft %^BOLD%^fruit %^RESET%^beneath.%^RESET%^");
   tell_room(ETP,"%^RESET%^"+TPQCN+" carefully pulls back the %^ORANGE%^peel %^RESET%^of the %^YELLOW%^banana %^RESET%^to expose the soft %^BOLD%^fruit %^RESET%^beneath.",TP);
   new("/d/danger/vesprus/obj/pbanana.c")->move(ETO);
   new("/d/danger/vesprus/obj/bananapeel.c")->move(ETO);
   TO->remove();
   return 1;
}
   

