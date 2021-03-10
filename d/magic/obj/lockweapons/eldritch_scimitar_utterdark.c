#include <std.h>
#include <magic.h>
inherit "/d/magic/obj/lockweapons/eldritch_scimitar";

void create() {
   ::create();
   set_id(({"eldritch scimitar","scimitar","energy scimitar","scimitar of energy","scimitar of malefic energy","eldritch_weapon_xxx"}));
}

void special_tier1(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^You lunge into the fray as a h%^BOLD%^%^BLACK%^az%^RESET%^%^MAGENTA%^y s%^RESET%^i%^MAGENTA%^lho%^BOLD%^%^BLACK%^u%^RESET%^et%^MAGENTA%^te forms in your wake. It mirrors your strike with its own, even as it is shredded upon the air back into nothingness!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^"+wielder->QCN+" lunges into the fray as a h%^BOLD%^%^BLACK%^az%^RESET%^%^MAGENTA%^y s%^RESET%^i%^MAGENTA%^lho%^BOLD%^%^BLACK%^u%^RESET%^et%^MAGENTA%^te forms in "+wielder->QP+" wake. It mirrors "+wielder->QP+" strike with its own, even as it is shredded upon the air back into nothingness!%^RESET%^",wielder);
    if(sizeof(ETO->query_attackers())) ETO->execute_attack();
}

void special_tier3(object wielder,object victim) {
    int duration;
    object secondary;
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your scimitar carves into "+victim->QCN+" and you unleash a blast of %^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^w po%^RESET%^we%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^, shattering "+victim->QP+" strength!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s scimitar carves into you and "+wielder->QS+" unleashes a blast of %^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^w po%^RESET%^we%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^, shattering your strength!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s scimitar carves into "+victim->QCN+" and "+wielder->QS+" unleashes a blast of %^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^w po%^RESET%^we%^BOLD%^%^BLACK%^r%^RESET%^%^MAGENTA%^, shattering "+victim->QP+" strength!%^RESET%^",({wielder,victim}));
    duration = 120/ROUND_LENGTH; // -4 str, 2min
    secondary = present("eldritch_utterdark_xxx",victim);
    if(!objectp(secondary)) {
      secondary = new("/d/magic/obj/eldritch_effects/eldritch_utterdark");
      secondary->move(victim);
    }
    secondary->activate(duration);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6));
}

void special_tier2(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^Your eldritch scimitar f%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^a%^RESET%^s%^MAGENTA%^h%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^s brightly as it slices into "+victim->QCN+"!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^"+wielder->QCN+"'s scimitar f%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^a%^RESET%^s%^MAGENTA%^h%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^s brightly as it slices into you!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^The scimitar f%^BOLD%^%^BLACK%^l%^RESET%^%^MAGENTA%^a%^RESET%^s%^MAGENTA%^h%^BOLD%^%^BLACK%^e%^RESET%^%^MAGENTA%^s brightly as it slices into "+victim->QCN+"!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,6)+2);
    TO->remove_property("magic");
}

void special_tier4(object wielder,object victim) {
    tell_object(wielder,"%^RESET%^%^MAGENTA%^M%^BOLD%^%^BLACK%^al%^RESET%^%^MAGENTA%^ef%^RESET%^i%^MAGENTA%^c e%^BOLD%^%^BLACK%^n%^RESET%^e%^MAGENTA%^rgy jolts through the eldritch scimitar as it rends flesh and bone!%^RESET%^");
    tell_object(victim,"%^RESET%^%^MAGENTA%^M%^BOLD%^%^BLACK%^al%^RESET%^%^MAGENTA%^ef%^RESET%^i%^MAGENTA%^c e%^BOLD%^%^BLACK%^n%^RESET%^e%^MAGENTA%^rgy jolts through "+wielder->QCN+"'s scimitar as it rends flesh and bone!%^RESET%^");
    tell_room(environment(wielder),"%^RESET%^%^MAGENTA%^M%^BOLD%^%^BLACK%^al%^RESET%^%^MAGENTA%^ef%^RESET%^i%^MAGENTA%^c e%^BOLD%^%^BLACK%^n%^RESET%^e%^MAGENTA%^rgy jolts through "+wielder->QCN+"'s scimitar as it rends "+victim->QCN+"'s flesh and bones!%^RESET%^",({wielder,victim}));
    TO->set_property("magic",1);
    victim->do_damage(victim->return_target_limb(),roll_dice(tier,10)+2);
    TO->remove_property("magic");
}
