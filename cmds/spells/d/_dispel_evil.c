#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_author("ares");
    set_spell_name("dispel evil");
    set_spell_level(([ "cleric" : 6 ]));
    set_domains("good");
    set_spell_sphere("combat");
    set_syntax("cast CLASS dispel evil on TARGET");
    set_description("Dispel Evil can only be cast by users of good alignment and it only effects targets of evil "
"alignment.  When cast at a target of the correct alignment, it will disrupt the harmonics of their soul and wrack their "
"body with pain, doing a significant amount of damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string() 
{
    tell_object(caster,"%^BOLD%^%^WHITE%^Holding your hand out,"+
		" you begins to chant in a pure flowing tone.");
    tell_room(place,"%^BOLD%^%^WHITE%^Holding "+caster->QP+" hand out,"+
		" "+caster->QCN+" begins to chant in a pure flowing tone.",caster );
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
    tell_room(place, "%^BOLD%^The air shimmers as "+caster->QCN+" "+
		"completes "+caster->QCN+" chant.", caster);
    tell_object(caster, "%^BOLD%^Your chant builds in power, causing the very air to shimmer.");

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
    if(!is_good(caster))
    {
        tell_object(caster, "Only those of good alignment may use this spell.");
        dest_effect();
        return;
    }
    if(!is_evil(target))
    {
        tell_object(caster, "This spell only affects those of evil alignment.");
        dest_effect();
        return;
    }
    tell_object(caster,"%^YELLOW%^"+target->QCN+" twists in pain as the prayer tears at"+
		" the fiber of "+target->QP+" being.");
    tell_object(target,"You can feel your very soul wracked with an incredible pain "
        "from the purity of "+caster->QCN+"'s chant.");
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
