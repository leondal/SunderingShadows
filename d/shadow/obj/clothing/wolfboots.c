// updated dex bonus from the new system. Nienne, 09/07.
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("boots of the wolves");
   set_id( ({"boots","wolves","wolves boots","boot"}) );
   set_short("%^BOLD%^%^BLACK%^Boots of the %^RED%^W%^RESET%^%^RED%^o"+
        "%^BOLD%^%^BLACK%^l%^RED%^v%^RESET%^%^RED%^e%^BOLD%^s%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A pair of riding boots%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This is a pair of riding boots with some "
     "%^RED%^red wolf%^BOLD%^%^BLACK%^ tattoos on the blackened leather"+
     " surface. The heavy boots rise up to protect the lower legs.  "+
     "Thick leather soles make the boots difficult to walk in, without"+
     " much practice or strength.  The boots have a regal style to them, "+
     "dispite the tattoos, as if they once might have been a fine pair of"+
     " footwear.  Tarnished mithril spurs are still attached to the boots,"+
     " though time has ruined them.%^RESET%^");
   set_type("clothing");
   set_limbs( ({"right foot", "left foot"}) );
   set_weight(3);
   set_value(600);
   set_property("enchantment",1);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
   set_item_bonus("dexterity",1);
}

int wear_func() {
   if((int)ETO->query_highest_level() < 8) {
      tell_object(ETO,"You are not capable of using them.\n");
      return 0;
   }
   write("%^BOLD%^%^BLACK%^You put on the boots and feel a little more "
      "protected.%^RESET%^");
   return 1;
}

int remove_func() {
   tell_object(ETO,"%^BOLD%^%^BLACK%^You feel less protected as you "
      "remove the boots.%^RESET%^");
   return 1;
}