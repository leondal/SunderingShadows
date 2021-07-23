#include <std.h>
inherit "/std/armour";


void create()
{
	::create();
      set_name("%^BOLD%^%^WHITE%^Starissa's Crown%^RESET%^");
      set_id(({"crown","wood crown","wooden crown","forest crown","Starissa's crown"}));
      set_short("%^BOLD%^%^WHITE%^A crown of pointed, %^RESET%^b%^BOLD%^o%^RESET%^ne%^BOLD%^-%^RESET%^wh%^BOLD%^i%^RESET%^te driftwood%^RESET%^");
      set_long("%^RESET%^%^ORANGE%^This %^BOLD%^%^WHITE%^crown %^RESET%^%^ORANGE%^is almost impossibly formed out of a single piece of %^RESET%^driftwood %^ORANGE%^that has curled into the perfect shape"
         " to fit the top of a person's head.  The surface of the %^RESET%^wood %^ORANGE%^is %^RESET%^b%^BOLD%^o%^RESET%^ne%^BOLD%^-wh%^RESET%^i%^BOLD%^t%^RESET%^e%^ORANGE%^,"
        " %^BOLD%^%^WHITE%^bleached %^RESET%^%^ORANGE%^through a thousand turns in the %^RESET%^%^CYAN%^t%^BOLD%^i%^RESET%^%^CYAN%^de %^ORANGE%^to clean it of %^RESET%^%^ORANGE%^bark%^ORANGE%^, %^CYAN%^imperfections%^ORANGE%^,"
   " and %^RESET%^color%^ORANGE%^.%^RESET%^\n");
      set_lore("%^BOLD%^%^WHITE%^Starissa Longbow was rumored to be a powerful elven druid from long ago.  It is said that she hand a longstanding Talossian rival, Ekarath, who used his mighty power to call in the great tides of the sea to flood the low lying forests and destroy them."
         " After a lengthy battle that ended with the retreat of the mad cleric, Starissa found a crown like this amongst the items left behind from the receding tides.  It was rumored to be a gift from the great stag himself for her service to the forests, and since then, some of the most talented of elven craftsmen and enchanters have made effort to replicate the crown in an effort to forever remember and honor the mighty Starissa.");
      set_weight(3);
         set_property("repairtype",({"woodwork"}));
      set_armor_prof("light");
      set_wear((:TO,"wear":));
	set_value(575);
         set_type("leather");
	set_limbs(({"head"}));
	set_ac(0);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
//      set_property("enchantment",5);
     set_item_bonus("survival",5);
     set_property("no disenchant",1);
}


int wear(){
   if((ETO->is_class("druid")) || (ETO->is_class("ranger"))){
      tell_object(ETO,"%^BOLD%^%^WHITE%^Your heart swells with pride in remembrance of Starissa.%^RESET%^");
      set_item_bonus("wisdom",4);
     return 1;
   }
      else{
      tell_object(ETO,"%^RESET%^%^ORANGE%^You feel unworthy of the crown as you place it atop your head.%^RESET%^");
     set_item_bonus("wisdom",2);
      return 1;
      }
   }


