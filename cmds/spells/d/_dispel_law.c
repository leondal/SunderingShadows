#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("dispel law");
    set_spell_level(([ "cleric" : 5, "inquisitor":5, "paladin":4]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS dispel law on TARGET");
    set_description("Dispel Law can only be cast by users of chaotic alignment and it only effects targets of lawful "
"alignment.  When cast at a target of the correct alignment, it will disrupt the harmonics of their soul and wrack their "
"body with pain, doing a significant amount of damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^%^GREEN%^Holding your hand out,"+
		" you begins to chant in a wild shifting tone.");
    tell_room(place,"%^BOLD%^%^GREEN%^Holding "+caster->QP+" hand out,"+
		" "+caster->QCN+" begins to chant in a wild shifting tone.",caster);
    return"display";
}

int preSpell()
{
    if (!target)
    {
        tell_object(caster, "That is not here.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int damage;
    tell_room(place, "%^BOLD%^%^GREEN%^The air shimmers as "+caster->QCN+" completes"+
		" "+caster->QP+" chant.", caster);
    tell_object(caster, "%^BOLD%^%^GREEN%^Your chant builds in power, causing the "+
		"very air to shimmer.");

    if(target && !present(target,PLACE))
    {
        dest_effect();
        return;
    }
    if(target && !caster->ok_to_kill(target))
    {
        dest_effect();
        return;
    }
    if(!is_chaotic(caster))
    {
        tell_object(caster, "Only those of chaotic alignment may cast this spell.");
        dest_effect();
        return;
    }
    if(!is_lawful(target))
    {
        tell_object(target, "This spell only affects those of lawful alignment.");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^MAGENTA%^"+target->QCN+" twists in pain as the"+
		" spell tears at the fiber of their being.");
    tell_object(target,"%^BOLD%^%^MAGENTA%^You can feel your very soul wracked with"+
		" an incredible pain at the chaotic tone of "+caster->QCN+"'s chant.");
    if(do_save(target,0))
        damage = sdamage / 2;
    else
        damage = sdamage;
    damage_targ(target,target->return_target_limb(),damage,"divine");
	spell_kill(target,caster);
    spell_successful();
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
