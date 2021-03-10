//Coded by ~Circe~ 5/30/07
#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("necklace of teeth");
	set_id(({"necklace","tooth necklace","necklace of teeth"}));
	set_short("%^BOLD%^%^BLACK%^Nec%^WHITE%^k%^BLACK%^la%^WHITE%^c"+
         "%^BLACK%^e of %^WHITE%^Teeth%^RESET%^");
      set_obvious_short("%^RESET%^%^ORANGE%^a leather necklace%^RESET%^");
      set_long("%^RESET%^%^ORANGE%^This necklace has been formed from "+
         "several strips of thin leather woven together to make a "+
         "flat band.  Hanging by thin leather thongs are countless "+
         "%^RESET%^teeth %^ORANGE%^of various people and beasts.  "+
         "One %^BOLD%^%^BLACK%^blackened tooth %^RESET%^%^ORANGE%^"+
         "hangs in the center - a curious, triangular thing that "+
         "curves inward near the tip.%^RESET%^");
      set_lore("Crafted by a yuan-ti warrior, this necklace is "+
         "said to be made only from the flesh and teeth of beasts "+
         "the yuan-ti killed.  Many such necklaces are fashioned "+
         "from humanoid flesh, as the yuan-ti find this to be "+
         "most intimidating and distasteful to their foes.  The "+
         "blackened tooth was most likely taken from a tabaxi, "+
         "whom yuan-ti seem to relish killing.");
 	set_weight(2);
	set_value(700+random(100));
	set_type("clothing");
	set_limbs(({"neck"}));
      set_ac(random(2));
	set_property("enchantment",3);
      set_wear((:TO,"wearme":));
      set_remove((:TO,"removeme":));  
}

int wearme() {
   tell_object(ETO,"%^BOLD%^%^BLACK%^You savagely tie on the "+
      "%^RESET%^%^ORANGE%^necklace of teeth %^BOLD%^%^BLACK%^"+
      "and feel the might of the beast within you.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" ties a necklace "+
      "made of teeth and leather around "+ETO->QP+" neck.%^RESET%^",ETO);
   ETO->set_property("magic resistance",10);
   ETO->add_stat_bonus("intelligence",-1);  //beast dumb
   return 1;
}

int removeme() {
   tell_object(ETO,"%^RESET%^%^ORANGE%^The spirit of the beast "+
      "releases its hold on you as you remove the necklace.%^RESET%^");
   if(!ETO->query_invis()) {
      tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETOQCN+" blinks several "+
         "times as "+ETO->QS+" removes a necklace.%^RESET%^",ETO);
   }
   ETO->set_property("magic resistance",-10);
   ETO->add_stat_bonus("intelligence",1);
   return 1;
}
