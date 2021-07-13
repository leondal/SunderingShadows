#include <std.h>
#include <magic.h>
#include <spell.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("precognitive perception");
    set_spell_level(([ "mage" : 4, "magus" : 4, "bard" : 4, "psion" : 3, "cleric" : 4 ]));
    set_domains("fate");
    set_spell_sphere("divination");
    set_syntax("cast CLASS precognitive perception [on TARGET]");
    set_damage_desc("half of clevel perception skill");
    set_description("You share some insights into the future with target, allowing them to better perceive the surroundings. This spell gives an exceptional defence against stabs and won't last long.");
    //set_arg_needed();
	  set_helpful_spell(1);
}

int preSpell()
{
    if(!target) target = caster;

    if(target->query_property("precognitive perception"))
    {
        tell_object(caster,"The target is already under the influence of similar effect");
        return 0;
    }
    return 1;
}

spell_effect()
{


    if(!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }

    spell_successful();
    if(target == caster){
    tell_room(place,"%^CYAN%^With a swift chant, "+caster->QCN+" touches "+target->query_possessive()+" own eyes.%^RESET%^");
    }
    else{
    tell_room(place,"%^CYAN%^With a swift chant, "+caster->QCN+" touches "+target->QCN+"'s eyes.%^RESET%^");
    }
    bonus=clevel/2+1;
    target->add_skill_bonus("perception",bonus);
    target->set_property("spelled", ({TO}) );
    target->set_property("precognitive perception",1);
    addSpellToCaster();
    spell_duration = (clevel / 10+ roll_dice(1, 6)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(target))
    {
        target->add_skill_bonus("perception",-bonus);
        target->remove_property_value("spelled", ({TO}) );
        tell_object(target,"%^CYAN%^The precognitive insights retreat.%^RESET%^");
        target->remove_property("precognitive perception");
    }
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
