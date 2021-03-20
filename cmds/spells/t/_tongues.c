#include <std.h>
#include <langs.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("tongues");
    set_spell_level(([ "mage" : 3, "bard" : 2, "psion" : 2, "inquisitor" : 2, "cleric" : 3, "magus" : 3 ]));
    set_spell_sphere("alteration");
    set_mystery("lore");
    set_syntax("cast CLASS tongues on TARGET");
    set_description("This will give the target the ability to understand, both read and write any language. This should not change the ability to teach the language.");
    set_verbal_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return caster->QCN + " starts to mouth out syllables.\n";
}

void spell_effect()
{
    int i;

    if (!objectp(target)) {
        target = caster;
    }

    tell_object(target, "%^BOLD%^You start to feel knowledge enter your mind that you lacked before.");

    if (target != caster) {
        tell_object(caster,"%^BOLD%^You grant " + target->QCN + " knowledge of tongues.");
    }

    spell_successful();

    for (i = 0; i < sizeof(ALL_LANGS); i++) {
        if (member_array(ALL_LANGS[i], OLD_LANGS) == -1) {
            target->add_lang_overload(ALL_LANGS[i], 100);
        }
    }
    addSpellToCaster();
    caster->set_property("spelled", ({ TO }));
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 3;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    int i;

    if (objectp(target)) {
        for (i = 0; i < sizeof(ALL_LANGS); i++) {
            if (member_array(ALL_LANGS[i], OLD_LANGS) == -1) {
                target->subtract_lang_overload(ALL_LANGS[i], 100);
            }
        }
        tell_object(target,"%^BOLD%^Knowledge of tongues fades from your mind.");
    }

    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
