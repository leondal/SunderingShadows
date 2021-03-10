#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
#include <skills.h>
inherit SPELL;

int bonus,i;

void create()
{
    ::create();
    set_spell_name("dimensional anchor");
    set_spell_level(([ "cleric" : 4, "inquisitor" : 3, "mage" : 4, "psion" : 4, "magus" : 4 ]));
    set_spell_sphere("abjuration");
    set_discipline("nomad");
    set_syntax("cast CLASS dimensional anchor on TARGET");
    set_damage_desc("prevents extraplanar travel");
    set_description("A green ray springs from your hand. You must make a ranged touch attack to hit the target. Any creature or object struck by the ray is covered with a shimmering emerald field that blocks extradimensional travel based on their caster level.");
    set_target_required(1);
}

void spell_effect()
{
    int duration;
    int roll;
    duration = ROUND_LENGTH * (clevel/6 + 1);


    roll = BONUS_D->process_hit(caster, target, 1, 0, 0, 1);

    if(!roll || roll == -1 && ! caster->query_property("spectral_hand"))
    {
        target = 0;
        tell_object(caster,"%^GREEN%^%^BOLD%^You extend your hand and a ray of green sprays out of it, but you %^WHITE%^fail%^GREEN%^ to touch "+target->QCN+".%^RESET%^");
        tell_room(place,"%^GREEN%^%^BOLD%^"+caster->QCN+" extends "+caster->QP+" hand and a ray of green sprays out of it, but %^WHITE%^fails%^GREEN%^ to land on anything.%^RESET%^",({caster}));
        dest_effect();
        return;
    }

    tell_object(caster,"%^GREEN%^%^BOLD%^You extend your hand and a ray of green sprays out of it, covering "+target->QCN+" in a green emerald field.%^RESET%^");
    tell_object(target,"%^GREEN%^%^BOLD%^"+caster->QCN+" extends "+caster->QP+" hand and a ray of green sprays out of it, covering you in a green emerald field.%^RESET%^");
    tell_room(place,"%^GREEN%^%^BOLD%^"+caster->QCN+" extends "+caster->QP+" hand and a ray of green sprays out of it, covering "+target->QCN+" in a green emerald field.%^RESET%^",({caster,target}));
    target->set_property("teleport proof",clevel);

    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    spell_successful();
}

void dest_effect() {
    if(objectp(target))
    {
        target->remove_property("teleport proof");
        tell_room(ENV(target),"%^GREEN%^%^BOLD%^A green field around "+target->QCN+" fades away.%^RESET%^",({target}));
        tell_object(target,"%^GREEN%^%^BOLD%^A green field around you fades away.%^RESET%^");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
