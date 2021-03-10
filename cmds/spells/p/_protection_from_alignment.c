#include <std.h>
#include <magic.h>
inherit SPELL;

int lower;
object weap;

void create()
{
    ::create();
    set_spell_name("protection from alignment");
    set_spell_level(([ "inquisitor" : 1, "cleric" : 1, "mage":1, "paladin":1]));
    set_spell_sphere("abjuration");
    set_domains(({"good", "evil", "chaos", "law"}));
    set_syntax("cast CLASS protection from alignment on good|evil|chaos|law");
    set_damage_desc("+2 to saves");
    set_description("This spell allows you to ward yourself from spells originating at casters with specified alignment. You must belong to opposing alignment group to be able to use this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed(1);
}

void spell_effect()
{
    string poisonf, weapstr, alignstr;

    alignstr = arg;

    if (!alignstr)
    {
        tell_object(caster,"Syntax:" + query_syntax());
        TO->remove();
        return;
    }

    if (!regexp(alignstr, "good|evil|chaos|law")) {
        tell_object(caster,"Syntax:" + query_syntax());
        TO->remove();
        return;
    }

    switch (alignstr) {
    case "good":
        if (member_array(caster->query_true_align(), ({ 3, 6, 9 })) == -1) {
            wrong_align();
            return;
        }
        break;
    case "evil":
        if (member_array(caster->query_true_align(), ({ 1, 4, 7 })) == -1) {
            wrong_align();
            return;
        }
        break;
    case "law":
        if (member_array(caster->query_true_align(), ({ 7, 8, 9 })) == -1) {
            wrong_align();
            return;
        }
        break;
    case "chaos":
        if (member_array(caster->query_true_align(), ({ 1, 2, 3 })) == -1) {
            wrong_align();
            return;
        }
        break;
    }

    if (objectp(caster)) {
        switch (alignstr) {
        case "good":
            caster->set_property("protection_from_alignment", ({ 3, 6, 9 }));
            break;
        case "evil":
            caster->set_property("protection_from_alignment", ({ 1, 4, 7 }));
            break;
        case "law":
            caster->set_property("protection_from_alignment", ({ 7, 8, 9 }));
            break;
        case "chaos":
            caster->set_property("protection_from_alignment", ({ 1, 2, 3 }));
            break;
        }

        tell_object(caster, "%^CYAN%^Chanting in low undertones you attune yourself to ward against opposing auras.");

        caster->set_property("spelled",({TO}));
        spell_successful();
        addSpellToCaster();
    }
}

void wrong_align()
{
    tell_object(caster,"You're not of appropriate alignment to use this argument!");
}


void dest_effect()
{
    if (objectp(caster)) {
        caster->remove_property("aligned_weapon");
        tell_object(caster, "%^CYAN%^You sense your ability to ward against opposing auras fades.");
    }
    ::dest_effect();
}
