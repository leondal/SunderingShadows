// it was totally broke, yanked 2 properties and now it's working again. Since they were kinda overkill anyway, leaving them off. Think the shieldMiss shouldn't be set as item_bonus. N, 4/15
#include <std.h>
inherit "/d/common/obj/armour/shield";

void create() {
   ::create();
   set_name("Therdall's shield");
   set_id(({ "shield","medium shield","shield of the king","shield of therdall skycast","therdall's shield"}));
   set_short("%^BOLD%^%^WHITE%^The shield of %^BOLD%^%^BLUE%^Th%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^rd%^RESET%^al%^BOLD%^%^BLUE%^l %^BOLD%^%^CYAN%^S%^RESET%^k%^BOLD%^%^WHITE%^y%^RESET%^%^CYAN%^c%^BOLD%^%^BLUE%^a%^RESET%^%^BLUE%^s%^RESET%^t%^RESET%^");
   set_obvious_short("A medium shield");
   set_long("%^BOLD%^%^CYAN%^This shield seems to radiate an aura of power"+
      " that is almost tangible. The adamantium shield has a design etched"+
      " into its surface. A regal lion, in roaring positon, covers the face"+
      " of the shield. Other than the leather strap that would secure your arm"+
      " to the shield there is nothing else special about this oval shield.");
   set_value(2295);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
//   set_item_bonus("magic resistance",2);
   set_item_bonus("spell damage resistance",25);
   set_item_bonus("constitution",2);
//   set_item_bonus("shieldMiss",35);
   set_wear((:TO,"wear_it":));
   set_remove((:TO,"remove_it":));
   set_struck((:TO,"struck":));
}

int wear_it(){
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"You can't seem to settle the shield properly on your arm.");
     return 0;
   }
   write("%^BOLD%^%^WHITE%^You feel the power of the shield flowing into your body.%^RESET%^");
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" seems much more confident with the shield.%^RESET%^",ETO);
   return 1;
}

int remove_it(){
   write("%^BOLD%^%^CYAN%^You feel the raw energy of the shield seeping from your skin.%^RESET%^");
   return 1;
}

int struck(int damage, object what, object who){
      tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^The lion on "+ETO->query_cap_name()+"'s shield suddenly releases a roar that appears to repel blows!%^RESET%^",({who,ETO}));
   tell_object(who,"%^BOLD%^%^CYAN%^As you try to hit "+ETO->query_cap_name()+", the shield roars at you, repelling your blow!%^RESET%^");
   tell_object(ETO,"%^BOLD%^%^CYAN%^The shield roars and pushes the oncoming blow backward!%^RESET%^");
   return (-1)*(damage);
}
