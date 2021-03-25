/*
  _ego_whip.c

  Does 1d4 damage to mental stats

  -- Tlaloc -- 4.3.20
*/

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int amount;

void create()
{
    ::create();

    set_author("tlaloc");
    set_spell_name("ego whip");
    set_spell_level( ([ "psion" : 2 ]) );
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS ego whip on TARGET");
    set_damage_desc("1d8 damage to CHA for 3 rounds. Daze on failed save");
    set_description("Your rapid mental lashings assault the ego of your enemy, debilitating its confidence. The target takes 1d8 points of Charisma damage. A target that fails its save is also dazed for 3 rounds.");
    set_target_required(1);
    set_save("will");
}

int preSpell()
{
   if(target->query_property("idiocied"))
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
    
    spell_successful();

    tell_object(caster, "%^CYAN%^BOLD%^You lash out at " + target->QCN + ", assaulting " + target->query_possessive() + " ego!");
    tell_object(target, "%^BOLD%^" + " lashes out at you, assaulting your ego!");
    say("%^BOLD%^" + sprintf("%s lashes out at %s with a mental assault!", caster->QCN, target->QCN), ({ caster, target }));

    amount = roll_dice(1, 8);

    target->set_property("idiocied", 1);
    target->set_stat_bonus(-amount);
    spell_kill(target, caster);

    if(!do_save(target, 0))
        target->set_paralyzed(3, "%^BOLD%^You are dazed by the mental attack!");
    
    call_out("dest_effect", 3);
}

void dest_effect()
{
    tell_object(caster, "%^MAGENTA%^BOLD%^The shadows subsuming your body seem to dissapate.");
    target->remove_property("idiocied");
    target->set_stat_bonus("charisma", amount);

    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
