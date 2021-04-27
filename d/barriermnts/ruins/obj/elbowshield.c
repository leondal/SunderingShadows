#include <std.h>
#include "../inherit/ruins.h"
inherit "/d/common/obj/armour/buckler";

void create() {
   ::create();
   set_name("elbow shield");
   set_short("%^RESET%^%^ORANGE%^rogue's barrier%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^small circular shield%^RESET%^");
   set_id(({"shield","elbow shield","Shield","rogue shield","leather shield","barrier","rogue's 
barrier"}));
   set_long("%^CYAN%^This shield could barely even be classified as that - it is even smaller than a "
"buckler, and perfectly circular.  %^ORANGE%^Treated leather%^CYAN%^ forms the base of the shield, set "
"with a single %^WHITE%^mi%^BLACK%^%^BOLD%^t%^RESET%^%^WHITE%^hr%^BLACK%^%^BOLD%^i%^RESET%^%^WHITE%^l "
"pl%^BLACK%^%^BOLD%^a%^RESET%^%^WHITE%^te%^CYAN%^ covering the outer edge.  Two sturdy %^ORANGE%^leather "
"straps%^CYAN%^ would hold it upon the wearer's arm, though they are fitted so that the shield would be "
"more comfortable to wear over the elbow, rather than further down the arm.  How they would manage to "
"defend the wearer in such a position is anyone's guess.%^RESET%^\n");
   set_value(430);
   set_lore("%^WHITE%^%^BOLD%^This unique shield was devised for combat by the rogue known only in lore "
"as Eylean.  Many accounts of his battles claim he could use the tiny shield to defend himself, as "
"effectively as a warrior would use a full body shield.  Only the most practiced of rogues could ever "
"manage to duplicate his skill with such an item, leaving others only to wonder at how something so small "
"could ever be effective.%^RESET%^\n");
   set_property("lore difficulty",15);
   set_property("enchantment",2);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   tell_object(ETO,"%^ORANGE%^You strap the shield securely over your right elbow.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" straps the shield securely over "+ETO->QP+" right "
"elbow.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^ORANGE%^You unstrap the small shield from your arm.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" unstraps the small shield from "+ETO->QP+" arm.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage, object what, object target) {
   if (!random(2)) {
     tell_object(ETO,"%^ORANGE%^You swing your elbow up, and deflect "+target->QCN+"'s attack with your "
"shield!%^RESET%^");
     tell_object(target,"%^ORANGE%^"+ETO->QCN+" swings "+ETO->QP+" elbow up, and deflects your attack "
"with "+ETO->QP+" shield!%^RESET%^");
     tell_room(EETO,"%^ORANGE%^"+ETO->QCN+" swings "+ETO->QP+" elbow up, and deflects "+target->QCN+"'s attack with "+ETO->QP+" shield!%^RESET%^",({ETO,target}));
     return 0;
   }
   return damage;
}
