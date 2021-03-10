// Revised by Pator@ShadowGate
// Aug 8 1996

#include <priest.h>

inherit SPELL;

void create()
{
    ::create();
    set_author("pator");
    set_spell_name("remove disease");
    set_spell_level(([ "cleric" : 4, "bard" : 4, "paladin" : 4, "ranger" : 3, "druid" : 3,"inquisitor":3 ]));
    set_spell_sphere("healing");
    set_syntax("cast CLASS remove disease on TARGET");
    set_description("This spell will attempt to cleanse any diseases present on the TARGET. Success is based on the level of the caster versus the difficulty of the particular disease.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
}

string query_cast_string()
{
    string cast;

    cast = "%^CYAN%^"+YOU+" starts to vibrate and speaks a long incantation!";
    return cast;
}

void spell_effect(int prof)
{
    int res = 0;
    string dname;
    object * diseases, disease;
    tell_room(place, "%^BOLD%^%^WHITE%^A brilliant white aura briefly envelopes " + HIM + "!", ({ caster, target }));
    if (interactive(caster)) {
        if (target != caster) {
            tell_object(caster, "%^BOLD%^%^WHITE%^A brilliant white aura envelopes " + HIM + " as you attempt to cleanse " +
                        target->QO + "!");
        }
    }

    if (living(target)) {
        tell_object(target, "%^BOLD%^%^WHITE%^A brilliant white aura envelopes you as " + caster->QCN + " attempts to cleanse you!%^RESET%^");
    }

    diseases = filter_array(all_inventory(target), (:$1->is_disease():));

    if (sizeof(diseases)) {
        disease = diseases[random(sizeof(diseases))];

        dname = disease->query_name();
        res = disease->cure_disease(clevel * 3 / 2);
    }

    if (res == 0) {
        tell_object(caster, "%^BOLD%^%^WHITE%^" + HIM + " appears no different");
        tell_object(target, "%^BOLD%^%^WHITE%^You feel no different.%^RESET%^");
    }else {
        tell_object(caster, "%^BOLD%^%^WHITE%^" + HIM + " appears has been cleansed of " + dname + "!", ({ target }));
        tell_object(target, "%^BOLD%^%^WHITE%^You have been cleansed of the disease!");
    }

    spell_successful();
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
