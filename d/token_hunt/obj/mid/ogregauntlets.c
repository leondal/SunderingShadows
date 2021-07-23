#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
   ::create();
   set_name("gauntlets");
   set_id(({"gauntlets","reticulated gauntlets","bone gauntlets","reticulated bone gauntlets","talons","gorthoks talons","gorthok's talons"}));
   set_short("%^BLACK%^%^BOLD%^Go%^RESET%^r%^BOLD%^%^BLACK%^thok's Tal%^RED%^o%^BLACK%^ns%^RESET%^");
   set_obvious_short("%^RESET%^sp%^BOLD%^i%^RESET%^ked bo%^BOLD%^n%^RESET%^e %^ORANGE%^gauntlets%^RESET%^");
   set_long("%^RESET%^This fierce-looking piece of armor seems almost as if it would be better used as a "
"weapon.  Forged from two base plates of %^ORANGE%^darkly-bur%^RED%^n%^ORANGE%^ished metal%^RESET%^, to allow "
"a resting point for the hands, each is bridged by a reticulated arch of %^BOLD%^bone spikes%^RESET%^.  They "
"would run easily half the length of the forearm, branching from a central line much like the spine of a "
"creature, and with each bone sharpened to a %^RED%^p%^BOLD%^ie%^RESET%^%^RED%^rc%^BOLD%^in%^RESET%^%^RED%^g "
"%^RESET%^tip.  At the very top, flanking the fingers of the wearer to either side, are twin curved blades of "
"%^BOLD%^%^BLACK%^poli%^RESET%^sh%^BOLD%^%^BLACK%^ed steel%^RESET%^, each of which sweeps forward towards the "
"other as if it were meant to be a weapon.  The overall piece has a dangerous look to it; it would be likely "
"wise only for an experienced warrior to use.\n%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^These rugged gauntlets were crafted as a mark of status for the Orog chieftain "
"known only as Gorthok.  Feared several decades previous throughout the Daggerdale mountains, he brought down "
"many raids upon the northern cities of the that region, until he was finally brought down by the combined "
"forces of the Tormish kingdom. From there the gauntlets pass out of history's record; it was assumed they "
"were taken as a prize of war.%^RESET%^\n");
   set_property("lore difficulty",18);
   set_size(-1);
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
   set_value(0);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_struck((:TO,"struck_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_fun() {
   if((int)ETO->query_level() < 20) {
     tell_object(ETO,"You aren't experienced enough to use these.");
     return 0;
   }
   tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" slips a spiked brace over each forearm, and flexes one hand in "
"anticipation.%^RESET%^",ETO);
   tell_object(ETO,"%^CYAN%^%^RED%^You slip each spiked brace over your forearms, and flex a hand in "
"anticipation of the battle to come.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_object(ETO,"%^BOLD%^%^RED%^You already regret removing the impressive gauntlets.%^RESET%^");
   return 1;
}

int struck_fun(int damage,object what,object who){
   if(!random(4)){
     tell_room(EETO,"%^BOLD%^%^RED%^Seeing a weakness in "+who->QCN+"'s defenses, "+ETO->QCN+" lashes out at "
+who->QO+" with one of "+ETO->QP+" spiked gauntlets!%^RESET%^",({ETO,who}));
     tell_object(ETO,"%^BOLD%^%^RED%^Seeing a weakness in your opponent's defenses, you lash out with the fiercely spiked gauntlet!%^RESET%^");
     tell_object(who,"%^BOLD%^%^RED%^"+ETO->QCN+" seems to sense a weakness in your defenses, and lashes out "
"at you with one of "+ETO->QP+" spiked gauntlets!%^RESET%^");
     ETO->execute_attack();
     return 0;
   }
   return damage;
}
