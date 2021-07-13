//somewhat based on Aura of Healing by Garrett
//Circe 7/29/05
//Adjusted by ~Circe~ 1/13/16 to improve healing
//trying heart_beat since the combat approach is not working ~Circe~ 11/10/19
#include <std.h>
#include <daemons.h>
#include <priest.h>

inherit SPELL;

int timer,flag,stage,toggle,counter;

void create()
{
    ::create();
    set_spell_name("true metabolism");
    set_spell_level(([ "psion" : 8 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS true metabolism");
    set_description("This power will allow the psion to focus his energy on making minor bodily adjustments, in effect healing himself over time. The power will gradually expend itself over time.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    traveling_spell(1);
}

int preSpell() {
    if (caster->query_property("true metabolism")) {
      tell_object(caster,"You are already under the effects of this power!");
        return 0;
    }
    counter = clevel*5+4;
    return 1;
}

void spell_effect(int prof)
{
    if(!objectp(caster)){
        dest_effect();
        return;
    }
    caster->set_property("true metabolism",1);
    tell_object(caster, "%^RED%^You focus your energies so that your body will repair itself!%^RESET%^");
    if(!FEATS_D->usable_feat(caster,"metabolic perfection"))
        caster->set_property("spelled", ({TO}) );
    spell_successful();
    addSpellToCaster();
    execute_attack();
    counter = clevel * 10 + 4;
    call_out("room_check",ROUND_LENGTH);
}

void room_check()
{
    if(!objectp(caster) || !objectp(ENV(caster)))
    {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check",ROUND_LENGTH);
    return;
}


void execute_attack()
{
    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster) || !objectp(environment(caster)) || counter<0){
        dest_effect();
        return;
    }
    if(caster->query_unconcious()){
        dest_effect();
        return;
    }
    define_base_damage(0);//lazy reroll
    if((int)caster->query_hp() < (int)caster->query_max_hp()){
        tell_object(caster,"%^BOLD%^%^CYAN%^You make a mental adjustment, healing some of your wounds!%^RESET%^");
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^Some of "+caster->QCN+"'s wounds seem to heal!%^RESET%^",caster);
        if(FEATS_D->usable_feat(caster,"metabolic perfection"))
            sdamage*=19/5;
        damage_targ(caster,"torso",-sdamage,"untyped");
    }
    if(!FEATS_D->usable_feat(caster,"metabolic perfection"))
        counter--;
    prepend_to_combat_cycle(place);
}


void dest_effect(){
    remove_call_out("room_check");
    if(objectp(caster)){
        caster->remove_property("true metabolism");
        tell_object(caster,"%^CYAN%^You feel the hyper awareness of your body's injuries fade away.%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
