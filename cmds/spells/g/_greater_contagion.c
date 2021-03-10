#include <std.h>

inherit "/cmds/spells/c/_contagion";

void create() {
    ::create();
    set_spell_name("greater contagion");
    set_spell_level(([ "cleric":5, "druid":5, "mage":5]));
    set_spell_sphere("necromancy");
    set_damage_desc("Random disease");
    set_syntax("cast CLASS greater contagion on TARGET");
    set_description("This spell functions as contagion, except the victim cannot overcome the disease without magic—making the required number of saves does not cure it.");

    set_verbal_comp();
    set_somatic_comp();

    set_target_required(1);

    set_save("fort");
    evil_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^"+caster->QCN+" steps into the shadows, then mixes something in his hands while chanting in a deep, dark tone.";
}

int query_forced_infection()
{
    return 1;
}
