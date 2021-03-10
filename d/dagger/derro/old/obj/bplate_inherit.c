//This is the inherit for the gem breastplates given by 
//the pech.  Do not remove this file!  It's here for 
//easier maintenance.
//~Circe~ 5/20/05
//converted to run from breastplate inherit with an extra AC point (hard gem). Nienne, 05/07
#include <std.h>
inherit "/d/common/obj/armour/breastplate.c";
string OWNER;

void init(){
  ::init();
  if(interactive(TP) && TP==environment(TO)  && !OWNER) OWNER = TPQN;
}

void create(){
  ::create();
  set_name("breastplate");
  set_id(({"plate","breastplate","gem breastplate","crystalline breastplate"}));
  set_obvious_short("a crystalline breastplate");
//short, long, and lore taken care of in the individual files
/*
  set_short("%^RESET%^%^GREEN%^Em%^BOLD%^er%^RESET%^a%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^d breastplate%^RESET%^");
  set_long("  This plate sparkles in the light sending green prisms dancing over everything in the area."
  "  It looks carved from a green flawless crystal and its facets are cut clean and true."
  "Its value must be near uncalculatable and its enchantment must be great as well to even have made such armor."
  );
*/
   set_value(20000);
   set_wear((:TO,"extra_wear":));
   set_ac(6);
   set_property("enchantment",3);
}

int extra_wear(){
  if((int)ETO->query_highest_level()<25){
   tell_object(ETO,"You cannot master the magic in the armor, "+
      "and it refuses to be worn.");
   tell_room(EETO,""+ETOQCN+" seems depressed as "+ETO->QP+" crystalline "+
      "breastplate resists "+ETO->QP+" attemps to wear it.",ETO);
   return 0;
  }
  if((string)ETO->query_name() !=OWNER){
   tell_object(ETO,"%^BOLD%^%^RED%^The plate cannot be sized for "+
      "anyone but the one it was carved for!%^RESET%^");
   return 0;
  }
  tell_object(ETO,"%^BOLD%^%^BOLD%^You slide into the perfectly carved "+
     "armor, and it glows softly in response to your touch.");
  tell_room(EETO,"%^BOLD%^"+ETOQCN+" slides into a breastplate of a "+
     "perfectly carved gemstone, which begins to glow.",ETO);
  ETO->set_property("magic resistance",10);
  return 1;
}
