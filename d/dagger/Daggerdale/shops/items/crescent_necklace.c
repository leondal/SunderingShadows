#include <std.h>
inherit ARMOUR;

void create()
{
   ::create();
   set_name("silver necklace");
   set_short("%^BOLD%^%^WHITE%^A silver crescent moon necklace%^RESET%^");
   set_id(({"necklace","silver necklace","moon necklace","crescent moon necklace","crescent necklace","dagger_jewelry"}));
   set_long("%^BOLD%^%^WHITE%^The necklace has a chain of finely braided strands of silver."+
   " The pendant that hangs from it is also made of silver and is in"+
   " the shape of a crescent moon with a tiny %^CYAN%^crystal%^WHITE%^ that hangs from"+
   " the top point. Seated in the curve of the moon is a woman in a long"+
   " flowing gown who is done in fine detail and seems completely relaxed.");
   set_weight(2);
   set_value(150);
   set_type("ring");
   set_limbs(({"neck"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
}

int wearme()
{
   if((string)ETO->query_diety() == "selune") {
      tell_object(ETO,"%^BOLD%^The crystal glows with a faint blue light"+
      " as you slip it on.");
      return 1;
   }
   if((string)ETO->query_diety() == "shar") {
      tell_object(ETO,"You decide not to anger Selune by wearing one of her"+
      " tokens.");
      return 0;
   }
   return 1;
}

int removeme()
{
   if((string)ETO->query_diety() == "selune") {
      if(!random(4)) {
         tell_object(ETO,"You almost think the woman in the moon smiled at"+
         " you as you were removing the crescent necklace.");
         return 1;
      }
      tell_object(ETO,"You remove the precious crescent moon necklace.");
      return 1;
   }
   return 1;
}
