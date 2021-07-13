// fortune fate
// Works similar to contingency, except it triggers a random heal spell
// from cure light wounds up to heal automatically when the target falls
// below 25% health -Ares
//Adjusted to have a higher percentage chance for the higher level
//heals in rebalancing the domains.  ~Circe~ 4/24/08

#include <std.h>

inherit SPELL;

int cast_level;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("alter fate");
    set_spell_level(([ "psion" : 8 ]));
    set_spell_sphere("clairsentience");
    set_discipline("seer");
    set_syntax("cast CLASS alter fate on TARGET");
    set_description("This spell will cause the fates to smile on the target.  When cast, it will activate a healing spell "
"that will remain in reserve up until the target falls below 25% of their maximum health.  When that point is reached, a "
"random healing spell is cast on the target.");
    set_verbal_comp();
    set_target_required(1);
    set_heart_beat(1);
	set_helpful_spell(1);
}

void random_heal()
{
    int rand;
    if(!objectp(target)) { dest_effect(); return; }

    rand = 100 + clevel; // slightly weighted to give higher levels a higher chance of stronger 				 //spells
    switch(roll_dice(1,rand))
    {
   	case 1..35:
        new("/cmds/spells/c/_cure_serious_wounds.c")->use_spell(target,target,cast_level,100,"cleric");
        break;
    case 36..75:
        new("/cmds/spells/c/_cure_critical_wounds.c")->use_spell(target,target,cast_level,100,"cleric");
        break;
    default:
        new("/cmds/spells/h/_heal.c")->use_spell(target,target,cast_level,100,"cleric");
        break;
    }
    dest_effect();
    return;
}

void heart_beat()
{
   	int hp,max_hp,mookie;

    if(!objectp(target) || !objectp(caster)) { dest_effect(); return; }

    hp     = (int)target->query_hp();
    max_hp = (int)target->query_max_hp();
    mookie = (max_hp * 25) / 100;
    if(hp < mookie)
    {
    tell_object(target,"%^YELLOW%^You feel your fate change on your behalf!");
        random_heal();
        dest_effect();
    }
    return;
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    if(target->query_property("fortune fate"))
    {
        tell_object(caster,"That target is already protected by the altering of fate.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster,"%^ORANGE%^As you begin to chant a lilting prayer,"+
       " a golden aura bathes your fingers.");
    tell_room(place,"%^ORANGE%^A golden aura bathes "+caster->QCN+"'s "+
        "fingers as "+caster->QS+" begins to chant a lilting prayer.",caster);
    return "display";
}

void spell_effect(int prof)
{
    if(!present(target,place))
    {
        tell_object(caster,"Your target has left the area.");
        dest_effect();
        return;
    }

	if(target == caster)
    {
        tell_room(place,"%^YELLOW%^A golden aura surrounds"+
            " "+caster->QCN+", before it fades into "+caster->QP+" skin.",target);
       tell_object(target,"%^YELLOW%^The golden aura spreads to surround"+
            " you, before it fades into your skin.");
    }
    else
    {
        tell_room(place,"%^ORANGE%^"+caster->QCN+" bathes "+target->QCN+" in"+
            " a golden aura, that fades into "+target->QP+" skin.",caster);
        tell_object(caster,"Bathe "+target->QCN+" in the golden aura, altering"+
            " "+target->QP+" fate.");
        tell_object(target, "%^YELLOW%^"+caster->QCN+" bathes you in the golden"+
            " aura, before it sinks into your skin.");
    }

    cast_level = clevel;
    spell_successful();
    addSpellToCaster();
	if(objectp(target))
	{
		target->set_property("spelled",({TO}));
		target->set_property("fortune fate",1);
	}
}

void dest_effect()
{
	if(!objectp(TO)) return;
	if(objectp(target))
	{
		tell_object(target,"%^ORANGE%^You feel more vulnerable now that the fates"+
		" no longer smile on you.");
		target->remove_property("fortune fate");
	}
    	::dest_effect();
      if(objectp(TO)) TO->remove();

}
