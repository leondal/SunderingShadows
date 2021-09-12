/*
  _apopsi.c

  Deals Damage to an enemy psion's Power Points

  -- Tlaloc -- 4.3.20
*/

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int amount, old_amount;

void create()
{
    ::create();

    set_author("tlaloc");
    set_spell_name("apopsi");
    set_spell_level( ([ "psion" : 9 ]) );
    set_spell_sphere("telepathy");
    set_syntax("cast CLASS apopsi on TARGET");
    set_damage_desc("Destroys enemy power points or mental damage");
    set_description("With this power, a strong psion can dismantle an enemy's ability to use their psychic powers, resulting in severe damage to their power points pool. A failed save will result in the target's power pool being destroyed, cutting the psychic off from their powers. A successful save will result in half mental damage.");
    set_target_required(1);
    set_save("will");
}

int preSpell()
{
   if(target->query_property("apopsi"))
   {
      tell_object(caster,"Your target is already affected by this effect!");
      return 0;
   }

   return 1;
}


string query_cast_string()
{
    return "%^BOLD%^CYAN%^" + sprintf("%s concentrates on %s psionic powers", caster->QCN, caster->query_possessive());
}

void spell_effect(int prof)
{
    string myname, yourname;
    int mylevel;

    myname = caster->QCN;

    tell_object(caster, "%^CYAN%^BOLD%^You lash out at " + target->QCN + ", dismantling " + target->query_possessive() + " power reserves!");
    tell_object(target, "%^BOLD%^" + " lashes out at you, attempting to dismantle your power reserves!");
    say("%^BOLD%^" + sprintf("%s lashes out at %s with a mental assault!", caster->QCN, target->QCN), ({ caster, target }));

    if(!do_save(target, 0) && target->query_mp())
    {
        old_amount = target->query_max_mp();
        tell_object(caster, "%^BOLD%^Your psychic attack crushes your opponents' power reserves!");
        tell_object(target, "%^BOLD%^Your power reserves are diminished greatly!");
        target->set_property("apopsi", 1);  //Can only be used once per target on long cooldown
        target->set_max_mp(0);
        target->set_mp(0);
    }
    else
    {
        tell_object(caster, "%^BOLD%^Your psychic attack causes your opponent intense mental pain!");
        tell_object(target, "%^BOLD%^You suffer intense mental pain from " + caster->QCN + "'s psychic assault!");
        amount = sdamage / 2;
        damage_targ(target, target->return_target_limb(), amount, "mental");
    }

    spell_successful();
    spell_duration = (clevel / 2 + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    tell_object(caster, "%^BOLD%^You feel the Apopsi placed on your mind dissapate.");
    target->set_max_mp(old_amount);
    target->remove_property("apopsi");

    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
