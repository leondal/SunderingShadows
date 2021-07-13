/*
  _energy_conversion.c

  Travelling AOE and self buff.

  -- Tlaloc -- 4.5.20
*/

#include <magic.h>
#include <spell.h>

inherit SPELL;

int flag;

void create()
{
    ::create();

    set_author("tlaloc");
    set_spell_name("energy conversion");
    set_spell_level( ([ "psion" : 7 ]) );
    set_spell_sphere("psychokinesis");
    set_bonus_type( ({ "resistance", "deflection" }) );
    set_syntax("cast CLASS energy conversion");
    set_damage_desc("Force damage, +4 AC, +4 Fortitude Save");
    set_description("With this power, the psionicist alters their body to absorb the kinetic energy from enemy blows. After reaching a certain threshold, the energy is released as rays of light, striking all attackers. This is a nimbus family spell that won't work with other nimbuses.");

    traveling_aoe_spell(1);
}

int preSpell()
{
    if(caster->query_property("nimbus"))
    {
        tell_object(caster, "You are already affected by a nimbus effect.");
        return 0;
    }

    return 1;
}

void spell_effect(int prof)
{
    int duration;

    duration = ROUND_LENGTH * 10 * clevel;

    tell_object(caster, "%^CYAN%^BOLD%^You alter the makeup of your body to absorb the energy from enemy blows!");

    caster->set_property("spelled", this_object());
    caster->set_property("nimbus", 1);
    caster->set_property("added short", ({ "%^CYAN%^BOLD%^ (In an aura of energy)" }) );
    addSpellToCaster();
    spell_successful();
    caster->add_ac_bonus(4);
    caster->add_saving_bonus("fortitude", 4);

    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    call_out("room_check", ROUND_LENGTH);
}

void room_check()
{
    if(!objectp(caster) || !objectp(ENV(caster)))
    {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(ENV(caster));

    call_out("room_check",ROUND_LENGTH*2);
    return;
}

void execute_attack()
{
    object *attackers;

    if(!flag)
    {
        flag = 1;
        ::execute_attack();
        return;
    }

    if(!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }

    prepend_to_combat_cycle(place);

    attackers = filter_array(caster->query_attackers(),(:objectp($1):));
    attackers = filter_array(attackers,(:$1->is_living():));

    if(!sizeof(attackers))
        return;

    tell_object(caster, "%^CYAN%^BOLD%^The stored energy in your body unleashes on your foes!");
    tell_room(place, "%^CYAN%^BOLD%^", sprintf("The stored energy in %s's body unleashes on %s enemies!", caster->QCN, caster->query_possessive()), ({ caster }));

    foreach(object ob in attackers)
    {
        tell_object(ob, "%^BOLD%^You are hit with a burst of energy!");
        damage_targ(ob, "chest", sdamage, "force");
    }
}

void dest_effect()
{
    remove_call_out("room_check");

    if(objectp(caster))
    {
        tell_object(caster, "%^CYAN%^Your energy conversion fades.");
        caster->remove_property("nimbus");
        caster->add_ac_bonus(-4);
        caster->add_saving_bonus("fortitude", -4);
        caster->remove_property_value("added short", ({ "%^CYAN%^BOLD%^ (In an aura of energy)" }) );
    }

    ::dest_effect();
    objectp(this_object()) && this_object()->remove();
}
