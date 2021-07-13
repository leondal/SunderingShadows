#include <std.h>
#include "../inherit/ruins.h"
inherit ARMOUR;

void create() {
   ::create();
   set_name("steel-capped boots");
   set_short("%^RESET%^%^WHITE%^Bat%^BLACK%^%^BOLD%^t%^RESET%^%^WHITE%^leg%^BLACK%^%^BOLD%^u%^RESET%^%^WHITE%^ards%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^steel-capped boots%^WHITE%^");
   set_id(({"boots","Boots","battleguards","Battleguards","steel boots","steel-capped boots","steel capped boots"}));
   set_long("%^ORANGE%^These heavy boots seem a little shorter and wider than normal, and would probably reach up the "
"calves to just below the knees.  They are crafted of hardened %^BLACK%^%^BOLD%^black leather%^RESET%^%^ORANGE%^, with "
"sturdy steel buckles up the sides.  The toe of each boot is covered in a hard %^WHITE%^ste%^BOLD%^e%^RESET%^%^WHITE%^l "
"pl%^BOLD%^a%^RESET%^%^WHITE%^te%^ORANGE%^, which would probably do some effective damage with a kick.  The boots are "
"uncharacteristically heavy, due to the bands of metal inside each boot, making them much too ungainly to be considered "
"mere clothing.  They would, however, be extremely effective protection for the feet.%^RESET%^\n");
   set_weight(8);
   set_value(350);
   set_type("clothing");
   set_size(2);
   set_lore("%^WHITE%^%^BOLD%^These were once the property of the reknowned dwarven warrior Gelthek "
"Battlestorm, who smithed the boots himself.  They were made as an odd hybrid of clothing and armor, and "
"could reportedly cause some painful wounds in a fight.%^RESET%^\n");
   set_property("lore difficulty",17);
   set_property("enchantment",3);
   set_limbs(({ "left foot", "right foot" }));
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
}

int wear_fun() {
   if((int)ETO->query_lowest_level() < 15) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You need more training to use these boots!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->QCN+" can't seem to make sense of how to wear the boots!",ETO);
     return 0;
   }
   tell_object(ETO,"%^ORANGE%^You stomp into the heavy boots.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" stomps into the heavy boots.%^RESET%^",ETO);
   return 1;
}

int remove_fun() {
   tell_object(ETO,"%^ORANGE%^You pull the heavy boots off.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" pulls the heavy boots off.%^RESET%^",ETO);
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(5)){
     tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" blocks "+who->QCN+"'s attack, and kicks "+who->QO+
" painfully in the shin with "+ETO->QP+" steel-capped boots!",({ETO,who}));
     tell_object(ETO,"%^BLACK%^%^BOLD%^You block "+who->QCN+"'s attack, and kick "+who->QO+" painfully "
"in the shin with your steel-capped boots.  That must've really hurt!%^RESET%^");
     tell_object(who,"%^BLACK%^%^BOLD%^"+ETOQCN+" blocks your attack, and then kicks you painfully in "
"the shins with "+ETO->QP+" steel-capped boots.  It's all you can do to remain standing!%^RESET%^");
     who->do_damage("right leg",random(5)+5);
     return 0;
   }
   return damage;
}
