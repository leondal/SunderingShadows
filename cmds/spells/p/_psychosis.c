#include <spell.h>
#include <magic.h>
#include <daemons.h>
#include <magic_effects.h>
inherit SPELL;

int counter = 0;

void create()
{
    ::create();
    set_spell_name("psychosis");
    set_spell_level(([ "psion" : 7 ]));
    set_spell_sphere("telepathy");
    set_syntax("cast CLASS psychosis on TARGET");
    set_damage_desc("continuously confuses target");
    set_description("This psychic power repeatedly applies confusion to target.");
    set_verbal_comp();
    mental_spell();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    return "%^CYAN%^BOLD%^Psychic energy coalesces as " + caster->QCN + " manifests a power.%^RESET%^";
}

void spell_effect(int prof)
{
    if (!objectp(target)) {
        dest_effect();
    }
    tell_object(caster, "%^BLUE%^You send an assault of psychic energy at " + target->QCN + "!");
    tell_room(place, "%^BLUE%^" + caster->QCN + " sends an assault of psychic energy at " + target->QCN + "!", caster);

    target->set_property("spelled", ({ TO }));
    addSpellToCaster();
    check_confusion();
    spell_successful();
}

void check_confusion()
{
    if (!objectp(target)) {
        dest_effect();
    }

    if (counter > (clevel / 4 + 4)) {
        dest_effect();
    }

    counter++;

    if (!do_save(target, -2)) {
        CONFUSION->confuse(caster, target);
        call_out("check_confusion", ROUND_LENGTH);
    }else {
        tell_room(ENV(target), "%^BOLD%^%^WHITE%^" + target->QCN + " shakes off the confusion.");
        spell_kill(target, caster);
        dest_effect();
    }
}

void dest_effect()
{
    remove_call_out("check_confusion");
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
