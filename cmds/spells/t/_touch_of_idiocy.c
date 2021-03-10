#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int adjust,origstr, theProf;

int is_curse()
{
    return 1;
}

void create() {
    ::create();
    set_spell_name("touch of idiocy");
    set_spell_level(([ "mage" : 2, "magus" : 2 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS touch of idiocy on TARGET");
    set_damage_desc("1d8 to mental stats");
    set_description("With a touch, you reduce the target's mental faculties. Your successful melee touch attack applies a 1d6 penalty to the target's Intelligence, Wisdom, and Charisma scores.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

int preSpell()
{
    if(target->query_property("idiocied"))
    {
        tell_object(caster,"The target is already cursed with this spell!");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int roll;
    ::spell_effect();
    theProf = prof;

    if(!caster->ok_to_kill(target)) {
        dest_effect();
        return;
    }

    if(target->query_property("idiocied"))
    {
        tell_object(caster,"The target is already cursed with this spell!");
        return;
    }

    spell_kill(target,caster);
    roll = BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    if(!roll || roll == -1 && ! caster->query_property("spectral_hand"))
    {
        tell_object(target, "You are narrowly missed by a ray emanating from "+caster->QCN+".\n");
        tell_room(place, target->QCN+" is narrowly missed by a ray emanating from "+caster->QCN+".\n",({ caster, target}));
        tell_object(caster, "Your ray of enfeeblement missed "+target->QCN+".\n");
        spell_kill(target,caster);
        TO->remove();
    } else {
        spell_successful();
        target->set_property("idiocied", 1);
        tell_object(target, "%^BOLD%^%^MAGENTA%^You are hit by a ray emanating from "+caster->QCN+".");
        tell_object(target, "You suddenly feel very stupid.");
        tell_room(place, "%^BOLD%^%^BLUE%^"+target->QCN+" is hit by a ray emanating from "+caster->QCN+".\n", ({ caster, target}));
        tell_object(caster, "%^BOLD%^%^BLUE%^You channel curse through your hand into "+target->QCN+"!\n");
        adjust=roll_dice(1,8);
        target->add_stat_bonus("intelligence", -adjust);
        target->add_stat_bonus("wisdom", -adjust);
        target->add_stat_bonus("charisma", -adjust);
        target->set_property("spelled", ({TO}) );
        spell_duration = (clevel / 10 + 1) * ROUND_LENGTH;
        set_end_time();
        call_out("dest_effect",spell_duration);
        addSpellToCaster();
    }
    return 1;
}

void dest_effect() {
    remove_call_out("dest_effect");
    if(objectp(target))
    {
        tell_object(target, "%^BOLD%^%^BLUE%^You recover your mental abilities.");
        tell_object(caster,"%^BOLD%^%^BLUE%^You sense that curse you placed on "+target->QCN+"'s mind fades.");
        target->remove_property("idiocied");
        target->remove_property_value("spelled", ({TO}) );
        target->add_stat_bonus("intelligence", adjust);
        target->add_stat_bonus("charisma", adjust);
        target->add_stat_bonus("wisdom", adjust);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
