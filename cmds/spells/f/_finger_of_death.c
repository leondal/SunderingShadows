//_finger_of_death.c
#include <std.h>
#include <daemons.h>
#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("finger of death");
    set_spell_level(([ "mage" : 7, "cleric" : 8 ]));
    set_domains("evil");
    evil_spell(1);
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS finger of death on TARGET");
    set_damage_desc("negative energy");
    set_description("Finger of death pulls the darkness in close around the caster as the caster attempts to free the soul of the target from its coil, be they alive or undead, effectively killing them. Target able to withstand the spell will receive standard damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("fort");
}

string query_cast_string()
{
    return "%^BOLD%^%^BLACK%^" + caster->QCN + "'s face goes blank, then white. You feel eerie cold flowing through the area.%^RESET%^";
}

void spell_effect(int prof)
{
    int x;

    if (!objectp(target) || !objectp(caster)) {
        if (objectp(TO)) {
            TO->remove();
        }
        return;
    }

    define_base_damage(-5);
    place = environment(caster);

    spell_successful();

    if (combat_death_save(target, 4)) {
        tell_object(target, "%^BOLD%^The struggle is won, yet at a price.");
        tell_room(place, "%^BOLD%^The soul survives, yet at a price.", target);
        damage_targ(target, target->return_target_limb(), sdamage, "negative energy");
        target->set_property("no_slay", ({ caster->query_name() }));
    } else {
        tell_room(place, "%^BOLD%^%^BLUE%^The soul is cleaved from its body and left to drift homelessly!");
        tell_room(place, "%^BOLD%^%^MAGENTA%^The lifeless, soulless, body of " + target->QCN + " drops to the ground!", target);
        tell_object(target, "%^BOLD%^%^RED%^You sense a few last things as your soul is ripped from you body!\n");
        damage_targ(target, target->return_target_limb(), target->query_max_hp() * 2, "negative energy");
        target->die();
    }
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
