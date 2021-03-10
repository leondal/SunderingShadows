#include <spell.h>
#include <daemons.h>
inherit SPELL;
int bonus;

string* valid_forms()
{
    if (FEATS_D->usable_feat(caster, "aspect of the beast")) {
        return ({ "bat", "wolf", "vampire", "varghulf" });
    }
    return ({ "bat", "wolf", });
}

void create()
{
    ::create();
    set_spell_name("twilight shape");
    set_spell_level(([ "innate" : 4 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS twilight shape on bat|wolf");
    set_description("With this spell a vampire can change her body into a bat or a wolf. Bat is a tiny flying creature incapable of combat, while wolf form provides a vampire with the same strenghts as druidic wolf form. In addition, bat form can use <wing> command.

Vampire lord gains two additional form: vampire and varghulf.

%^BOLD%^%^RED%^N.B.%^RESET%^ You can set alternative description, speech string and adjective for these forms.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

int preSpell()
{
    object shape;
    if (objectp(shape = caster->query_property("shapeshifted")) ||
        objectp(shape = caster->query_property("altered"))) {
        tell_object(caster, "You are already in an alternative form!");
        return 0;
    }
    if (member_array(arg, valid_forms()) == -1) {
        tell_object(caster, "Invalid form, valid forms are: " + implode(valid_forms(), ", "));
        return;
    }
    return 1;
}

void spell_effect(int prof)
{
    object shape;
    if (!objectp(caster)) {
        TO->remove();
        return;
    }
    new("/std/races/shapeshifted_races/vampire_" + arg + ".c")->init_shape(caster, arg);

    if (caster->query_property("shapeshifted")) {
        shape = caster->query_property("shapeshifted");
    } else {
        shape = caster->query_property("altered");
    }

    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    object shape;
    if (objectp(caster)) {
        if (caster->query_property("shapeshifted")) {
            shape = caster->query_property("shapeshifted");
        } else {
            shape = caster->query_property("altered");
        }
        if (objectp(shape)) {
            shape->reverse_shape(caster);
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
