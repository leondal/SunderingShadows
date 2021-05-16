/*
  _dissolving_touch.c

  Dissolving Touch from PF SRD.
  Does acid damage with touch attack.

  -- Tlaloc --
*/

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("dissolving touch");
    set_spell_level( ([ "psywarrior" : 2 ]) );
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS dissolving touch on TARGET");
    set_damage_desc("Successful touch attack deals acid damage.");
    set_description("Your touch becomes corrosive and bubbling moisture visibly oozes from your hand. A successful touch attack does acid damage to the target. You are immune to your own acid.");
    set_immunities("acid");
    set_target_required(1);
}

string query_cast_string()
{
    return "%^GREEN%^BOLD%^Bubbling moisture oozes from " + caster->QCN + "'s hand as " +
           caster->QS + " spreads " + caster->QP + " hands.%^RESET%^";
}

void spell_effect(int prof)
{
    object enemy;
    int roll;
    string pname, ename;
    
    target && enemy = target;

    if(!enemy)
        enemy = caster->query_current_attacker();

    if(!enemy)
    {
        tell_object(caster, "That is not a valid target.");
        return;
    }

    roll = BONUS_D->process_hit(caster, enemy, 1, 0, 0, 1);
    ename = enemy->query_cap_name();
    pname = caster->query_cap_name();

    if(roll < 1)
    {
        tell_object(caster, "%^BOLD%^You reach out with your acidic hand, but miss!%^RESET%^");
        tell_room(place, "%^BOLD%^" + pname + " reaches out with " + caster->query_possessive() + " acidic hand, but misses " + ename + "!%^RESET%^", ({ caster }));
        this_object()->remove();
    }

    spell_successful();
    tell_object(caster, "%^BOLD%^GREEN%^You reach out and touch " + ename +", dissolving their flesh!%^RESET%^");
    tell_room(place, "%^BOLD%^GREEN%^" + pname + " reaches out and touches " + ename + ", dissolving their flesh with acid!%^RESET%^", ({ caster }));

    damage_targ(enemy, enemy->return_target_limb(), sdamage, "acid");
    dest_effect();
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
