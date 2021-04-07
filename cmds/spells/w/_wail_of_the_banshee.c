#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("wail of the banshee");
    set_spell_level(([ "mage" : 9, "oracle" : 9, "cleric" : 9 ]));
    set_spell_sphere("necromancy");
    set_mystery(({ "reaper", "bones" }));
    set_syntax("cast CLASS wail of the banshee");
    set_damage_desc("sonic");
    set_domains(({ "repose", "undeath" }));
    set_description("A caster invokes a horrible arcane scream that may kill every living thing in sight, but it mostly targets those closest to the caster. Those who withstand the scream still suffer a little bit.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("fort");
    splash_spell(3);
}

string query_cast_string()
{
    return "%^BLUE%^" + caster->QCN + " starts to chant in fell tongues, and a feeling of otherwordly horror fills the area.";
}

void spell_effect(int prof)
{
    object* foes, foe;
    int max;

    tell_object(caster, "%^BLUE%^You concentrate and release a HORRIBLE SCREAM in the language of unlife.");
    tell_room(place, "%^BLUE%^" + caster->QCN + " releases a HORRIBLE SCREAM in fell tongues. You feel your soul being ripped from your body.", caster);
    message("info", "%^BLUE%^You hear a horrible high-pitched scream.", nearbyRoom(place, 2));

    foes = target_selector();

    max = clevel;

    if (sizeof(foes)) {
        foreach(foe in foes)
        {
            if (combat_death_save(foe, 0)) {
                tell_object(foe, "%^BLUE%^You sigh with relief as your soul withstands a horrid scream!");
                damage_targ(foe, foe->return_target_limb(), sdamage, "sonic");
                continue;
            }
            tell_object(foe, "%^BOLD%^%^BLUE%^You scream as your soul is carved out from your body!");
            tell_room(place, "%^BOLD%^%^BLUE%^" + foe->QCN + " screams as " + foe->QP + " soul is carved out from their body!", foe);
            damage_targ(foe, foe->return_target_limb(), foe->query_max_hp() * 2, "sonic");
            max -= foe->query_level();
        }
    }

    spell_successful();
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
