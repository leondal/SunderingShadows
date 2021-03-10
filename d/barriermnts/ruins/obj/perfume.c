#include <std.h>
#include "../inherit/ruins.h"
inherit OBJECT;

int uses;

void create(){
   ::create();
   set_name("perfume");
   set_id(({"perfume","bottle of perfume","vial of perfume"}));
   set_short("%^RESET%^%^ORANGE%^slender vial of perfume%^RESET%^");
   set_long("%^MAGENTA%^This small, slender vial is filled with a %^ORANGE%^dark amber%^MAGENTA%^ liquid "
"that shimmers in the light.  A faint scent comes from it that you can't quite place, of soft mixed "
"spices that tickle pleasantly at your nose.%^RESET%^");
   set_value(550);
   set_weight(1);
   set_lore("%^WHITE%^%^BOLD%^Perfumes such as these are common among women of the upper classes.  This "
"particular aroma was once commonly created in an area west of the Dagger regions, scented with several "
"autumn blossoms, and spiced lightly with cinnamon.%^RESET%^");
   set_property("lore difficulty",13);
}

void init() {
   :: init();
   add_action("wear_fun","wear");
}

int wear_fun(string str) {
   string long;
   int value;
   if(member_array(str,TO->query_id()) != -1) {
     if(uses > 4) {
       tell_object(TP,"There is no more perfume left in the vial.");
       return 1;
     }
     tell_object(TP,"%^ORANGE%^You dab on the softly-scented perfume.%^RESET%^");
     tell_room(ETP,"%^ORANGE%^"+TPQCN+" dabs on a little of the softly-scented perfume.%^RESET%^",TP);
     long = TP->query_long();
     TP->set("long","%^RESET%^%^ORANGE%^A faint aroma of soft spices scents the air around "
+TP->QO+".%^RESET%^");
     value = TO->query_value();
     value = value - 110;
     TO->set_value(value);
     uses++;
     if (uses > 4) {
       TO->set_short("%^RESET%^empty perfume vial");
       TO->set_long("%^MAGENTA%^This small, slender vial once held softly-spiced perfume, which you can "
"still smell faintly from the bottle. However, it is now empty.%^RESET%^");
       TO->set_value(1);
     }
     return 1;
   }
   return 0;
}
