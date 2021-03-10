#include <std.h>
#include <magic.h>
inherit "/d/magic/obj/lockweapons/eldritch_claw";

void create() {
   ::create();
   set_id(({"eldritch claw","claw","energy claw","claw of energy","claw of seething energy","eldritch_weapon_xxx"}));
   set_short("%^RESET%^%^CYAN%^cl%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^w of %^GREEN%^s%^BOLD%^%^GREEN%^ee%^RESET%^%^GREEN%^th%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng e%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^y%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This magical construct looks as though it would serve as a weapon of considerable %^RESET%^%^RED%^potency%^BOLD%^%^WHITE%^. "
"Instead of wood or metal, however, it is made purely of %^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^ee%^RESET%^%^GREEN%^th%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng "
"e%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^y"
"%^BOLD%^%^WHITE%^. Shaped like a claw, it bears three six-inch tines that each taper to a %^YELLOW%^razor-sharp %^BOLD%^%^WHITE%^point. They spring from a "
"flattened brace that rests around and across the hand, secured in place by seemingly nothing more than sheer manifestation of %^RESET%^%^CYAN%^will"
"%^BOLD%^%^WHITE%^.%^RESET%^\n");
}

void special_tier1(object wielder,object victim) {
    if((int)wielder->query_hp() < (int)wielder->query_max_hp()) {
      tell_object(wielder,"%^RESET%^%^MAGENTA%^You rake your claw across "+victim->QCN+", leeching a t%^GREEN%^as%^MAGENTA%^t%^GREEN%^e %^MAGENTA%^of "+victim->QP+" energy!%^RESET%^");
      tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+" rakes "+wielder->QP+" claw across you, and you feel slightly w%^GREEN%^ea%^MAGENTA%^ke%^GREEN%^ne%^MAGENTA%^d!%^RESET%^");
      tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^"+wielder->QCN+" rakes "+wielder->QP+" claw across "+victim->QCN+", and "+victim->QS+" looks slightly w%^GREEN%^ea%^MAGENTA%^ke%^GREEN%^ne%^MAGENTA%^d!%^RESET%^",({wielder,victim}));
      TO->set_property("magic",1);
      wielder->do_damage("torso",(roll_dice(tier,4)+10)*(-1));
      TO->set_property("magic",-1);
    }
    else special_tier2(wielder,victim); // may as well still do something useful if they're not injured!
}

void special_tier3(object wielder,object victim) {
    int tmp;
    if((int)wielder->query_hp() < (int)wielder->query_max_hp() || wielder->query_condition() < wielder->query_max_stamina()) {
      tell_object(wielder,"%^RESET%^%^MAGENTA%^You lunge forward and sink your claw into "+victim->QCN+"! A rush of %^GREEN%^vi%^BOLD%^%^GREEN%^ta%^RESET%^%^GREEN%^li%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^y %^MAGENTA%^fills you, as you drink from "+victim->QP+" very life-force!%^RESET%^");
      tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+" lunges forward and sinks "+wielder->QP+" claw into you! You feel suddenly drained, as "+wielder->QCN+" looks %^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^vi%^BOLD%^%^GREEN%^ta%^RESET%^%^GREEN%^li%^BOLD%^%^GREEN%^se%^RESET%^%^GREEN%^d%^RESET%^%^MAGENTA%^!%^RESET%^");
      tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^"+wielder->QCN+" lunges forward and sinks "+wielder->QP+" claw into "+victim->QCN+"! "+wielder->QCN+" looks suddenly %^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^vi%^BOLD%^%^GREEN%^ta%^RESET%^%^GREEN%^li%^BOLD%^%^GREEN%^se%^RESET%^%^GREEN%^d%^RESET%^%^MAGENTA%^!%^RESET%^",({wielder,victim}));
      TO->set_property("magic",1);
      wielder->do_damage("torso",(roll_dice(tier,6)+20)*(-1));
      TO->set_property("magic",-1);
      if(wielder->query_condition() < wielder->query_max_stamina()) {
        tmp = 2 * ((int)wielder->query_max_stamina() - (int)wielder->query_condition());
        if(tmp > 15) tmp = 15;
        wielder->use_stamina(-1*tmp);
      }
      victim->use_stamina(tmp);
    }
    else special_tier4(wielder,victim); // may as well still do something useful if they're not injured!
}

void special_tier2(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your eldritch claw %^GREEN%^f%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^as%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^es %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s claw %^GREEN%^f%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^as%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^es %^MAGENTA%^brightly as it slices into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The claw %^GREEN%^f%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^as%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^es %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^GREEN%^S%^BOLD%^%^GREEN%^ee%^RESET%^%^GREEN%^th%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng e%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^y%^MAGENTA%^ jolts through the eldritch claw as it rends flesh and bone!%^RESET%^");
    tell_object(victim,"%^RESET%^%^GREEN%^S%^BOLD%^%^GREEN%^ee%^RESET%^%^GREEN%^th%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng e%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^y%^MAGENTA%^ jolts through "+wielder->QCN+"'s claw as it rends flesh and bone!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^GREEN%^S%^BOLD%^%^GREEN%^ee%^RESET%^%^GREEN%^th%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng e%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^y%^MAGENTA%^ jolts through "+wielder->QCN+"'s claw as it rends "+victim->QCN+"'s flesh and bones!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,10)+2);
    TO->remove_property("magic");
}