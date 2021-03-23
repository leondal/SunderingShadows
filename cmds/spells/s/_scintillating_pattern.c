#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create()
{
    ::create();
    set_spell_name("scintillating pattern");
    set_spell_level(([ "mage" : 8, "cleric" : 8 ]));
    set_spell_sphere("illusion");
    set_domains("illusion");
    set_syntax("cast CLASS scintillating pattern");
    set_damage_desc("mass confusion for clevel/5 + 1 rounds on enemies");
    set_description("This casting summons forward illusionary patter that briefly captivates and confuses enemies that are weaker than the spell.");
    splash_spell(2);
}

void spell_effect(int prof)
{
    object* attackers;
    int i, admg;
    attackers = target_selector();

    tell_room(place, "%^MAGENTA%^%^BOLD%^Spirals of scintillating patterns appear in the air!%^RESET%^");
    if (!sizeof(attackers)) {
        dest_effect();
        return;
    }

    for (i = 0; i < sizeof(attackers); i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        if (attackers[i]->query_level() < clevel && !mind_immunity_damage(attackers[i])) {
            tell_room(place, "%^MAGENTA%^Spirals capitvate " + attackers[i]->QCN + "!");
            "/std/effect/status/confused"->apply_effect(target, clevel / 5 + 1, caster);
        }
    }
    spell_successful();
}
