#include <std.h>
inherit "/d/common/obj/weapon/warhammer";

void create(){
   ::create();
   set_name("hooked hammer");
   set_id(({"hook hammer","hammer","hook","hooked hammer","gnomish hammer","gnomish hooked hammer","tool"}));
   set_short("%^RESET%^%^ORANGE%^Gnomish Hoo%^RED%^k%^ORANGE%^ed Hammer%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^a hammer with an oddly hooked handle%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This weapon is unusual, as it looks like a tool of some kind, but is held like a "
"weapon. A stout length of %^RESET%^%^ORANGE%^oak wood %^BOLD%^%^BLACK%^provides the shaft of the weapon, and "
"at either end an %^RESET%^%^WHITE%^iron head %^BOLD%^%^BLACK%^is fixed. One head is a giant %^RESET%^%^WHITE%^"
"blunt surface%^BOLD%^%^BLACK%^, providing the wielder the ability to %^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^m"
"%^RESET%^%^ORANGE%^ash%^BOLD%^%^BLACK%^ their victim. The other ends in a %^RESET%^%^RED%^wicked claw %^BOLD%^"
"%^BLACK%^that could %^RESET%^%^BOLD%^%^RED%^pierce%^BOLD%^%^BLACK%^, or be used to trip an opponent. The "
"weapon is well cared for, as if it was more of a family heirloom than a simple tool.%^RESET%^");
   set_value(800);
   set_property("enchantment",3);
   set_lore("%^WHITE%^%^BOLD%^This rather strange creation is actually a prized weapon among the svirfneblin, "
"with only their most skilled warriors trained in its use. It makes use of the harmful blunt end for damage, "
"while the hooked handle is designed for the small gnomes to trip a larger opponent, giving them a greater "
"advantage in combat. It is rarely seen in use by other races, as it is considered too strange by most to "
"bother using it as a weapon, but noone who has opposed a skilled svirfneblin using such a weapon would deny "
"their clever functionality in combat.%^RESET%^\n");
   set_property("lore difficulty",12);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun() {
   tell_room(EETO,"%^YELLOW%^"+ETOQCN+" grips the shaft of the rather strange looking weapon.%^RESET%^",ETO);
   tell_object(ETO,"%^YELLOW%^You grasp the shaft of the oddly designed weapon.%^RESET%^");
   return 1;
}

int unwield_fun() {
   tell_room(EETO,"%^YELLOW%^"+ETOQCN+" releases "+ETO->QP+" hold on the hooked hammer.%^RESET%^",ETO);
   tell_object(ETO,"%^YELLOW%^You release your hold on the hooked hammer.%^RESET%^");
   return 1;
}

int hit_fun(object targ) {
    if(!objectp(targ)) return 0;
    if(!objectp(ETO)) return 0;
    targ = ETO->query_current_attacker();
    if(!random(6)){
      switch(random(10)) {

      case 0..3:
        tell_room(EETO,"%^BLUE%^%^BOLD%^"+ETOQCN+" brings the blunt end of the hooked hammer forward, sending "
+targ->QCN+" a crushing blow!%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^BLUE%^%^BOLD%^You bring the blunt end of the hooked hammer forward, sending "
+targ->QCN+" a crushing blow!%^RESET%^");
        tell_object(targ,"%^BLUE%^%^BOLD%^"+ETOQCN+" brings the blunt end of the hooked hammer forward, "
"smashing you with a crushing blow!%^RESET%^");
        targ->do_damage(targ->return_target_limb(),random(5)+10);
        break;

      case 4..5:
        tell_room(EETO,"%^BOLD%^%^BLACK%^With a quick reversal of the hammer, "+ETOQCN+" impales "+targ->QCN+
" with a painful stab from its hooked end!%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^BOLD%^%^BLACK%^With a quick reversal of the hammer, you impale "+targ->QCN+" with a "
"painful stab from its hooked end!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^BLACK%^With a quick reversal of the hammer, "+ETOQCN+" impales you with "
"a painful stab from its hooked end!%^RESET%^");
        targ->do_damage(targ->return_target_limb(),roll_dice(2,4)*2);
        break;

      case 6..9:
        tell_room(EETO,"%^ORANGE%^"+ETOQCN+" aims a low swipe at "+targ->QCN+" with the hooked end of the "
"hammer, pulling "+targ->QO+" off "+targ->QP+" feet!%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^ORANGE%^You aim a low swipe at "+targ->QCN+" with the hooked end of the hammer, and "
"manage to pull "+targ->QO+" off "+targ->QP+" feet!%^RESET%^");
        tell_object(targ,"%^ORANGE%^"+ETOQCN+" aims a low swipe at you with the hooked end of the hammer and "
"pulls you off your feet!%^RESET%^");
        targ->set_paralyzed(random(12)+6,"You are still trying to get back on your feet!\n");
        break;
      }
   }
   return 1;
}