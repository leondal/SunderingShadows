#include <std.h>
#include <magic.h>
inherit "/d/magic/obj/lockweapons/eldritch_claw";

void create() {
   ::create();
   set_id(({"eldritch claw","claw","energy claw","claw of energy","claw of tenebrous energy","eldritch_weapon_xxx"}));
   set_short("%^RESET%^%^CYAN%^cl%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^w of %^BOLD%^%^BLACK%^te%^RESET%^n%^BOLD%^%^BLACK%^ebr%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^us e%^RESET%^ne%^BOLD%^%^BLACK%^rgy%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This magical construct looks as though it would serve as a weapon of considerable %^RESET%^%^RED%^potency%^BOLD%^%^WHITE%^. "
"Instead of wood or metal, however, it is made purely of %^BOLD%^%^BLACK%^te%^RESET%^n%^BOLD%^%^BLACK%^ebr%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^us e%^RESET%^ne%^BOLD%^%^BLACK%^rgy"
"%^BOLD%^%^WHITE%^. Shaped like a claw, it bears three six-inch tines that each taper to a %^YELLOW%^razor-sharp %^BOLD%^%^WHITE%^point. They spring from a "
"flattened brace that rests around and across the hand, secured in place by seemingly nothing more than sheer manifestation of %^RESET%^%^CYAN%^will"
"%^BOLD%^%^WHITE%^.%^RESET%^\n");
}

void special_tier1(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^A precisely directed hint of %^RESET%^pow%^BOLD%^%^BLACK%^e%^RESET%^r %^MAGENTA%^leaves the claw as you plunge it into "+victim->QCN+", and "+victim->QS+" blinks sightlessly!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+" plunges "+wielder->QP+" claw, and a %^RESET%^ha%^BOLD%^%^BLACK%^z%^RESET%^e %^MAGENTA%^of darkness briefly blurs your vision!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^"+wielder->QCN+" plunges "+wielder->QP+" claw it into "+victim->QCN+", and "+victim->QS+" blinks sightlessly!%^RESET%^",({wielder,victim}));
    victim->set_temporary_blinded(1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,4));
}

void special_tier3(object wielder,object victim) {
    int i, dc;
    object *targetz;
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Whisps of %^BOLD%^%^BLACK%^sh%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w %^RESET%^%^MAGENTA%^gather about you, and you unleash them in a sudden burst as you leap forward to strike at "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^Whisps of %^BOLD%^%^BLACK%^sh%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w %^RESET%^%^MAGENTA%^gather about "+wielder->QCN+", and as "+wielder->QS+" leaps forward to strike at you they are unleashed in a sudden burst!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^Whisps of %^BOLD%^%^BLACK%^sh%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^d%^RESET%^o%^BOLD%^%^BLACK%^w %^RESET%^%^MAGENTA%^gather about "+wielder->QCN+", and as "+wielder->QS+" leaps forward to strike at "+victim->QCN+" they are unleashed in a sudden burst!%^RESET%^",({wielder,victim}));
    targetz = wielder->query_attackers();
    targetz -= ({victim});
    targetz -= ({wielder});
    dc = 1+(tier*6)+roll_dice(1,6); // flat DC to scale with relative caster level, up to max 25 per master weapon standard.
    if(sizeof(targetz)) {
      for(i=0;i<sizeof(targetz);i++) {
        if(!"daemon/saving_throw_d"->reflex_save(targetz[i],dc) && !"daemon/feat_d"->usable_feat(targetz[i],"evasion")) {
          tell_object(targetz[i],"%^BOLD%^%^BLACK%^The shadows tear at your flesh!%^RESET%^");
          tell_room(EETO,"%^BOLD%^%^BOLD%^%^BLACK%^The shadows tear through "+targetz[i]->QCN+"!%^RESET%^",targetz[i]);
          targetz[i]->do_damage("torso",roll_dice(tier,4));          
        }
      }
    }
}

void special_tier2(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your eldritch claw %^BOLD%^%^BLACK%^fl%^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^he%^BOLD%^%^BLACK%^s %^RESET%^%^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s claw %^BOLD%^%^BLACK%^fl%^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^he%^BOLD%^%^BLACK%^s %^RESET%^%^MAGENTA%^brightly as it slices into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The claw %^BOLD%^%^BLACK%^fl%^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^he%^BOLD%^%^BLACK%^s %^RESET%^%^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^BOLD%^%^BLACK%^Te%^RESET%^n%^BOLD%^%^BLACK%^ebr%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^us e%^RESET%^ne%^BOLD%^%^BLACK%^rgy%^RESET%^%^MAGENTA%^ jolts through the eldritch claw as it rends flesh and bone!%^RESET%^");
    tell_object(victim,"%^BOLD%^%^BLACK%^Te%^RESET%^n%^BOLD%^%^BLACK%^ebr%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^us e%^RESET%^ne%^BOLD%^%^BLACK%^rgy%^RESET%^%^MAGENTA%^ jolts through "+wielder->QCN+"'s claw as it rends flesh and bone!%^RESET%^");
    tell_room(environment(wielder),"%^BOLD%^%^BLACK%^Te%^RESET%^n%^BOLD%^%^BLACK%^ebr%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^us e%^RESET%^ne%^BOLD%^%^BLACK%^rgy%^RESET%^%^MAGENTA%^ jolts through "+wielder->QCN+"'s claw as it rends "+victim->QCN+"'s flesh and bones!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,10)+2);
    TO->remove_property("magic");
}