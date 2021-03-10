#include <std.h>
#include "../inherit/ruins.h"
inherit OBJECT;

int uses;

void create(){
   ::create();
   set_name("perfume");
   set_id(({"oils","scented oils","softly scented oils","bottle of oils","bottle of scented oils"}));
   set_short("%^RESET%^%^MAGENTA%^softly scented oils%^RESET%^");
   set_long("%^CYAN%^Pale %^MAGENTA%^violet%^CYAN%^ oils filled this little, elaborately-sculpted "
"bottle.  A gentle, exotic aroma fills the air around it, that reminds you of several different flowers "
"at once, touched with a hint of honey.%^RESET%^");
   set_value(1100);
   set_weight(1);
   set_lore("%^WHITE%^%^BOLD%^Scented oils are often used in place of various perfumes, though because "
"of their undiluted nature, they are generally far more valuable.  This particular oil was commonly "
"crafted many decades ago, from a rare species of orchid that only grew in the Dagger regions, drawn "
"carefully from the nectar of the flowers.%^RESET%^");
   set_property("lore difficulty",14);
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
       tell_object(TP,"The little bottle is empty.");
       return 1;
     }
     tell_object(TP,"%^MAGENTA%^You wear a little of the gentle-smelling oils.%^RESET%^");
     tell_room(ETP,"%^MAGENTA%^"+TPQCN+" dabs on a little of the gentle-smelling oils.%^RESET%^",TP);
     long = TP->query_long();
     TP->set("long","%^RESET%^%^MAGENTA%^"+capitalize(TP->QS)+" is surrounded by the gentle smell of "
"flowers and honey.%^RESET%^");
     value = TO->query_value();
     value = value - 200;
     TO->set_value(value);
     uses++;
     if (uses > 4) {
       TO->set_short("%^RESET%^empty bottle of scented oils");
       TO->set_long("%^CYAN%^This little, elaborately-sculpted bottle once held sweet-smelling oils, "
"that you can still smell faintly around it. However, it is now empty.%^RESET%^");
       TO->set_value(100);
     }
     return 1;
   }
   return 0;
}
