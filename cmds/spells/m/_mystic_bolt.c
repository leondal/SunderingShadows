// Mystic Bolt
//Updated by ~Circe~ 4/26/08 to bring in line with
//other bolt spells - rebalancing domains
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create(){
    ::create();
    set_spell_name("mystic bolt");
    set_spell_level(([ "cleric" : 5 ]));
    set_spell_sphere("abjuration");
    set_domains("magic");
    set_syntax("cast CLASS mystic bolt on TARGET");
    set_description("This spell sends a mystical bolt of energy to ravage the target.  Those standing nearby may be hit "
"as well.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    splash_spell(1);
}

int preSpell(){
    if(!objectp(target)){
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string(){
    tell_object(caster,"%^BOLD%^%^BLUE%^As you intone an ancient prayer,"+
        " multi-hued bands of energy snake around your fingers.");
    tell_room(place,"%^BOLD%^%^BLUE%^As "+caster->QCN+" intones an ancient prayer, "+
        "multi-hued bands of energy snake around "+caster->QP+" fingers.",caster);
	return "display";
}

void spell_effect(int prof){
    int damage,i;
    object *attackers;

    if (!objectp(caster)){
        dest_effect();
        return;
    }
    if(!present(target,place)){
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }

    attackers = target_selector();
    attackers += ({ target });
    attackers = distinct_array(attackers);

    damage = sdamage;

    tell_object(caster,"%^BLUE%^You hurl your fist towards "+target->QCN+" and a bolt of energy "
        "flows forth towards "+target->QO+".");
    tell_object(target,"%^BLUE%^A bolt of energy flows forth from "+caster->QCN+"'s hand towards you!");
    tell_room(place,"%^BLUE%^"+ caster->QCN+" hurls "+caster->QP+" fist forth and a bolt of "
        "energy flows towards "+target->QCN+"!",({ caster, target}) );

    if(sizeof(attackers)){
        for(i=0;i<sizeof(attackers);i++){
            define_base_damage(0);
            damage = sdamage;
            if(!objectp(attackers[i])) { continue; }
            if(!present(attackers[i],place)) { continue; }
            if(attackers[i] == target){
                if(!do_save(target,0)) {
               //if (!SAVING_D->saving_throw(target, "spell",0)){
                  tell_object(target,"%^BOLD%^%^BLUE%^The mystic bolt strikes you, ravaging your mind.");
                  tell_room(place,"%^BOLD%^The mystic bolt strikes "+target->QCN+".", ({ target}) );
                  damage_targ(target, "torso", damage,"divine");
                  spell_kill(target,caster);
               }else{
                  tell_object(target,"%^CYAN%^The mystic bolt narrowly misses you.");
                  tell_room(place,"%^CYAN%^The mystic bolt narrowly misses "+target->QCN+".", target);
                  damage_targ(target, "torso", damage/2,"divine");
                  spell_kill(target,caster);
               }
            }else{
                if(!do_save(attackers[i],0)) {
               //if (!SAVING_D->saving_throw(attackers[i], "spell",0)){
                  tell_object(attackers[i],"%^BOLD%^%^BLUE%^You are struck by the mystic bolt!");
                  tell_room(place,"%^BOLD%^The mystic bolt strikes "+attackers[i]->QCN+".",({attackers[i]}));
                  damage_targ(attackers[i], "torso", damage,"divine");
                  spell_kill(attackers[i],caster);
               }else{
                  tell_object(attackers[i],"%^CYAN%^The mystic bolt grazes you.");
                  tell_room(place,"%^CYAN%^The mystic bolt grazes "+attackers[i]->QCN+".", attackers[i]);
                  damage_targ(attackers[i], "torso", damage/2,"divine");
                  spell_kill(attackers[i],caster);
               }
            }
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
