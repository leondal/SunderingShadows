//Lion's Charge
//Psywarrior attack spell ~Circe~ 9/29/15

#include <spell.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("lions charge");
    set_spell_level(([ "psywarrior" : 2 ]));
    set_syntax("cast CLASS lions charge on TARGET");
    set_spell_sphere("psychometabolism");
    set_save("reflex");
    set_description("When manifesting this power, the psionic character "
       "charges toward her foe and attempts to knock him down. The damage "
       "done will depend on any weapon the psionic character has wielded.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

void spell_effect(int prof) {
    object *weapons, myweapon;
    int bonus, enchant, damage, mylevel;
    if(!objectp(target)){
       tell_object(caster,"You don't see that here!");
       dest_effect();
       return;
    }
    if(target == caster){
       tell_object(caster,"Don't try to charge yourself!");
       dest_effect();
       return;
    }
    if(caster->query_in_vehicle()) {
        tell_object(caster,"You cannot manifest this power while mounted!");
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster,"%^RESET%^%^ORANGE%^With a mighty roar, "
           "you leap toward "+target->QCN+"!%^RESET%^");
    }
    mylevel = clevel;
    tell_object(target,"%^RESET%^%^ORANGE%^"+caster->QCN+" gives a "
       "mighty roar and leaps toward you!%^RESET%^");
    tell_room(place,"%^RESET%^%^ORANGE%^"+caster->QCN+" gives a mighty roar "
       "and leaps toward "+target->QCN+"!%^RESET%^", ({caster, target}) );
    bonus = 0;
    if(sizeof(caster->query_wielded())) {
        weapons = caster->query_wielded();
        myweapon = weapons[0];
        if(myweapon->is_lrweapon()) {
           bonus = 0;
        }else{
           enchant = (int)myweapon->query_property("enchantment");
           if(enchant < 0) enchant = 0;
           bonus += enchant;

        }
    }
    if(do_save(target,0)){
        tell_object(caster,"%^BOLD%^%^RED%^You charge straight past "
           ""+target->QCN+", missing "+target->QO+" entirely!%^RESET%^");
        tell_object(target,"%^BOLD%^%^RED%^You sidestep, avoiding "+caster->QCN+"'s charge!%^RESET%^");
        tell_room(place,"%^BOLD%^%^RED%^"+target->QCN+" sidesteps, "
           "avoiding "+caster->QCN+"'s charge!%^RESET%^", ({caster, target}));
        spell_successful();
        dest_effect();
        return;
    }

    damage = sdamage*7/6;
    if(objectp(myweapon)){
        if((int)target->query_size() < 3) damage += myweapon->query_damage();
        else damage += myweapon->query_large_damage();
    }else if(caster->query_property("shapeshifted")){
        damage += (int)caster->get_hand_damage();
    }

    damage += "/daemon/bonus_d"->damage_bonus(caster->query_stats("intellience"));
    damage += (int)caster->query_damage_bonus();

    if(target->query_property("weapon resistance")){
        if(enchant < (int)target->query_property("weapon resistance")){
            damage = 0;
        }
    }

    tell_object(caster,"%^YELLOW%^You pounce on "+target->QCN+", knocking "
       ""+target->QO+" to the ground!%^RESET%^");
    tell_object(target,"%^YELLOW%^"+caster->QCN+" pounces on you, knocking "
       "you to the ground!%^RESET%^");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" pounces on "+target->QCN+", "
       "knocking "+target->QO+" to the ground!%^RESET%^", ({caster, target}));

    if(target->is_npc() || userp(target)) {
      if(target->query_deaths_door() && (userp(caster) || caster->query_property("knock unconscious"))) {
        target->cease_all_attacks();
        target->remove_attacker(caster);
        caster->remove_attacker(target);
        tell_object(caster,"%^BOLD%^%^RED%^"+target->QCN+" falls unconscious "+
          "after you slam into "+target->QO+"!");
     	  tell_room(environment(caster),"%^BOLD%^%^RED%^"+caster->QCN+" slams "+
          "full force into "+target->QCN+", knocking "+target->QO+" completely "+
          "unconscious due to wounds!",({target,caster}));
        tell_object(target,"%^BOLD%^%^RED%^"+caster->QCN+" slams full force "+
          "into you, knocking you unconscious.\n");
      }
    }
    damage_targ(target, target->return_target_limb(), damage, "force");
    spell_successful();
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
