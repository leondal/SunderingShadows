#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("dispel good");
    set_spell_level(([ "cleric" : 6 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS dispel good on TARGET");
    set_description("Dispel Good can only be cast by users of evil alignment and it only effects targets of good "
"alignment.  When cast at a target of the correct alignment, it will disrupt the harmonics of their soul and wrack their "
"body with pain, doing a significant amount of damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string() 
{
    tell_object(caster,"%^BOLD%^%^BLACK%^Holding your hand out,"+
		" you begins to chant in a dark sinister tone.");
    tell_room(place,"%^BOLD%^%^BLACK%^Holding "+caster->QP+" hand out,"+
		" "+caster->QCN+" begins to chant in a dark sinister tone.",({ caster }) );
  return"display";
}

int preSpell() 
{
    if (!target) 
    {
        tell_object(caster, "That is not here.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) 
{
    int damage;
    tell_room(place, "%^BOLD%^%^RED%^The air shimmers as "+caster->QCN+" completes"+
		" "+caster->QP+" chant.", caster);
    tell_object(caster, "%^BOLD%^%^RED%^Your chant builds in power, causing the "+
		"very air to shimmer.");

    if(target && !present(target,PLACE)) 
    { 
        dest_effect(); 
        return; 
    }
    if(target && !caster->ok_to_kill(target)) 
    {  
        dest_effect();
        return;
    }
    if(!is_evil(caster))
    {
        tell_object(caster, "Only those of evil alignment cast this spell.");
        dest_effect();
        return;
    }
    if(!is_good(target))
    {
        tell_object(caster, "This spell only affects those of good alignment.");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^%^RED%^"+target->QCN+" twists in pain as the spell"+
		" tears at the fiber of their being.");
    tell_object(target,"%^BOLD%^%^RED%^You can feel your very soul wracked with an"+
		" incredible pain as from the sinister tone of "+caster->QCN+"'s chant.");
    if(do_save(target,0))
        damage = roll_dice(clevel,6) / 2;
    else 
        damage = roll_dice(clevel,6);
    damage_targ(target,target->return_target_limb(),damage,"divine");
	spell_kill(target,caster);
    spell_successful();
    dest_effect();
    return;
}

void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}