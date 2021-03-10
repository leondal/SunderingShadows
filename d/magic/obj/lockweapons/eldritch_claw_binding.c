#include <std.h>
#include <magic.h>
inherit "/d/magic/obj/lockweapons/eldritch_claw";

void create() {
   ::create();
   set_id(({"eldritch claw","claw","energy claw","claw of energy","claw of surging energy","eldritch_weapon_xxx"}));
   set_short("%^RESET%^%^CYAN%^cl%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^w of %^BOLD%^%^BLUE%^s%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^BOLD%^%^GREEN%^g %^BOLD%^%^WHITE%^e%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^g%^BOLD%^%^CYAN%^y%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This magical construct looks as though it would serve as a weapon of considerable %^RESET%^%^RED%^potency%^BOLD%^%^WHITE%^. "
"Instead of wood or metal, however, it is made purely of %^BOLD%^%^BLUE%^s%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^i"
"%^BOLD%^%^CYAN%^n%^BOLD%^%^GREEN%^g %^BOLD%^%^WHITE%^e%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^g%^BOLD%^%^CYAN%^y"
"%^BOLD%^%^WHITE%^. Shaped like a claw, it bears three six-inch tines that each taper to a %^YELLOW%^razor-sharp %^BOLD%^%^WHITE%^point. They spring from a "
"flattened brace that rests around and across the hand, secured in place by seemingly nothing more than sheer manifestation of %^RESET%^%^CYAN%^will"
"%^BOLD%^%^WHITE%^.%^RESET%^\n");
}

void special_tier1(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^You take a step back and unleash a j%^BOLD%^%^CYAN%^a%^RESET%^%^MAGENTA%^rr%^GREEN%^i%^BOLD%^%^GREEN%^n%^RESET%^%^MAGENTA%^g blast at "+victim->QCN+", knocking "+victim->QO+" from "+victim->QP+" feet!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+" takes a step back and unleashes a j%^BOLD%^%^CYAN%^a%^RESET%^%^MAGENTA%^rr%^GREEN%^i%^BOLD%^%^GREEN%^n%^RESET%^%^MAGENTA%^g blast that knocks you from your feet!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^"+wielder->QCN+" takes a step back and unleashes a j%^BOLD%^%^CYAN%^a%^RESET%^%^MAGENTA%^rr%^GREEN%^i%^BOLD%^%^GREEN%^n%^RESET%^%^MAGENTA%^g blast at "+victim->QCN+", knocking "+victim->QO+" from "+victim->QP+" feet!%^RESET%^%^RESET%^",({wielder,victim}));
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,4));
    victim->set_tripped(tier,"%^BOLD%^%^CYAN%^You're still trying to get back on your feet!%^RESET%^",tier);
}

void special_tier3(object wielder,object victim) {
    tell_object(wielder,"%^BOLD%^%^CYAN%^J%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^g%^BOLD%^%^CYAN%^g%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^d %^MAGENTA%^streaks of energy erupt into the air around you, dazing your foes just long enough for you to lash out again!%^RESET%^");
    tell_room(environment(wielder),"%^BOLD%^%^CYAN%^J%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^g%^BOLD%^%^CYAN%^g%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^d %^MAGENTA%^streaks of energy erupt into the air around "+wielder->QCN+", dazing "+wielder->QP+" foes just long enough for "+wielder->QO+" to lash out again!%^RESET%^",wielder);
    if(sizeof(ETO->query_attackers())) ETO->execute_attack();
}

void special_tier2(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your eldritch claw %^CYAN%^f%^BOLD%^%^CYAN%^l%^BOLD%^%^GREEN%^a%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^h%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s claw %^CYAN%^f%^BOLD%^%^CYAN%^l%^BOLD%^%^GREEN%^a%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^h%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^MAGENTA%^brightly as it slices into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The claw %^CYAN%^f%^BOLD%^%^CYAN%^l%^BOLD%^%^GREEN%^a%^RESET%^%^CYAN%^s%^BOLD%^%^WHITE%^h%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^s %^MAGENTA%^brightly as it slices into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^BOLD%^%^BLUE%^S%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^BOLD%^%^GREEN%^g %^BOLD%^%^WHITE%^e%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^g%^BOLD%^%^CYAN%^y%^RESET%^%^MAGENTA%^ jolts through the eldritch claw as it rends flesh and bone!%^RESET%^");
    tell_object(victim,"%^BOLD%^%^BLUE%^S%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^BOLD%^%^GREEN%^g %^BOLD%^%^WHITE%^e%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^g%^BOLD%^%^CYAN%^y%^RESET%^%^MAGENTA%^ jolts through "+wielder->QCN+"'s claw as it rends flesh and bone!%^RESET%^");
    tell_room(environment(wielder),"%^BOLD%^%^BLUE%^S%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^g%^RESET%^%^CYAN%^i%^BOLD%^%^CYAN%^n%^BOLD%^%^GREEN%^g %^BOLD%^%^WHITE%^e%^BOLD%^%^BLUE%^n%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^RESET%^%^CYAN%^g%^BOLD%^%^CYAN%^y%^RESET%^%^MAGENTA%^ jolts through "+wielder->QCN+"'s claw as it rends "+victim->QCN+"'s flesh and bones!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,10)+2);
    TO->remove_property("magic");
}