/*
  _shrapnel_burst.c

  Level 5 Multi-Target.

  -- Tlaloc -- 4.10.20
*/

#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();

    set_author("tlaloc");
    set_spell_name("shrapnel burst");
    set_spell_level( ([ "psion" : 5, "psywarrior" : 4 ]) );
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS shrapnel burst on TARGET");
    set_damage_desc("Piercing Damage to all attackers");
    set_description("You emit a burst of crystalline shrapnel, dealing piercing damage to all attackers.");
    set_save("reflex");
    set_target_required(1);
    splash_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^CYAN%^" + sprintf("%s concentrates on %s psionic powers", caster->QCN, caster->query_possessive());
}

void spell_effect(int prof)
{
    object *attackers, room;
    int damage;

    attackers = target_selector();
    attackers += ({ target });
    attackers = distinct_array(attackers);
    room = environment(caster);

    if(!sizeof(attackers))
    {
        tell_object(caster, "%^BOLD%^Your crystal shrapnel blasts out from you, but hits nothing!");
        return;
    }

    tell_object(caster, "%^BOLD%^You focus your psychic energies and crystalline shrapnel explodes outwards from you!");
    room && tell_room(room, sprintf("%s focuses on %s psychic energies and crystalline shrapnel explodes outwards from %s!",caster->QCN,caster->query_possessive(),caster->query_subjective()), ({ caster }));

    damage = sdamage;

    foreach(object ob in attackers)
    {
        if(do_save(target, 0))
            damage /= 2;

        tell_object(caster, "%^BOLD%^Your crystal shrapnel tears into " + ob->QCN + "!");
        tell_object(ob, "%^BOLD%^The crystal shrapnel tears into you!");
        room && tell_room(room, "%^BOLD%^The crystal shrapnel tears into " + ob->QCN + "!", ({ ob, caster }));
        damage_targ(ob, "torso", damage, "piercing");
        spell_kill(ob, caster);
    }

    spell_successful();
    dest_effect();
}
