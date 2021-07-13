// Guidance for Druids
// Coded by ~Circe~ 3/20/13
// Based on Bless for Clerics
#include <std.h>
#include <magic.h>

inherit SPELL;

int bonus;

void create() {
    ::create();
    set_spell_name("guidance");
    set_spell_level(([ "cantrip":1 ]));
    set_mystery(({"elemental", "nature"}));
    set_spell_sphere("alteration");
    set_bonus_type("competence");
    set_syntax ("cast CLASS guidance on TARGET");
    set_description("This spell will offer guidance to the target, "
       "giving him a slightly better chance to hit in combat as "
       "well as allowing him to do a small amount more damage. This spell won't work with bless kind of spells.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

int preSpell(){
    if(!target) { target = caster; }
    /*
    if(target->query_property("blessed")){
     tell_object(caster,"%^ORANGE%^Your target has already blessed.");
        return 0;
    }
    if(target->query_property("blighted")){
     tell_object(caster,"%^ORANGE%^Your target has already received guidance.");
        return 0;
    }
    */
    return 1;
}

string query_cast_string()
{
    string god;
    god = (string)caster->query_diety();
    if(!god) { god = "nature"; }

     tell_object(caster,"%^BOLD%^%^WHITE%^Feeling the wisdom of "
        ""+capitalize(god)+" flowing through you, you begin to whisper an incantation.%^RESET%^");
     tell_room(place,"%^BOLD%^%^WHITE%^With a knowing gleam in "+caster->QP+" eyes, "
        ""+caster->QCN+" begins to whisper an incantation to "+caster->QP+" deity.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof)
{
    int duration;
    string god;

    duration = (ROUND_LENGTH * 20) * clevel;

    god = (string)caster->query_diety();
    if(!god) { god = "nature"; }

    bonus = 1;
    bonus = bonus>2?2:bonus;
	if(target == caster)
    {
       tell_room(place,"%^BOLD%^%^GREEN%^"+target->QCN+" glows with a "
          "healthy vigor as knowledge brightens "+target->QP+" eyes.%^RESET%^",target);
       tell_object(target,"%^BOLD%^%^GREEN%^You feel the wisdom of "+capitalize(god)+" "
          "rush through you, strengthening your body and granting you insight.%^RESET%^");
    }
    else
    {
       tell_object(caster,"%^BOLD%^%^GREEN%^You call on "+capitalize(god)+"'s "
          "aid as you offer guidance to "+target->QCN+".");
       tell_object(target,"%^BOLD%^%^GREEN%^You feel a surge of energy "
          "and clarity of mind as "+caster->QCN+" calls on "+caster->QP+" "
          "deity for aid, offering you guidance.%^RESET%^");
       tell_room(place, "%^BOLD%^%^GREEN%^"+caster->QCN+" calls on "+caster->QP+" deity for aid, offering "
            ""+target->QCN+" guidance.%^RESET%^",({caster,target}));
    }
    target->add_damage_bonus(bonus);
    target->add_attack_bonus(bonus);
    addSpellToCaster();
    target->set_property("spelled",({TO}));
    //target->set_property("blessed",1);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect()
{
    if(objectp(target))
    {
        tell_object(target,"%^ORANGE%^You can feel the guidance you have been granted fade "
            "away.");
        target->add_damage_bonus(-1*bonus);
        target->add_attack_bonus(-1*bonus);
        //target->remove_property("blessed");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
