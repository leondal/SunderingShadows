#include <std.h>
inherit ARMOUR;

void create(){
   ::create();
   set_name("boots");
   set_id(({"boots","red boots","way of the warrior"}));
   set_obvious_short("%^RESET%^%^RED%^dark red boots%^RESET%^");
   set_short("%^BOLD%^%^RED%^W%^RESET%^%^RED%^ay of the %^BOLD%^%^RED%^W%^RESET%^%^RED%^arrior%^RESET%^");
   set_long(
   "%^RESET%^%^RED%^These dark red boots are crafted of fine old leather that does barely shows its age. The insides are lined with the soft red furs of a mazique. There are no writings or runes along the boots anywhere, but there are several markings from years of use."
   );
   set_lore(
   "These boots are rumored to have been seen on the feet of many warriors that have come to pass. Some of the names are of great heroes and some notorius villians. Most names have faded to time, but some are still recent such as Beowulf, Daaku, Zeal, Sunder, Kaarell, and the list goes on. However, rumors will be rumors and it is quite certain that they were all just wearing a pair of similar boots, but when rumors spread myths arise and it is said that these boots had something to do with why they"+
   " were so great. Even though it can not be proved the boots were even magical when they wore them, if they ever wore them."
   );
   set_type("clothing");
   set_limbs(({"right foot","left foot"}));
   set_weight(2);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("strength",4);
   set_item_bonus("endurance",4);
   set_item_bonus("damage resistance",5);
   set_value(25000);
   set_size(-1);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
}

int wear_func(){
   if(ETO->is_monster()){
     return 1;
   }
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"The boots seem not to fit you.");
     return 0;
   }
   write("%^RESET%^%^RED%^You slide your feet into the boots and feel a sense of pride wash over you.%^RESET%^");
   return 1;
}
int remove_func(){
   write("%^RESET%^%^RED%^You feel like you are missing something once you remove the boots.%^RESET%^");
   return 1;
}
