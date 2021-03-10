//updated to run from inherit with an extra AC point (hard gem), nienne 05/07
#include <std.h>
inherit "/d/common/obj/armour/breastplate.c";
string OWNER;
void init(){
  ::init();
  if(interactive(TP) && TP==environment(TO)  && !OWNER) OWNER = TPQN;
}
  void create(){
  ::create();
  set_name("emerald plate");
  set_id(({"plate","breastplate","emerald breastplate"}));
  set_short("%^RESET%^%^GREEN%^Em%^BOLD%^er%^RESET%^a%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^d breastplate%^RESET%^");
  set_long("  This plate sparkles in the light sending green prisms dancing over everything in the area."
  "  It looks carved from a green flawless crystal and its facets are cut clean and true."
  "Its value must be near uncalculatable and its enchantment must be great as well to even have made such armor."
  );
 set_value(20000);
 set_wear((:TO,"extra_wear":));
  set_ac(6);
  set_property("enchantment",3);
}
int extra_wear(){
  if((int)TP->query_highest_level()<25){
   write("You cannot master the magic in the armor and it refuses to be worn.");
   say(""+TPQCN+" seems depressed as "+ETO->query_possessive()+" emerald plate resists "+ETO->query_possessive()+" attemps to wear it.");
  return 0;
  }
  if((string)TP->query_name() !=OWNER){
  write("%^BOLD%^%^GREEN%^The plate cannot be sized for anyone but the one it was carved for!%^RESET%^");
  return 0;
 }
  write("%^BOLD%^%^GREEN%^You slide into the perfectly carved armor.");
  say(""+TPQCN+" slides into a suit of perfectly carved crystal armor.");
  return 1;
}
