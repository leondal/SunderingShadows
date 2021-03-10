#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("opal necklace");
   set_short("%^BOLD%^%^CYAN%^Water Opal Necklace%^RESET%^");
   set_id(({"necklace","opal necklace","water opal necklace"}));
   set_long("%^BOLD%^%^CYAN%^The necklace has a braided silver chain that"+
   " holds a water opal pendant. The opal itself is large and beautiful,"+
   " constantly shifting colors in the light to various shades of blues."+
   " It is a favorite of Istishians.");
   set_weight(1);
   set_type("ring");
   set_limbs(({"neck"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   set_value(375);
   set_size(random(3)+1);
}

int wearme()
{
   if((string)ETO->query_diety() == "istishia") {
      tell_object(ETO,"%^BOLD%^%^CYAN%^You feel the cool favor of Istishia"+
      " as you slip the necklace around your neck.");
      return 1;
   }
   if((string)ETO->query_diety() == "kossuth") {
      tell_object(ETO,"You have a feeling it would make Kossuth very angry"+
      " if you wore a necklace of Istishia's!");
      return 0;
   }
   return 1;
}

int removeme()
{
   if((string)ETO->query_diety() == "istishia") {
      tell_object(ETO,"%^CYAN%^You feel a slight loss as you remove the necklace.");
   }
   return 1;
}
