#include <std.h>
#include <magic.h>
inherit "/d/magic/obj/lockweapons/eldritch_bow";

void create() {
   ::create();
}

void special_tier1(object wielder,object victim) {
    if((int)wielder->query_hp() < (int)wielder->query_max_hp()) {
      tell_object(wielder,"%^RESET%^%^MAGENTA%^You rake your bolt across "+victim->QCN+", leeching a t%^GREEN%^as%^MAGENTA%^t%^GREEN%^e %^MAGENTA%^of "+victim->QP+" energy!%^RESET%^");
      tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+" rakes "+wielder->QP+" bolt across you, and you feel slightly w%^GREEN%^ea%^MAGENTA%^ke%^GREEN%^ne%^MAGENTA%^d!%^RESET%^");
      tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^"+wielder->QCN+" rakes "+wielder->QP+" bolt across "+victim->QCN+", and "+victim->QS+" looks slightly w%^GREEN%^ea%^MAGENTA%^ke%^GREEN%^ne%^MAGENTA%^d!%^RESET%^",({wielder,victim}));
      TO->set_property("magic",1);
      wielder->do_damage("torso",(roll_dice(tier,4)+10)*(-1));
      TO->set_property("magic",-1);
    }
    else special_tier2(wielder,victim); // may as well still do something useful if they're not injured!
}

void special_tier3(object wielder,object victim) {
    int tmp;
    if((int)wielder->query_hp() < (int)wielder->query_max_hp() || wielder->query_condition() < wielder->query_max_stamina()) {
      tell_object(wielder,"%^RESET%^%^MAGENTA%^You lunge forward and sink your bolt into "+victim->QCN+"! A rush of %^GREEN%^vi%^BOLD%^%^GREEN%^ta%^RESET%^%^GREEN%^li%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^y %^MAGENTA%^fills you, as you drink from "+victim->QP+" very life-force!%^RESET%^");
      tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+" lunges forward and sinks "+wielder->QP+" bolt into you! You feel suddenly drained, as "+wielder->QCN+" looks %^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^vi%^BOLD%^%^GREEN%^ta%^RESET%^%^GREEN%^li%^BOLD%^%^GREEN%^se%^RESET%^%^GREEN%^d%^RESET%^%^MAGENTA%^!%^RESET%^");
      tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^"+wielder->QCN+" lunges forward and sinks "+wielder->QP+" bolt into "+victim->QCN+"! "+wielder->QCN+" looks suddenly %^GREEN%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^vi%^BOLD%^%^GREEN%^ta%^RESET%^%^GREEN%^li%^BOLD%^%^GREEN%^se%^RESET%^%^GREEN%^d%^RESET%^%^MAGENTA%^!%^RESET%^",({wielder,victim}));
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
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your eldritch bolt %^GREEN%^f%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^as%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^es %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s bolt %^GREEN%^f%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^as%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^es %^MAGENTA%^brightly as it slices into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The bolt %^GREEN%^f%^BOLD%^%^GREEN%^l%^RESET%^%^GREEN%^as%^BOLD%^%^GREEN%^h%^RESET%^%^GREEN%^es %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^GREEN%^S%^BOLD%^%^GREEN%^ee%^RESET%^%^GREEN%^th%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng e%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^y%^MAGENTA%^ jolts through the eldritch bolt as it rends flesh and bone!%^RESET%^");
    tell_object(victim,"%^RESET%^%^GREEN%^S%^BOLD%^%^GREEN%^ee%^RESET%^%^GREEN%^th%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng e%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^y%^MAGENTA%^ jolts through "+wielder->QCN+"'s bolt as it rends flesh and bone!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^GREEN%^S%^BOLD%^%^GREEN%^ee%^RESET%^%^GREEN%^th%^BOLD%^%^GREEN%^i%^RESET%^%^GREEN%^ng e%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^er%^BOLD%^%^GREEN%^g%^RESET%^%^GREEN%^y%^MAGENTA%^ jolts through "+wielder->QCN+"'s bolt as it rends "+victim->QCN+"'s flesh and bones!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,10)+2);
    TO->remove_property("magic");
}
