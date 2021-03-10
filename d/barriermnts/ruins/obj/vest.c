#include <std.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

void create() {
   ::create();
   set_name("tanned vest");
   set_short("%^RESET%^%^ORANGE%^Vest of the Zephyr%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^tanned vest%^RESET%^");
   set_id(({"vest","Vest","tanned vest","tan vest","zephyr vest","vest of the zephyr","Vest of the Zephyr"}));
   set_long("%^CYAN%^This particularly %^GREEN%^casual%^CYAN%^ article of clothing would only serve for "
"ascetic purposes.  The vest would cover very little of the wearer's chest, though it would obviously be "
"very light and comfortable to wear.  It has been crafted from soft, tanned cloth with the appearance of "
"%^ORANGE%^leather%^CYAN%^, though it is far too thin and light to be any sort of hide.  It is "
"sleeveless, and entirely open down the front.  A few attached slender straps could be laced across the "
"front to hold it in place, while leaving it entirely free and flowing.%^RESET%^\n");
   set_weight(5);
   set_value(735);
   set_ac(0);
   set_size(-1);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_lore("%^WHITE%^%^BOLD%^A particular akadian rogue, known only by the name of Eylean, was said to "
"have always worn a garment similar to this.  The rogue was supposedly distainful of most armor, "
"preferring instead to confuse his opponents as to just where he was standing.  This flowing vest only "
"served to make his body even harder to target properly in combat, and he always used this to his "
"advantage.%^RESET%^\n");
   set_property("lore difficulty",17);
   set_property("enchantment",3);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
}

int wear_fun() {
   if((string)ETO->query_gender() == "female") {
     tell_object(ETO,"%^WHITE%^%^BOLD%^You realise by looking at the garment that it would not cover "
"your chest at all, and you think better of wearing such a thing.");
     return 0;
   }
   tell_object(ETO,"%^ORANGE%^You shrug the vest over each arm, lacing up the loose straps down the "
"front.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" shrugs the vest over each of "+ETO->QP+" arms, and laces up the loose straps down the front.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^ORANGE%^You lightly tug upon one of the vest's straps, and let the garment slip "
"from your shoulders.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" tugs lightly upon one of the vest's straps, letting the "
"garment slip from "+ETO->QP+" shoulders.%^RESET%^",ETO);
   return 1;
}
