// Updated by ~Circe~ 5/11/08 for the rebalancing of domains
// Id Insinuation
// ~Circe~ 9/11/05
// Ganked for the priest spell confusion -Ares
#include <spell.h>
#include <daemons.h>

inherit SPELL;

object mytarg;
int rnds,total;

void create(){
    ::create();
    set_spell_name("confusion");
    set_spell_level(([ "oracle" : 4, "bard" : 3, "mage" : 4, ]));
    set_mystery("whimsy");
    set_spell_sphere("enchantment_charm");
    set_domains(({"trickery", "mentalism"}));
    set_syntax("cast CLASS confusion on TARGET");
    set_damage_desc("confusion for clevel/5 + 1 rounds on target");
    set_description("This spell will attempt to confuse the target and make them do random things.  They might babble "
"incoherently, attack the closest thing to them, or simply wander away.  When used on a player, it simply causes them to "
"stand and stare blankly.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    mental_spell();
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

int preSpell(){
    if(!target){
        tell_object(caster,"You need a target for this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
    int bonus;
    mytarg = target;
    bonus = clevel/6;
    bonus = -1*bonus;
    total = clevel/5;
    if(total < 0) total = 0;
    total += 3;

    tell_object(target,"%^BOLD%^%^CYAN%^"+caster->QCN+" gazes at you intently as "
        ""+caster->QS+" begins to chant!");
    tell_object(caster,"%^BOLD%^%^CYAN%^You gaze intently at "+target->QCN+" as "
        "you begin to chant!");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" gazes at "+target->QCN+" intently "
        "as "+caster->QS+" begins to chant!",({caster,target}));

    if(do_save(mytarg,bonus))
    //if(do_saving_throw(mytarg,"spell",bonus))
    {
        tell_object(caster,"%^BOLD%^%^GREEN%^"+target->QCN+" is able to resist the pull "
            "of your spell!");
        tell_object(target,"%^GREEN%^%^BOLD%^You are able to resist the pull of "+caster->QCN+"'s "
            "spell!");
        tell_room(place,"%^BOLD%^%^GREEN%^"+target->QCN+" shakes "+target->QP+" head and as "
            ""+caster->QCN+" completes "+caster->QP+" spell.",({caster,target}));
        if(!target->is_player()) { spell_kill(mytarg, caster); }
        TO->dest_effect();
        return;
    }else{
        if(mind_immunity_damage(target, "default"))
        {
            spell_successful();
            dest_effect();
            return;
        }

        "/std/effect/status/confused"->apply_effect(target,clevel/5+1,caster);
    }
}
