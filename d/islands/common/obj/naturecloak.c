//naturecloak.c - altered cloak of silk
#include <std.h>
//Four other cloaks are being copied from this one.

inherit ARMOUR;

void create() {
   ::create();
   set_name("cloak of nature");
   set_id( ({"cloak","cloak of nature","nature cloak"}) );
   set_obvious_short("%^BOLD%^%^GREEN%^A c%^RESET%^%^GREEN%^l%^RESET%^%^RED%^o%^BOLD%^%^RED%^a%^BOLD%^%^YELLOW%^k%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Cloak of %^GREEN%^N%^RESET%^%^GREEN%^a%^RED%^t%^BOLD%^u%^YELLOW%^r%^RESET%^%^ORANGE%^e%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This cloak is fashioned from high quality silk "+
      "that has been magically enchanted to change with the seasons.  "+
      "%^BOLD%^%^GREEN%^In springtime, it is a brilliant, verdant green full "+
      "of new life and rebirth.  %^RESET%^%^GREEN%^In the heat of summer, it reveals "+
      "the strong, deep browns and greens of the earth.  %^RESET%^%^RED%^In autumn, "+
      "brilliant %^BOLD%^reds %^RESET%^%^RED%^and %^YELLOW%^golds %^RESET%^%^RED%^"+
      "mix together to camoflauge the wearer.  %^BOLD%^%^WHITE%^Finally, wintertime "+
      "brings with it a spectacular %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r "+
      "hue.  Magical inscriptions have been embroidered around the edge of the cloak "+
      "in thread-of-silver.");
   set_weight(2);
   set_type("clothing");
   set_limbs( ({"neck"}) );
   set_property("enchantment",5);
   set_item_bonus("spell damage resistance",25);
   set_item_bonus("survival",5);
   set_value(500+random(3)*500);
   set_wear( (: TO,"wear_func" :) );
   set_remove( (: TO,"remove_func" :) );
   set_read("The runes reveal the magic of the cloak:\n"+
      "The wearer of this cloak will find warmth in all seasons within Mielikki's embrace.");
}

int wear_func() {
   tell_object(TP,"%^BOLD%^%^GREEN%^You feel yourself wrapped in Mielikki's embrace as you wear the cloak.");
   return 1;
}

int remove_func() {
   write("%^GREEN%^You relinguish the cloak with a sigh and a prayer to Mielikki.");
   return 1;
}
