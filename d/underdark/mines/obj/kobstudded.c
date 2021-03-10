//Octothorpe (1/18/09)
//Underdark Mining Caverns, Kobold Gem-Studded Leather +3 

#include <std.h>
inherit "/d/common/obj/armour/studded.c";

void create(){
   ::create();
   set_name("gem-studded leather");
   set_id(({"leather","gem-studded","studded leather","armor","studded","gem leather","gem"}));
   set_short("%^BOLD%^%^BLACK%^suit of %^RED%^g%^GREEN%^e%^BLUE%^m"+
      "%^BOLD%^%^BLACK%^-studded leather%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This leather armor shows a high level of "+
      "workmanship. It is constructed from a lightweight, yet sturdy "+
      "black leather. The armor is a creative interpretation of studded "+
      "leather armor, dotted with an assortment of precious %^RED%^g"+
      "%^GREEN%^e%^BLUE%^m%^ORANGE%^s %^BOLD%^%^BLACK%^and %^RESET%^"+
      "me%^BOLD%^%^YELLOW%^t%^WHITE%^a%^BOLD%^%^BLACK%^%^RESET%^ls"+
      "%^BOLD%^%^BLACK%^. At first glance the placement appears to be "+
      "nothing more than a hodge-podge, but after more concentration, "+
      "a definite shape forms out of seeming chaos. The shape resembles "+
      "that of a stylized claw, similar to that of a Malarite icon, "+
      "but reptilian in nature.%^RESET%^\n");
   set_lore("Religion is an integral part of kobold society. Most kobold "+
      "worship is centered around worship of The Earthlord, in the "+
      "guise of Kurtulmak, or the veneration of dragons. Frequently "+
      "this dragon veneration is centered upon one dragon in particular "+
      "which the worship, and attempt to serve. Honored protectors of "+
      "the community are dubbed Claws of the Venerated Dragon, gifted "+
      "with the sacred kobold claws and armor befitting a kobold hero.\n "+
      "-An excerpt from 'On the Kobold Race,' by Thaddeus Kranzot");
   set_size(1);
   set_property("lore difficulty",12);
   set_property("enchantment",3);
   set_value(300+random(150));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun(){
   if((int)ETO->query_lowest_level() < 15){
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" seems flummoxed as "+ETO->QP+" "+
         "tries to wear the studded leather.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^You are confused by the excessive "+
         "amounts of straps and ties on this armor. Perhaps you need "+
         "more training to figure out how to wear this armor.%^RESET%^");
      return 0;
   }
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" dons the studded "+
      "leather, and the %^RED%^g%^GREEN%^e%^BLUE%^m%^ORANGE%^s %^WHITE%^"+
      "glitter %^BOLD%^%^BLACK%^in the light hypnotically."+
      "%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^The light %^WHITE%^glitters "+
      "%^BOLD%^%^BLACK%^hypnotically off the %^RED%^g%^GREEN%^e%^BLUE%^"+
      "m%^ORANGE%^s %^BOLD%^%^BLACK%^as you wear the armor.%^RESET%^");
   if((string)ETO->query_race() == "kobold") set_item_bonus("stealth",2);
   else set_item_bonus("stealth",0);
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^BLACK%^The %^WHITE%^glittering %^RED%^g"+
      "%^GREEN%^e%^BLUE%^m%^ORANGE%^s %^BOLD%^%^BLACK%^dim as "+ETOQCN+" "+
      "removes "+ETO->QP+" armor.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^The %^WHITE%^glittering %^RED%^g"+
      "%^GREEN%^e%^BLUE%^m%^ORANGE%^s %^BOLD%^%^BLACK%^dim noticeably "+
      "as you remove the studded armor.%^RESET%^");
   return 1;
}
