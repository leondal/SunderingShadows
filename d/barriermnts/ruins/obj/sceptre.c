#include <std.h>
#include "../inherit/ruins.h"
inherit "/d/common/obj/weapon/morningstar";

create(){
   ::create();
   set_id(({"sceptre","Sceptre","translucent sceptre","spectral sceptre"}));
   set_name("translucent sceptre");
   set_obvious_short("%^RESET%^%^BLUE%^translucent sceptre%^RESET%^");
   set_short("%^CYAN%^%^BOLD%^spe%^BLACK%^c%^CYAN%^tral scep%^BLACK%^t%^CYAN%^re%^RESET%^");
   set_long("%^BLUE%^This sceptre is flawless in appearance, made of what looks like solid "
"%^WHITE%^ad%^BLACK%^%^BOLD%^a%^RESET%^%^WHITE%^man%^BLACK%^%^BOLD%^t%^RESET%^%^WHITE%^ium%^BLUE%^, with "
"a %^ORANGE%^leatherbound%^BLUE%^ grip.  The weapon looks strangely %^CYAN%^%^BOLD%^translucent "
"%^RESET%^%^BLUE%^and insubstantial, though it seems quite solid to touch.  The head of the sceptre is "
"smooth and spherical, and etched with the image of a set of scales, held in the centre by a skeletal "
"hand.  Below the head of the sceptre is a ridge of identical metal, which merges lower into the thick "
"handle wrapped in %^ORANGE%^leather bindings%^BLUE%^.%^RESET%^");
   set_weight(8);
   set_property("enchantment",random(2)+2);
   set_value(1550);
   set_lore("%^WHITE%^%^BOLD%^This holy relic was the possession of the Kelemvorite priestess, Sionne of "
"the Ashes.  It was gifted to her upon her departure from the High Temple of Eternal Order.  The weapon "
"was rumoured to be blessed by the touch of Kelemvor himself, granting it strength to battle undead "
"creatures.%^RESET%^");
   set_property("lore difficulty",15);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun() {
   tell_object(ETO,"%^BLUE%^You take the translucent sceptre in a firm grip.%^RESET%^");
   tell_room(EETO,"%^BLUE%^"+ETO->QCN+" takes a firm grip upon the sceptre's handle.%^RESET%^",ETO);
   return 1;
}

int unwield_fun() {
   tell_object(ETO,"%^BLUE%^You loose your grip on the sceptre's leatherbound handle.%^RESET%^");
   tell_room(EETO,"%^BLUE%^"+ETO->QCN+" releases "+ETO->QP+" grip on the sceptre's "
"handle.%^RESET%^",ETO);
   return 1;
}

int hit_fun(object target){
   if(!random(12)){
      if(target->query_property("undead") || (string)target->query_race() == "undead") {
        switch(random(8)){
          case 0..2:
          tell_object(ETO,"%^CYAN%^%^BOLD%^The sceptre shimmers, passing straight through the undead "
"creature!%^RESET%^");
          tell_object(target,"%^CYAN%^%^BOLD%^The sceptre in "+ETO->QCN+"'s hand shimmers, passing "
"straight through you!%^RESET%^");
          tell_room(EETO,"%^CYAN%^%^BOLD%^"+ETO->QCN+"'s sceptre shimmers and passes straight through "
"the undead creature!%^RESET%^",({ETO,target}));
          TO->set_property("magic",1);
          target->do_damage(target->return_target_limb(),roll_dice(2,4) *2);
          TO->remove_property("magic");
          break;

          case 3..4:
          tell_object(ETO,"%^ORANGE%^The sceptre seems to solidify as it connects soundly with the "
"undead creature, knocking it back!%^RESET%^");
          tell_object(target,"%^ORANGE%^"+ETO->QCN+"'s sceptre seems to solidify as it connects soundly "
"with you, knocking you back!%^RESET%^");
          tell_room(EETO,"%^ORANGE%^"+ETO->QCN+"'s sceptre seems to solidify as it connects soundly with "
"the undead creature, knocking it back!%^RESET%^",({ETO,target}));
          target->set_paralyzed(15,"You are trying to get your balance back!");
          return 1;
          break;

          case 5..6:
          tell_object(ETO,"%^YELLOW%^A glow emanates from the sceptre in your hand as it hits the undead "
"creature, who seems to weaken!%^RESET%^");
          tell_object(target,"%^YELLOW%^A glow emanates from the sceptre in "+ETO->QCN+"'s hand as it "
"hits you, making you feel very weak!%^RESET%^");
          tell_room(EETO,"%^YELLOW%^A glow emanates from the sceptre in "+ETO->QCN+"'s hand as it hits "
"the undead creature, who seems to weaken!%^RESET%^",({ETO,target}));
          target->add_stat_bonus("strength",-1);
          return 1;
          break;

          case 7:
          tell_object(ETO,"%^BLUE%^%^BOLD%^The sceptre takes on a glowing aura as it slams into the "
"undead creature!%^RESET%^");
          tell_object(target,"%^BLUE%^%^BOLD%^"+ETO->QCN+"'s sceptre takes on a glowing aura as it slams "
"into you!%^RESET%^");
          tell_room(EETO,"%^BLUE%^%^BOLD%^The sceptre in "+ETO->QCN+"'s hand takes on a glowing aura as "
"it slams into the undead creature!%^RESET%^",({ETO,target}));
          target->do_damage(target->return_target_limb(),roll_dice(2,4) *4);
          break;
        }
      }
      else {
        tell_object(ETO,"%^WHITE%^%^BOLD%^You slam the sceptre heavily into your target!%^RESET%^");
        tell_object(target,"%^WHITE%^%^BOLD%^"+ETO->QCN+" slams the sceptre heavily into you!%^RESET%^");
        tell_room(EETO,"%^WHITE%^%^BOLD%^"+ETO->QCN+" slams the sceptre heavily into "
+target->QCN+"!%^RESET%^",({ETO,target}));
        target->do_damage(target->return_target_limb(),roll_dice(2,4) *2);
      }
      return 1;
    }
}