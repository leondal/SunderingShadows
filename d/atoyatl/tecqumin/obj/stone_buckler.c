#include <std.h>
inherit "/d/common/obj/armour/shield";

void create() {
   ::create();
   set_name("shaped stone shield");
   set_id(({ "shield","buckler","sone shield","stone buckler", "shaped buckler","shaped stone buckler"}));
   set_short("%^CYAN%^Tecqumin %^RESET%^stone %^ORANGE%^buckler%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^A %^RESET%^stone %^ORANGE%^buckler");
   set_long("This small round shield is shaped from stone. It looks like"
     +" it should be very heavy to lift, but the enchantments cast upon it make it"
     +" light enough to wield as a buckler. Staps of leather enable it to be held in one"
     +" hand while a weapon is wielded in the other.");
   set_value(2950);
   while((int)TO->query_property("enchantment") != 6) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",6);
   }
   set_item_bonus("shieldMiss",15);
   set_wear((:TO,"wear_it":));
   set_lore("The stone shields of the %^CYAN%^Tecqumin%^RESET%^ were carefully shaped."
    +" Mostly they were thin enough to be liftable, which significantly reduced their"
    +" protective capacity. However, a rare few were given powerful%^MAGENTA%^"
    +" enchantments %^RESET%^that allowed them to be made thick without becoming so"
    +" heavy. These shields offered unbelievable protection. Unfortunately, this is not one of those.");
}

int wear_it(){
   if((int)ETO->query_level() < 41){
     tell_object(ETO,"You can't seem to get the right grip to use the buckler. Perhaps when you have learned some more.");
     return 0;
   }
   write("You grip the strap of the buckler in your fist, ready to ward off blows from"
     +" your opponents' weapons");
   tell_room(environment(ETO),""+ETO->query_cap_name()+" grips the strap of the buckler in "
     + ETO->QP + " fist, ready to ward off blows from " + ETO->QP + " opponents' weapons."
     ,ETO);
   return 1;
}

