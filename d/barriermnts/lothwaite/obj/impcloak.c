//altered silk cloak to add variety.  Circe 11/25/04
#include <std.h>

inherit ARMOUR;

void create() {
   ::create();
   set_name("demonskin cloak");
   set_id(({"cloak","skin","demonskin","demonskin cloak","imp cloak"}));
   set_short("%^RED%^Cloak of the Forked-tongue Devil%^RESET%^");
   set_obvious_short("%^RED%^a red rough hide cloak%^RESET%^");
   set_long("%^RED%^While this cloak is rough to the touch, it "+
      "has a smooth, leather-like look.  The cloak is long and "+
      "sleek, having enough material to be wrapped all the way "+
      "around the body or tossed back over the shoulders.  "+
      "The cloak closes at the neck with an unusual spike "+
      "made of a strange %^BOLD%^%^BLACK%^black material %^RESET%^"+
      "%^RED%^that does not seem to be metal.  The inside of the "+
      "cloak is lined with a soft %^BOLD%^%^BLACK%^black leather"+
      "%^RESET%^%^RED%^, and the whole garment seems to radiate "+
      "a hidden power all its own.");
   set_lore("The material of this cloak seems to be nothing from "+
      "this world - with good reason, as the cloak is made from "+
      "the skin of a demon!  The name of the cloak is derived from "+
      "the story of its creation.  Demons and devils have long "+
      "feuded and harbored a hatred for each other.  Occasionally, "+
      "victors from both sides will take body parts as trophies.  "+
      "This cloak was made by an imp who always manages to talk "+
      "his way through problems...and then kill said problem.  "+
      "The cloak's construction is known only to that imp.");
   set_property("lore difficulty",15);
   set_weight(2);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_property("enchantment",3);
   set_item_bonus("magic resistance",1);
   set_value(2500+random(3)*500);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
}

int wear_func() {
   if((int)ETO->query_lowest_level() < 20){
      tell_object(ETO,"The cloak refuses to be worn by one as puny as you!");
      return 0;
   }
   tell_object(ETO,"%^BOLD%^%^RED%^You feel the power of the demon wrap "+
      "itself around you.");
   tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" grows more fearsome "+
      "as "+ETO->QS+" wears the cloak.",ETO);
   return 1;
}

int remove_func() {
   tell_object(ETO,"You seem to shrink as you remove the cloak.");
   return 1;
}
 