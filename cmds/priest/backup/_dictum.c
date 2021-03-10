#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

create() 
{
    ::create();
    set_spell_name("dictum");
    set_spell_level(7);
    set_spell_type("priest");
    set_spell_sphere("combat");
    set_spell_domain("vigilance");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    set_target_required(1);
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"You need a target for this spell.");
        return 0;
    }
    return 1;
}

string query_cast_string() 
{
    tell_object(caster,"%^BOLD%^%^BLUE%^You weave your arms in a methodical"+
        " fashion, your voice resonating with an even tempo as you begin "+
        "to intone an orderly prayer..");
    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" weaves "+caster->QP+" "+
        "arms in a methodical fashion, "+caster->QP+" voice resonating with"+
        " an even tempo as "+caster->QS+" intones an orderly prayer.",caster);
    return "display";
}

spell_effect(int prof) 
{
    int damage;
    if(!present(target,place))
    {
        tell_object(caster, "Your target has left the area.");
        dest_effect();
        return;
    }
     spell_successful();

    tell_object(caster,"%^BOLD%^%^BLUE%^You send your hands out towards"+
		" "+target->QCN+", hurling a magical bolt of pure energy at "+
		""+target->QO+"!");
    tell_object(target,"%^BOLD%^%^BLUE%^"+caster->QCN+" sends "+caster->QP+" "+
		"hands towards you, hurling a bolt of pure energy at you!");
    tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+" sends "+caster->QP+" hands"+
		" towards "+target->QCN+", hurling a bolt of pure energy at"+
		" "+target->QO+"!",({caster,target}));

/*
    if(!SAVING_D->saving_throw(target,"spell",0))
*/
    if(!do_save(target))
    {
        tell_object(caster,"%^BOLD%^%^BLUE%^The bolt of energy slams full force "+
		    "into "+target->QCN+" doing serious damage!");
        tell_object(target,"%^BOLD%^%^BLUE%^The bolt of energy hits you full "+
		    "force, doing serious damage!");
        tell_room(place,"%^BOLD%^%^BLUE%^"+caster->QCN+"'s bolt of energy hits"+
		    " "+target->QCN+" full force, doing serious damage!",({caster,target}));
        damage = roll_dice(clevel,6);
    }
    else
    {
        tell_object(caster,"%^BLUE%^"+target->QCN+"is able to dodge to the side "+
		    "at the last moment, avoiding the worst of the damage from the magical bolt!");
        tell_object(target,"%^BLUE%^You are able to dodge to the side at the last"+
		    " instant, avoiding the full force of "+caster->QCN+"'s magical bolt!");
        tell_room(place,"%^BLUE%^"+target->QCN+" is able to dodge to the side at the"+
		    " last instant, avoiding the full force of "+caster->QCN+"'s magical "+
		    "bolt!",({target,caster}));
        damage = roll_dice(clevel,6)/2;
    }
    damage_targ(target, target->return_target_limb(), damage, "divine");
    spell_kill(target,caster);
    dest_effect();
}

void dest_effect() 
{
    ::dest_effect();
    TO->remove();
}

int help() 
{
    write(
@EndText
Spell  : Dictum
Level  : 7th Level
Sphere : Combat
Domain : Vigilance
Syntax : chant dictum on <target>

This spell will hurl a bolt of magical force at the target.
If the target fails their save, they will be hit full force
with the magical power of the bolt, doing tremendous damage.
Otherwise they are able to avoid the full impact and suffer
only a grazing blow.

EndText
);
    return 1;
}
