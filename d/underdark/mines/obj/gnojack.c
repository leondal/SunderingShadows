//Octothorpe (8/25/08)
//Underdark Mining Caverns, Gnomish Leather Jack +3 (Studded Leather +3)

#include <std.h>
inherit "/d/common/obj/armour/studded.c";

void create(){
   ::create();
   set_name("leather jack");
   set_id(({"leather","jack","leather jack","armor","jacket"}));
   set_short("%^ORANGE%^small leather jack%^RESET%^");
   set_long("%^ORANGE%^This jack, which is sometimes also known as "+
      "a gambeson or aketon, is a quilted leather jacket that has been "+
      "stuffed with some sort of padding.  Lightweight rings of "+
      "%^RESET%^svirfneblin %^ORANGE%^manufacture are cleanly sewn onto "+
      "the leather.  The rings are close enough to provide nearly "+
      "uninterrupted protection, yet make no noise when they rub "+
      "together.%^RESET%^");
   set_lore("This is the standard issue armor of svirfneblin mining "+
      "expeditions in the Underdark. Due to the hazardous environs, "+
      "normal procedure dictates that half of the party mines while "+
      "the other half watches guard over the mining. The guards wear "+
      "the mail shirts, whereas the miners strip down to leather "+
      "gambesons for comfort.");
   set_size(1);
   set_property("lore",12);
   set_property("enchantment",3);
   set_item_bonus("magic resistance",1);
   set_value(400+random(150));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun(){
   if((int)ETO->query_lowest_level() < 15){
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" has some difficulties putting "+
         "on the %^ORANGE%^leather %^WHITE%^jack.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^Putting on this %^ORANGE%^leather "+
         "%^WHITE%^jack seems slightly more complicated that you "+
         "originally thought. Perhaps you need more training to figure "+
         "it out.%^RESET%^");
      return 1;
   }
   tell_room(EETO,"%^BOLD%^%^ORANGE%^"+ETOQCN+" slides their arms into "+
      "the jack and begins to quickly ties the knots that secure the "+
      "front of the armor.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^ORANGE%^You slide your arms into the jack "+
      "and begin to tie the knots that run down the front.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^ORANGE%^"+ETOQCN+" unties the knots that "+
      "run down the front of the jack, and casually slides their arms "+
      "out of the sleeves of the armor.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^ORANGE%^You untie the knots that run "+
      "down the front of the jack, and casually slide your arms out "+
      "of the sleeves.%^RESET%^");
   return 1;
}
