#include <spell.h>
inherit SPELL;

#define DELAY 120

void create()
{
    ::create();
    set_spell_name("analyze dweomer");
    set_spell_level(([ "mage" : 6, "bard" : 6, "cleric" : 6 ]));
    set_domains("magic");
    set_spell_sphere("divination");
    set_syntax("cast CLASS analyze dweomer on TARGET");
    set_description("This spell allows you to sense what spells and magical afflictions affect the target. An ally will always fail the save, and there is always a chance the target will detect your probe.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
    set_save("will");
}

int preSpell()
{
    if (member_array(target, ob_party(caster)) == -1) {
        if (caster->query_property("analyze dweomer") + DELAY > time()) {
            tell_object(caster, "You can't cast this spell as an offensive that often.");
            return 0;
        }
    }
    return 1;
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^" + caster->QCN + " closes the eyes chanting.%^RESET%^";
}

void spell_effect()
{
    object* slist, spl;
    spell_successful();

    if (member_array(target, ob_party(caster)) == -1) {
        caster->set_property("analyze dweomer", time());
        if (do_save(target, 0)) {
            tell_object(caster, "%^BOLD%^%^CYAN%^Target shakes off your attempt to analyze them.");
            tell_object(target, "%^BOLD%^%^CYAN%^You sense magical probe trying to analyze your spells.");
            dest_effect();
            return;
        }
    }

    if (do_save(target, 18) || !random(5)) {
        tell_object(target, "%^BOLD%^%^CYAN%^You sense magical probe trying to analyze your spells.");
    }

    slist = target->query_property("dispellable spells") + target->query_property("spelled");
    slist = distinct_array(slist);

    if (!sizeof(slist)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^You sense no spells are affecting the target.");
        dest_effect();
        return;
    }

    tell_object(caster, "%^BOLD%^%^CYAN%^You sense the next spells:");
    foreach(spl in slist)
    {
        if (!objectp(spl)) {
            continue;
        }
        tell_object(caster, "  %^BOLD%^%^GREEN%^" + spl->query_name());
    }
}
