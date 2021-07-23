#include <std.h>
inherit "/d/common/obj/weapon/shortsword.c";

void create() {
   ::create();
   set_name("wakizashi");
   set_id(({"wakizashi","fang","black fang","steel wakizashi","tsukikage's fang","tsukikage's black fang","slender wakizashi","orisword2"}));
   set_short("%^BLACK%^%^BOLD%^Tsukikage's Black Fang%^RESET%^");
   set_obvious_short("%^BLACK%^%^BOLD%^slender steel wakizashi%^RESET%^");
   set_long("%^ORANGE%^This stunning weapon is about the size of a shortsword, at two feet in length.  The "
"sharp-tipped blade is single-sided, and slightly curved to be more effective in combat.  It is razor-sharp, "
"crafted from %^WHITE%^folded steel%^ORANGE%^ and is %^WHITE%^%^BOLD%^brilliantly polished%^RESET%^%^ORANGE%^. "
" The hilt and blade meet at a small hand-guard, known as a tsuba, which are used in some specialized combat "
"styles to catch and deflect an enemy weapon.  Identical steel to the blade forms the short hilt of the "
"weapon, which is wrapped in %^BLACK%^%^BOLD%^braided black leather %^RESET%^%^ORANGE%^to form a comfortable "
"grip for the wielder.  The weapon itself is quite light compared to similar blades, probably because of its "
"slender form.%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^This weapon was crafted and used by an ogre-mage warrior named Raiken.  While he "
"is not remembered for his skill as a warrior, he is reknowned for his skills in smithing weapons unlike any "
"other.  His greatest achievement in his craft was a pair of blades, one larger than the other, used in the "
"distinctive fighting style of his clan.  They were named as the Talon and the Fang, after the great black "
"dragon known as Tsukikage, who was revered by their clan for centuries.  Raiken himself gained the blessings "
"of their clan shaman upon the blades, and it was said that while useless alone, with both blades carried in "
"the right hands, they carried the fury of the great black dragon within them.%^RESET%^");
   set_property("lore difficulty",25);
   set_weight(3);
   set_value(0);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
   set_item_bonus("fortitude",1);
   set_item_bonus("armor bonus",1);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wield_fun(){
    tell_object(ETO,"%^BLACK%^%^BOLD%^You take up the wakizashi in a reverse grip, ready for battle.%^RESET%^");
    tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" takes up the wakizashi in a reversed grip.%^RESET%^",ETO);
    return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^BLACK%^%^BOLD%^You release your reversed hold on the wakizashi.%^RESET%^");
   tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" releases "+ETO->QP+" reversed hold on the wakizashi.%^RESET%^",ETO);
   return 1;
}


int hit_fun(object target) {
   object ob;
   if(!random(5)) {
     if((ob = present("orisword1",ETO)) && living(ETO) && ob->query_wielded()) {
       switch(random(10)) {
         case 0..1:
         ETO->execute_attack();
         tell_room(EETO,"%^RED%^%^BOLD%^"+ETOQCN+" follows the arc of the katana with a vicious backhand "
"slash of "+ETO->QP+" wakizashi!%^RESET%^",ETO);
         tell_object(ETO,"%^RED%^%^BOLD%^You follow the arc of your katana with a vicious backhand slash of "
"the wakizashi!%^RESET%^");
         return 1;
         break;

         case 2..3:
         if (sizeof(target->query_wielded()) && !target->query_paralyzed()) {
           tell_room(EETO,"%^CYAN%^%^BOLD%^"+ETOQCN+" catches "+target->QCN+"'s weapon upon the hand-guard of "
+ETO->QP+" katana, and knocks "+target->QS+" back off-balance!%^RESET%^",({ETO,target}));
           tell_object(ETO,"%^CYAN%^%^BOLD%^You catch "+target->QCN+"'s weapon upon the hand-guard of your "
"katana, and knock "+target->QS+" back off-balance!%^RESET%^");
           tell_object(target,"%^CYAN%^%^BOLD%^"+ETOQCN+" catches your weapon upon the hand-guard of "
+ETO->QP+" katana, and knocks you back off-balance!%^RESET%^");
         }
         else {
           tell_room(EETO,"%^CYAN%^%^BOLD%^"+ETOQCN+" brings up the hilt of the wakizashi and slams it hard "
"against "+target->QCN+"'s head, dazing "+target->QO+"!%^RESET%^",({ETO,target}));
           tell_object(ETO,"%^CYAN%^%^BOLD%^You bring up the hilt of the wakizashi and slam it hard against "
+target->QCN+"'s head, dazing "+target->QO+"!%^RESET%^");
           tell_object(target,"%^CYAN%^%^BOLD%^"+ETOQCN+" brings up the hilt of the wakizashi and slams it "
"hard against your head, knocking you into a daze!%^RESET%^");
         }
         target->set_paralyzed(random(15)+5,"%^CYAN%^%^BOLD%^You are still trying to regain your balance!"
"%^RESET%^\n");
         break;

         case 4..6:
         tell_room(EETO,"%^BLACK%^%^BOLD%^"+ETOQCN+" brings up the wickedly-sharp tip of the wakizashi from "
"the side in a stab at "+target->QCN+"!%^RESET%^",({ETO,target}));
         tell_object(ETO,"%^BLACK%^%^BOLD%^You bring up the wickedly-sharp tip of the wakizashi from the side "
"in a stab at "+target->QCN+"!%^RESET%^");
         tell_object(target,"%^WHITE%^%^BOLD%^"+ETOQCN+" brings up the wickedly-sharp tip of the wakizashi "
"from the side in a stab at you!%^RESET%^");
         return 3;
         break;

         case 7..9:
         tell_room(EETO,"%^WHITE%^%^BOLD%^The curved blade of "+ETOQCN+"'s katana bites deeply into "
+target->QCN+"'s flesh!%^RESET%^",({ETO,target}));
         tell_object(ETO,"%^WHITE%^%^BOLD%^The curved blade of your katana bites deeply into "+target->QCN+
"'s flesh!%^RESET%^");
         tell_object(target,"%^WHITE%^%^BOLD%^The curved blade of "+ETOQCN+"'s katana bites deeply into your "
"flesh!%^RESET%^");
         return 2;
         break;
       }
     }
   }
}