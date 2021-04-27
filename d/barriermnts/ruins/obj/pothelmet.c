#include <std.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

void create() {
   ::create();
   set_name("pot helmet");
   set_short("%^BLACK%^%^BOLD%^Iron-pot helmet%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^dented iron cooking-pot%^RESET%^");
   set_id(({"pot","Pot","cooking pot","cooking-pot","dented pot","iron pot","helmet","pot helmet"}));
   set_long("%^RED%^It's hard to decide just what this object should be used for.  On one hand, it seems "
"an almost perfect shape to fit a small head, and would probably protect that head very well from "
"damage.  On the other hand, it looks just about right for a cooking pot.  It is made entirely of sturdy "
"%^BLACK%^%^BOLD%^black iron%^RESET%^%^RED%^, scratched and dented in countless places.  The thick "
"handle attached to it could be used both to carry it, or to secure it on under someone's "
"chin.%^RESET%^\n");
   set_weight(7);
   set_value(70);
   set_type("armor");
   set_ac(1);
   set_size(2);
   set_lore("%^WHITE%^%^BOLD%^This was one of the few items the Tempusian warrior Gelthek Battlestorm "
"bothered to take upon his travels.  It served a double role for the dwarf as both cooking pot and "
"helmet, as he was not fond of carrying more than he needed to.  While Gelthek was also not particularly "
"fond of magic, his friend Lachlan, a mage of some repute, managed to convince the dwarf to allow him to "
"enchant the pot with a spell to keep it from breaking.%^RESET%^\n");
   set_property("lore difficulty",19);
   set_property("enchantment",2);
   set_item_bonus("fortitude",1);
   set_item_bonus("reflex",1);
   set_item_bonus("will",1);
   set_limbs(({"head"}));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   if((int)ETO->query_lowest_level() < 15) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You need more training to use this item!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" can't seem to figure out how to use the helmet.",ETO);
     return 0;
   }
   tell_object(ETO,"%^BLACK%^%^BOLD%^The pot slips down over your eyes as you put it upon your "
"head.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^The pot slips down over "+ETOQCN+"'s eyes as "+ETO->QS+" puts it "
"upon "+ETO->QP+" head.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You tug the heavy iron pot off your head.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" tugs the heavy iron pot off "+ETO->QP+
" head.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(8)){
     tell_room(EETO,"%^BLACK%^%^BOLD%^"+who->QCN+"'s attack hits "+ETOQCN+"'s iron helmet with a "
"resounding clang!  "+ETOQCN+" looks a little dazed, but otherwise unharmed.%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^BLACK%^%^BOLD%^"+who->QCN+"'s attack hits you squarely upon your iron helmet "
"with a resounding clang!  The helm seems to have taken most of the damage, but your head is humming "
"from the impact.%^RESET%^");
     tell_object(who,"%^BLACK%^%^BOLD%^Your attack hits "+ETOQCN+"'s iron helmet with a resounding "
"clang!  "+capitalize(ETO->QS)+" looks a little dazed, but otherwise unharmed.%^RESET%^");
     ETO->set_paralyzed(5,"Your head is still humming from the impact!");
     return 0;
   }
   return damage;
}
