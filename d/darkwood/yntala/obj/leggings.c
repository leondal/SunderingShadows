#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
      set_name("%^BLUE%^W%^CYAN%^a%^BOLD%^%^CYAN%^t%^RESET%^%^CYAN%^e%^BLUE%^r leggings.%^RESET%^");
      set_short("%^RESET%^%^CYAN%^A pair of %^BOLD%^%^CYAN%^light %^RESET%^%^BLUE%^b%^RESET%^%^CYAN%^l%^BOLD%^%^BLUE%^u%^CYAN%^e %^RESET%^%^CYAN%^leggings%^RESET%^");
      set_id(({"leggings","pants","water leggings"}));
      set_long("%^CYAN%^These leggings are rather unusual in"
" design. They are a soft %^BOLD%^%^CYAN%^light %^BLUE%^b%^RESET%^"
"%^BLUE%^l%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^e color that seems to"
" constantly shift in shade as if they themselves were made of"
" %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^a%^BLUE%^t%^CYAN%^e"
"%^BOLD%^%^CYAN%^r. %^RESET%^%^CYAN%^Though the material looks"
" unfamilar, they look to be quite light and comfortable"
".%^RESET%^\n");
      set_weight(3);
      set_value(200);
      set_ac(0);
      set_type("clothing");
      set_limbs(({"right leg","left leg"}));
      set_wear((:this_object(),"wearme":));
      set_remove((:this_object(),"unwearme":));
}
int wearme(string str){
   tell_room(environment(ETO),"%^BLUE%^"+ETOQCN+" slides into the comfortable leggings.%^RESET%^",ETO);
   tell_object(ETO,"%^CYAN%^You don't know if you've ever felt something quite as comfortable as these leggings.%^RESET%^");
   return 1;
}
int unwearme(string str){
   tell_room(environment(ETO),"%^BLUE%^"+ETOQCN+" doesn't look happy as "+ETO->query_subjective()+" removes the leggings.%^RESET%^",ETO);
   tell_object(ETO,"%^CYAN%^As you remove the leggings, you can't help but wonder why you are doing it.%^RESET%^");
   return 1;
}
void init(){
    ::init();
  if(!objectp(TP)) return;
  if (!objectp(ETO)) return;
  if (TP != ETO) return;
  if(interactive(TP) && !avatarp(TP)) {
     set_size(TP->query_size());
  }
}