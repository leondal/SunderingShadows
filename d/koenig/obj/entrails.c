// updated cha bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
      set_name("%^RESET%^%^RED%^Necklace of %^ORANGE%^en%^RED%^t%^ORANGE%^rai%^RED%^l%^ORANGE%^s%^RESET%^");
      set_short("%^RESET%^%^ORANGE%^A necklace made of %^RED%^entrails%^RESET%^");
      set_id(({"necklace","Necklace of entrails","necklace of entrails", "entrails"}));
      set_long("%^RESET%^%^BLUE%^This necklace is a solid, %^ORANGE%^stinking"
" cord %^BLUE%^made from the %^RED%^entrails %^BLUE%^of some poor creature."
"  %^BOLD%^%^BLUE%^Blue v%^RESET%^%^RED%^e%^BOLD%^%^BLUE%^in%^RESET%^%^RED%^i"
"%^BOLD%^%^BLUE%^ng %^RESET%^%^BLUE%^can still be seen tracing through it, as well"
" as a few %^GREEN%^gr%^BLUE%^e%^GREEN%^e%^BLUE%^n%^GREEN%^is%^BLUE%^h-b%^GREEN%^"
"l%^BLUE%^u%^GREEN%^e lumps %^BLUE%^here and there.  %^RED%^Blood %^BLUE%^still"
" drips from some of the torn, %^ORANGE%^fleshy pieces %^BLUE%^of the necklace,"
" and the %^ORANGE%^stench %^BLUE%^coming from it is almost unbearable.%^RESET%^\n");
      set_lore("It is impossible to tell from what sort of creature "+
         "these entrails came.  It is quite obvious, however, that "+
         "anyone wearing such a foul thing would not be fit for "+
         "any sort of society, perhaps save that of the brute "+
         "races such as ogres who prize trophies of the kind.");
      set_property("lore difficulty",2);
      set_weight(1);
      set_value(0);
      set_ac(0);
      set_type("clothing");
      set_limbs(({"neck"}));
      set_size(-1);
      set_wear((:this_object(),"wearme":));
      set_remove((:this_object(),"unwearme":));
	set_property("enchantment",1);
      set_item_bonus("charisma",-1);
}
int wearme(string str){
      tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" takes a deep breath and smiles sadistically as "+ETO->query_subjective()+" slips the %^RED%^dripping %^ORANGE%^necklace on.%^RESET%^",ETO);
      tell_object(ETO,"%^RESET%^%^ORANGE%^You take a deep breath and hold it as a sadistic smile crosses your face when you slip on the %^RED%^dripping %^ORANGE%^necklace.%^RESET%^");
      return 1;
}
int unwearme(string str){
   tell_room(environment(ETO),"%^RESET%^%^ORANGE%^"+ETOQCN+" is able to breath again as "+ETO->query_subjective()+" takes off the smelly necklace.%^RESET%^",ETO);
   tell_object(ETO,"%^RESET%^ORANGE%^You can breath again as you take off the smelly necklace.%^RESET%^");
   return 1;
}