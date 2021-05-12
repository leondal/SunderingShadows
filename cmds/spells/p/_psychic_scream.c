#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("psychic scream");
    set_spell_level(([ "psion" : 8 ]));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS psychic scream");
    set_discipline("telepath");
    set_damage_desc("Area of effect mental damage or death on failed save");
    set_description("The telepath manifests a wave of overpowering psychic energy and releases it on all around them. The unfortunate souls caught in this wave suffer intense mental damage, or death on a failed will save.");
    mental_spell();
    set_save("will");
    splash_spell(3);
}

string query_cast_string()
{
    return "%^CYAN%^BOLD%^" + caster->QCN + " concentrates deeply and waves of psychic energy begin to crackle in the air.";
}

void spell_effect(int prof)
{
    object* foes, foe;
    int max;

    tell_object(caster, "%^BOLD%^CYAN%^You let loose a wave of psionic energy and a piercing scream fills the air..");
    tell_room(place, "%^BOLD%^CYAN%^" + caster->QCN + " releases a wave of psionic energy and a piercing scream fills the air.", caster);
    message("info", "%^BOLD%^You hear a horrible high-pitched scream.", nearbyRoom(place, 2));

    foes = target_selector();

    if (sizeof(foes)) {
        foreach(foe in foes)
        {
            if (combat_death_save(foe, 0)) {
                tell_object(foe, "%^YELLOW%^You mind is wracked with horrible pain but you survive!");
                foe->cause_typed_damage(foe, foe->return_target_limb(), sdamage, "mental");
                continue;
            }
            tell_object(foe, "%^BOLD%^%^RED%^You scream as your mind is shattered!");
            tell_room(place, "%^BOLD%^%^RED%^" + foe->QCN + " screams as " + foe->QP + " mind is shattered!", foe);
            foe->cause_typed_damage(foe, foe->return_target_limb(), foe->query_max_hp() * 2, "mental");
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
