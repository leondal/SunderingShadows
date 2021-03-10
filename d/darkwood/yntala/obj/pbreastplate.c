#include <std.h>
inherit "/d/common/obj/armour/breastplate.c";
string OWNER;
void init(){
   ::init();
  if(interactive(TP) && TP==environment(TO)  && !OWNER) OWNER = TPQN;
}
   void create(){
   ::create();
   set_name("%^BOLD%^%^WHITE%^P%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^l breastplate");
   set_id(({"plate","pearl breastplate","breastplate"}));
   set_obvious_short("A white breastplate");
   set_short("%^BOLD%^%^WHITE%^P%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^l breastplate%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Thousands of small"
" p%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^"
"l%^RESET%^s %^BOLD%^%^WHITE%^have been %^CYAN%^magically"
" %^WHITE%^bound together to form this exquisite breastplate that"
" %^CYAN%^s%^WHITE%^h%^RESET%^i%^YELLOW%^m%^RESET%^m%^YELLOW%^"
"e%^WHITE%^r%^CYAN%^s %^WHITE%^in the light.  The craftsmanship"
" is superb, making this armor a piece of art in addition to the"
" great protection it offers%^RESET%^.\n");
   set_value(5000);
   set_wear((:TO,"wear_me":));
   set_property("enchantment",2);
}
int wear_me(){
   if((int)ETO->query_level()<12){
   tell_object(ETO,"%^BOLD%^%^CYAN%^The armor refuses to let you wear it%^RESET%^.");
   return 0;
   }
   if((string)ETO->query_name() !=OWNER){
   tell_room(ETO,"%^BOLD%^%^WHITE%^The armor cannot be worn by anyone but it's true master%^RESET%^!");
   return 0;
   }
   tell_object(ETO,"%^BOLD%^%^WHITE%^The p%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^l%^RESET%^s %^BOLD%^%^WHITE%^in the breastplate %^CYAN%^shimmer %^WHITE%^as you slide into the armor.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^The p%^RESET%^e%^BOLD%^%^BLACK%^a%^RESET%^r%^BOLD%^%^WHITE%^l%^RESET%^s %^BOLD%^%^WHITE%^in the breastplate %^CYAN%^shimmer %^WHITE%^as the armor is worn.%^RESET%^",ETO);
   return 1;
}
