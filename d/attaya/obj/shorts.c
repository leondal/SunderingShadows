//Cythera
#include <std.h>;
inherit "/std/armour";

void create(){
   ::create();
   set_name("shorts");
   set_id(({"shorts","leather shorts of the dervish","leather shorts"}));
   set_short("%^RESET%^%^ORANGE%^Leather Shorts of the %^GREEN%^D%^BOLD%^e"+
	"%^RESET%^%^CYAN%^r%^GREEN%^v%^BOLD%^i%^RESET%^%^CYAN%^s%^GREEN%^h%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A pair of long leather shorts%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Made from strong tough leather is this pair "+
	"of long shorts.  The leather is thick enough to protect the body but "+
	"thin enough not to be cumbersome. The shorts fit tight around the waist"+
	", the waistband %^GREEN%^quilted%^ORANGE%^ with some padding.  The"+
	" round edges curve and dip down slightly in the front, where thick "+
	"leather laces criss-cross down.  From there the shorts flare out, "+
	"fitting away from the body for a comfortable fit.  The long shorts "+
	"stop at the top of the calves, giving plenty of cover to the legs.  "+
	"The inside of the shorts are lined with a brushed %^GREEN%^green cotton"+
	"%^ORANGE%^ for comfort.  An interwoven %^GREEN%^g%^BOLD%^e%^RESET%^%^CYAN%^"+
      "o%^GREEN%^m%^BOLD%^e%^RESET%^%^CYAN%^t%^GREEN%^r%^BOLD%^i%^RESET%^%^CYAN%^c"+
      "a%^GREEN%^l%^ORANGE%^ pattern is stitched into the sides of the shorts.%^RESET%^\n");
   set_type("clothing");
   set_limbs(({"right leg","left leg"}));
   set_property("enchantment",5);
   set_lore("Tied to the warriors of the ancient Icarus Empire, these shorts"+
	" were worn by some of their best warriors.  The dervishes of Icarus "+
	"were trained from the age of five in the art of war, focusing on "+
	"brutal strength and swift attacks.  Though the warrior society "+
	"focused on the importance of physical strength they also instructed"+
	" all their warriors in finding an inner calmness through nature and "+
	"meditation. It was said that through meditation their minds were able "+
	"to enter a state of perfect calm that nothing could shake them.");
   set_property("lore",12);
   set_item_bonus("dexterity", 4); 
   set_weight(2);
   set_size(2);
   set_value(7500);
   set_wear((:TO,"wearme":));
   set_remove((:TO,"unwearme":));
}

int wearme(){
   if((string)ETO->query_gender() != "male"){
      tell_object(ETO,"%^GREEN%^Try as you might, you just can't fit "+
         "the shorts to your body!");
      return 0;
   }
   if((int)ETO->query_level() < 30) {
     tell_object(ETO,"The shorts just fall right off of you.");
     return 0;
   }

   tell_object(ETO,"%^ORANGE%^You pull on the shorts and lace them tight.");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" pulls on his shorts and lace them tight.",ETO);
   return 1;
}

int unwearme(){
   tell_object(ETO,"%^ORANGE%^You remove the shorts, missing it "+
      "already.");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" removes the shorts "+
      "with a soft sigh.",ETO);
   return 1;
}
