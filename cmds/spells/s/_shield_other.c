#include <std.h>
#include <magic.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("shield other");
    set_spell_level(([ "cleric" : 2, "inquisitor" : 2, "paladin" : 2, "psion" : 2 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS shield other on TARGET");
    set_damage_desc("shares damage done to target");
    set_save("will");
    set_description("This spell wards the subject and creates a mystic connection between you and the subject so that some of its wounds are transferred to you. Half of typed damage dealt to target will be transferred to you.");
    set_helpful_spell(1);
    set_target_required(1);
}

int preSpell()
{
    if (target->query_property("shielded_by")) {
        if (objectp(target->query_property("shielded_by"))) {
            tell_object(caster, "%^BOLD%^The target is already under the influence of a similar effect.");
            return 0;
        } else {
            target->remove_property("shielded_by");
        }
    }
    return 1;
}

spell_effect()
{
    spell_successful();

    if (target->query_property("shielded_by")) {
        if (objectp(target->query_property("shielded_by"))) {
            tell_object(caster, "%^BOLD%^The target is already under the influence of a similar effect.");
            dest_effect();
            return;
        } else {
            target->remove_property("shielded_by");
        }
    }

    tell_object(caster, "%^CYAN%^You extend your reach, surrounding " + target->QCN + " in a %^BOLD%^%^BLACK%^g%^BLUE%^l%^BLACK%^owin%^BLUE%^g %^BLACK%^fiel%^BLUE%^d %^BLUE%^o%^BLUE%^f %^BLACK%^magic,%^RESET%^%^CYAN%^ making a connection between you and them.");
    tell_object(target, "%^CYAN%^You feel a bond forming between you and " + caster->QCN + " as %^BOLD%^%^BLACK%^glowi%^BLUE%^n%^BLUE%^g %^BLACK%^fi%^BLUE%^e%^BLUE%^l%^BLACK%^d%^RESET%^%^CYAN%^ forms around you.");
    tell_room(place, "%^BOLD%^%^BLACK%^Glowin%^BLUE%^g %^BLUE%^f%^BLUE%^i%^BLUE%^e%^BLACK%^ld %^BLUE%^o%^BLUE%^f %^BLACK%^ma%^BLUE%^g%^BLUE%^i%^BLACK%^c%^RESET%^%^CYAN%^ raises around " + target->QCN, ({caster, target}));

    target->set_property("shielded_by", caster);

    target->set_property("spelled", ({ TO }));
    addSpellToCaster();
}

dest_effect()
{
    if (objectp(target)) {
        target->remove_property("shielded_by");
        tell_object(target, "%^BOLD%^%^BLACK%^Gl%^BLUE%^o%^BLACK%^wing %^BLACK%^f%^BLUE%^i%^BLACK%^e%^BLUE%^l%^BLACK%^d%^RESET%^%^CYAN%^ around you retreats as your protective link fades.");
        if (objectp(caster)) {
            tell_object(caster, "%^BOLD%^You sense your protective link with " + target->QCN + " is broken.");
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
