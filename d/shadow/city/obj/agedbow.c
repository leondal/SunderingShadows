#include <std.h>
inherit "/d/common/obj/lrweapon/longbow";

void create(){
   ::create();
   set_name("long bow");
   set_id(({"bow","long bow","aged long bow"}));
   set_obvious_short("%^ORANGE%^An a%^BOLD%^%^BLACK%^g%^RESET%^%^GREEN%^e%^ORANGE%^d "+
   "lo%^BOLD%^%^BLACK%^n%^RESET%^%^GREEN%^g %^BOLD%^%^BLACK%^b%^RESET%^%^ORANGE%^ow%^WHITE%^");
   set_short("%^RESET%^%^GREEN%^Elven%^RESET%^ long bow");
   set_long("%^BOLD%^%^BLACK%^Although it's a bit worse for wear now, this shortbow was once a very fine bow indeed. "+
   "The shaft is made from dark wood and is carved with %^GREEN%^l%^RESET%^%^GREEN%^e%^BOLD%^av%^RESET%^%^GREEN%^e%^BOLD%^s "+ 
   "%^BLACK%^and %^GREEN%^v%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^s%^BLACK%^. It seems quite sturdy, "+ 
   "despite the bow's aged appearance. The %^RESET%^taut string %^BOLD%^%^BLACK%^is in perfect condition, contrasting "+ 
   "with the rest of the bow's older features. Although all things fall to the ravages of time, it is obviously this "+ 
   "bow was once well-loved and cared for.%^RESET%^");
   set_value(900);
   set_property("enchantment",1);
   set_item_bonus("perception",1);
   set_lore("%^RESET%^%^ORANGE%^The trademark design of this bow seems to mark it as being crafted by Androth Nehrhen, a half-elven "+ 
   "woodworker of some renown. In his time, some dozens of years past now, he made many highly "+ 
   "coveted and beloved bows. To own one now is truly special.");
   set_property("lore difficulty",12);
   set_wield("%^RESET%^%^GREEN%^You feel more focused as you wield the bow.");
   set_unwield("%^RESET%^%^GREEN%^You lower your fine bow, for now.");
   set_lrhit((:TO,"lrhitit":));
}

int lrhitit(object targ) {
    targ = ETO->query_current_attacker();
    if(random(1000) < 200){
    if(!objectp(targ)) return roll_dice(1,6);
	tell_object(ETO,"%^RESET%^%^GREEN%^Your instincts take over and you quickly take another shot at "+targ->QCN+"!");
    tell_object(targ,"%^RESET%^%^GREEN%^"+ETO->QCN+" easily tracks your movements and takes another shot!%^RESET%^");
    tell_room(EETO,"%^RESET%^%^GREEN%^"+ETO->QCN+" quickly releases a shot at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
    return roll_dice(1,10)+2;
   }
}











