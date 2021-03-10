#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
      set_name("%^RESET%^%^ORANGE%^Bracelet of Brambles%^RESET%^");
      set_short("%^RESET%^%^ORANGE%^A bracelet of brambles%^RESET%^");
      set_id(({"bracelet","bracelet of brambles","Bracelet of brambles", "brambles bracelet"}));
      set_long("%^RESET%^%^ORANGE%^This is a rather unusual"
" circle of brambles.  About an inch wide, the vines from many"
" thornbushes have been woven together in an intricate design so" 
" that all the thorns are pointed towards the outer edges of the"
" circle rather than the inside.  It is probably safe to assume"
" this has been done purposely to ensure that the wearer does not"
" harm themself when attempting to wear it.%^RESET%^\n");
      set_weight(1);
      set_value(50);
      set_ac(0);
      set_type("clothing");
      set_limbs(({"right arm"}));
      set_size(2);
      set_wear((:this_object(),"wearme":));
      set_remove((:this_object(),"unwearme":));
}
int wearme(string str){
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" gets a wild glint in "+ETO->query_possessive()+" eyes as "+ETO->query_subjective()+" slips on the bracelet of brambles.%^RESET%^",ETO);
      tell_object(ETO,"%^RESET%^%^ORANGE%^You get a wild glint in your eye as you slip on the bracelet of brambles.%^RESET%^");
      return 1;
}
int unwearme(string str){
   tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" reluctantly removes the bracelet.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^ORANGE%^You reluctantly remove the bracelet.%^RESET%^");
   return 1;
}