#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   set_name("opal ring");
   set_short("%^BOLD%^%^BLUE%^Water Opal Ring%^RESET%^");
   set_id(({"ring","opal ring","water opal ring"}));
   set_long("%^BOLD%^%^BLUE%^The ring is made out of an odd metal that has"+
   " a dark blue cast to it. The water opal is set in the center of the"+
   " ring, and although it is only of average size, its coloring seems to"+
   " be further enhanced by the metal, so that it appears to be made up of"+
   " darker blues.");
   set_weight(1);
   set_type("ring");
   set_limbs(({"right hand"}));
   set_wear((:TO,"wearme":));
   set_remove((:TO,"removeme":));
   set_value(250);
   set_size(random(3)+1);
}

int wearme()
{
   if((string)ETO->query_diety() == "istishia") {
      tell_object(ETO,"%^BOLD%^%^BLUE%^You feel the cool favor of Istishia"+
      " as you slip the ring on your finger.");
      return 1;
   }
   if((string)ETO->query_diety() == "kossuth") {
      tell_object(ETO,"You have a feeling it would make Kossuth very angry"+
      " if you wore a ring of Istishia's!");
      return 0;
   }
   return 1;
}

int removeme()
{
   if((string)ETO->query_diety() == "istishia") {
      tell_object(ETO,"%^BLUE%^You feel a slight loss as you remove the ring.");
   }
   return 1;
}
