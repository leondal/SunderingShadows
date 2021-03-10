#include <std.h>
#include "../defs.h"
inherit ARMOUR;

void create() {
   ::create();
   set_name("leather boots");
   set_short("%^BOLD%^%^BLACK%^Dee%^RESET%^%^ORANGE%^p%^BOLD%^%^BLACK%^wal%^RESET%^%^BLUE%^k%^BOLD%^%^BLACK%^er's Boo%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^s%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^dusty %^BOLD%^%^BLACK%^leather boots%^RESET%^");
   set_id(({"boots","Boots","dusty boots","leather boots","dusty leather boots"}));
   set_long("%^ORANGE%^Crafted from dark leather, these boots are covered in a layer of %^BOLD%^%^BLACK%^stone "
"dust %^RESET%^%^ORANGE%^so thick you could never clean them properly. They have obviously been made for "
"%^WHITE%^small feet%^ORANGE%^, and have been made by a %^YELLOW%^master craftsman%^RESET%^%^ORANGE%^. The "
"soles are very thin, allowing the wearer to feel every %^WHITE%^pebble %^ORANGE%^under their feet. They lace "
"up with thick sturdy laces.%^RESET%^\n");
   set_weight(2);
   set_value(250);
   set_type("clothing");
   set_ac(0);
   set_size(1);
   set_lore("Such boots as these are commonly loved by the gnomes of underdark, known as Svirfneblin. They are "
"made to be protective, yet thin enough to feel the nuances and changes of the earth beneath them, for which "
"they hold a close affinity.\n");
   set_property("lore difficulty",7);
   set_property("enchantment",3);
   set_limbs(({ "right foot", "left foot" }));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if((int)ETO->query_lowest_level() < 10) {
     tell_object(ETO,"You need more training to use these boots!");
     tell_room(EETO,""+ETO->QCN+" can't seem to make sense of how to wear the boots!",ETO);
     return 0;
   }
   tell_object(ETO,"%^ORANGE%^You pull on the boots and lace them carefully, ensuring you can still feel every "
"feature of the ground beneath you.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" pulls on the boots, lacing them carefully.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^ORANGE%^You remove the boots slowly, as unlacing them takes awhile.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" takes awhile unlacing the boots.%^RESET%^",ETO);
   return 1;
}
