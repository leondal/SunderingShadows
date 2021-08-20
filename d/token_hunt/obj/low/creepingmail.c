#include <std.h>
inherit "/d/common/obj/armour/chain";

void create() {
   ::create();
   set_name("scales");
   set_id(({"scales","mass of scales","rippling scales","reflective scales","mail","scale mail","scalemail","armor","armour","scale","hide","living hide"}));
   set_short("%^RESET%^%^BLUE%^Drark%^BOLD%^h%^RESET%^%^BLUE%^eneld's Livi%^BOLD%^n%^RESET%^%^BLUE%^g Hide%^RESET%^");
   set_obvious_short("%^RESET%^%^BLUE%^a rippling mass of re%^BOLD%^f%^RESET%^%^BLUE%^lect%^BOLD%^i%^RESET%^%^BLUE%^ve scales%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^These scales hold quite an intriguing appearance.  They are a deep shade of "
"%^RESET%^%^BLUE%^sapp%^BOLD%^h%^RESET%^%^BLUE%^ire%^WHITE%^%^BOLD%^, with a perfect surface that is more "
"gem-like than anything else.  The scales reflect even the slightest hint of %^YELLOW%^light%^WHITE%^, "
"sparkling in every shade of %^BLUE%^b%^RESET%^%^BLUE%^l%^CYAN%^u%^BOLD%^e%^WHITE%^ imaginable.  They hold a "
"partial shape, almost like a coat, but the outline is vague at best, and never seems to hold the same size "
"for long.  The overlapping %^RESET%^%^BLUE%^sc%^BOLD%^a%^RESET%^%^BLUE%^les%^WHITE%^%^BOLD%^ seem to be "
"constantly rippling and moving, almost like a living creature.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^This intriguing creation was the work of a reknowned mage, Drakheneld Artharus, who "
"spent his lifetime mastering the intricacies of alteration magic.  The suit was rumoured to be one of many, "
"which he created and sold for a small fortune, and particularly effective armor for a warrior.  The scales "
"were said to be able to shift and move even while worn, in order to better protect the underlying skin of the "
"wearer.  When unused, they simply tumbled into a heap of shining scales that could not even be discerned as magical.");
   set_property("lore difficulty",25);
   set_item_bonus("magic resistance",1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
   set_weight(25);
   set_size(-1);
   set_value(0);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_fun() {
   TO->set_obvious_short("%^RESET%^%^BLUE%^a rippling suit of re%^BOLD%^f%^RESET%^%^BLUE%^lect%^BOLD%^i%^RESET%^%^BLUE%^ve scalemail%^RESET%^");
   TO->set_long("%^WHITE%^%^BOLD%^This suit of scalemail holds quite an intriguing appearance.  The scales are "
"a deep shade of %^RESET%^%^BLUE%^sapp%^BOLD%^h%^RESET%^%^BLUE%^ire%^WHITE%^%^BOLD%^, with a perfect surface "
"that is more gem-like than anything else.  The scales reflect even the slightest hint of %^YELLOW%^light"
"%^WHITE%^, sparkling in every shade of %^BLUE%^b%^RESET%^%^BLUE%^l%^CYAN%^u%^BOLD%^e%^WHITE%^ imaginable.  "
"They form a coat and leggings of overlapping scales to protect the wearer, although the%^RESET%^%^BLUE%^ "
"sc%^BOLD%^a%^RESET%^%^BLUE%^les%^WHITE%^%^BOLD%^ seem to be constantly rippling and moving across the "
"wearer's body, almost like a living creature.%^RESET%^\n");
   tell_object(ETO,"%^BLUE%^The scales shift to match the form of your body as you wear them.%^RESET%^");
   tell_room(EETO,"%^BLUE%^The scales shift to match the form of "+ETOQCN+"'s body as "+ETO->QS+" wears "
"them.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   TO->set_obvious_short("%^RESET%^%^BLUE%^a rippling mass of re%^BOLD%^f%^RESET%^%^BLUE%^lect%^BOLD%^i%^RESET%^%^BLUE%^ve scales%^RESET%^");
   TO->set_long("%^WHITE%^%^BOLD%^These scales hold quite an intriguing appearance.  They are a deep shade of "
"%^RESET%^%^BLUE%^sapp%^BOLD%^h%^RESET%^%^BLUE%^ire%^WHITE%^%^BOLD%^, with a perfect surface that is more "
"gem-like than anything else.  The scales reflect even the slightest hint of %^YELLOW%^light%^WHITE%^, "
"sparkling in every shade of %^BLUE%^b%^RESET%^%^BLUE%^l%^CYAN%^u%^BOLD%^e%^WHITE%^ imaginable.  They hold a "
"partial shape, almost like a coat, but the outline is vague at best, and never seems to hold the same size "
"for long.  The overlapping %^RESET%^%^BLUE%^sc%^BOLD%^a%^RESET%^%^BLUE%^les%^WHITE%^%^BOLD%^ seem to be "
"constantly rippling and moving, almost like a living creature.%^RESET%^\n");
   tell_object(ETO,"%^BLUE%^The rippling scalemail suit loses its distinct form as you remove it.%^RESET%^");
   tell_room(EETO,"%^BLUE%^"+ETOQCN+"'s rippling scalemail suit loses its distinct form as "+ETO->QS+" removes "
"it.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(10)){
     tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETOQCN+"'s suit of scalemail %^RESET%^%^BLUE%^ri%^BOLD%^p%^RESET%^%^BL"
"UE%^ples%^BOLD%^%^WHITE%^ and seems to shift, deflecting "+who->QCN+"'s blow harmlessly aside!",({ETO,who}));
     tell_object(ETO,"%^WHITE%^%^BOLD%^The scales of your armor %^RESET%^%^BLUE%^ri%^BOLD%^p%^RESET%^%^BLUE%^"
"ple %^BOLD%^%^WHITE%^and seems to shift, deflecting "+who->QCN+"'s blow harmlessly aside!%^RESET%^");
     tell_object(who,"%^WHITE%^%^BOLD%^The scales of "+ETOQCN+"'s armor %^RESET%^%^BLUE%^ri%^BOLD%^p%^RESET%^"
"%^BLUE%^ple%^BOLD%^%^WHITE%^ and seems to shift, deflecting your blow harmlessly aside!%^RESET%^");
     return 0;
   }
   return damage;
}

int is_metal() { return 0; }
