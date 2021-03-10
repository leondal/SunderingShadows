//fixed up code a bit as I was working on other files - I don't think it loads anymore though ~Circe~ 7/30/19
//updated to run from inherit with an extra AC point (hard gem), nienne 05/07

#include <std.h>
inherit "/d/common/obj/armour/breastplate.c";

string OWNER;

void init(){
   ::init();
   if(interactive(TP) && TP==ETO && !OWNER) OWNER = TPQN;
}

void create(){
   ::create();
   set_name("emerald plate");
   set_id(({"plate","breastplate","emerald breastplate"}));
   set_short("%^RESET%^%^GREEN%^Em%^BOLD%^er%^RESET%^a%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^d breastplate%^RESET%^");
   set_long("This plate sparkles in the light sending green prisms dancing over everything in the area.  It looks carved from a green flawless crystal and its facets are cut clean and true.  Its value must be near uncalculatable and its enchantment must be great as well to even have made such armor.");
  set_value(20000);
  set_wear((:TO,"extra_wear":));
  set_ac(6);
  set_property("enchantment",3);
}

int extra_wear(){
   if((int)ETO->query_highest_level()<25){
      tell_object(ETO,"You cannot master the magic in the armor and it refuses to be worn.");
      tell_room(EETO,""+ETOQCN+" seems depressed as "+ETO->QP+" emerald plate resists "+ETO->QP+" attemps to wear it.",ETO);
     return 0;
   }
   if((string)ETO->query_name() !=OWNER){
      tell_object(ETO,"%^BOLD%^%^GREEN%^The plate cannot be sized for anyone but the one it was carved for!%^RESET%^");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^GREEN%^You slide into the perfectly carved armor.%^RESET%^");
   tell_room(EETO,""+ETOQCN+" slides into a suit of perfectly carved crystal armor.",ETO);
   return 1;
}
