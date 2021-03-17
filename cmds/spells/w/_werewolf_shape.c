#include <spell.h>
#include <daemons.h>
inherit SPELL;
int bonus;

string *valid_forms()
{
    return ({"werewolf","wolf",});
}

void create()
{
    ::create();
    set_spell_name("werewolf shape");
    set_spell_level(([ "innate" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS werewolf shape on werewolf|wolf");
    set_description("With this power, a werewolf can transform itself into a huge wolf, or into a humanoid wolf-like being. The wolf form acts much like a common wolf in combat, with powerful specials. The hybrid form looks a lot like the original humanoid form, with wolf-like ears and soft fur. Both forms provide bonuses to physical attributes, armor class, sight, attack, damage, perception, and survival. They also develop a weakness to silver.

%^BOLD%^%^RED%^N.B.%^RESET%^ You can set an alternative description, speech string and adjective for these forms.");
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
    new("/std/races/shapeshifted_races/werewolf_" + arg + ".c")->init_shape(caster, arg);

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
