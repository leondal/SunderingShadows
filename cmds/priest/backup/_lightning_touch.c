// lightning touch based on Searing
//Light by saide - 8/05

#include <priest.h>
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create() 
{
    ::create();
    set_spell_name("lightning touch");
    set_author("cythera");
    set_spell_level(2);
    set_spell_type("priest");
    set_spell_sphere("weather");
       set_spell_domain("storms");
    set_target_required(1);
    set_somatic_comp();
    set_verbal_comp();
    set_immunities( ({ "spell_immunity"}) );
    set_xp_bonus(20);
}

int preSpell()
{
    if(!objectp(target))
    {
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_room(place, "%^YELLOW%^Crackling bolts of lightning surrounds "+caster->QCN+"'s"+
		" hand!",caster);    
    tell_object(caster,"%^YELLOW%^Crackling bolts of lightning surround"+
		" your hand!%^RESET%^");
    return "display";
}

spell_effect(int prof) 
{
    int effect, bonus;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if(!present(target,place))
    {
        tell_object(caster,"%^BOLD%^Your target has left the area!%^RESET%^");
        dest_effect();
        return;
    }

    if (roll_dice(1,20) < caster->Thaco(0,target,0)) 
    {
	    tell_object(caster,"%^YELLOW%^The crackling lightning around your hand"+
		    " flashes and fades away as"+
		    " you fail to touch "+target->QCN+".%^RESET%^");
     	tell_room(place,"%^YELLOW%^The crackling lightning around"+
            " "+caster->QCN+"'s hand flashes as it disperses after"+
		    " "+caster->QS+" fails to touch "+target->QCN+"."+
		    "%^RESET%^",({target,caster}));
        tell_object(target,"%^YELLOW%^The crimson flames around "+caster->QCN+"'s"+
		    " hand fades away as "+caster->QS+" fails to touch you!%^RESET%^");
        dest_effect();
        return;
    }

    tell_room(place,"%^YELLOW%^Crackling arcs of lightning leap from"+
        " "+caster->QCN+"'s hand and into "+target->QCN+"."+
        "%^RESET%^",({caster,target}));
    tell_object(caster,"%^YELLOW%^Crackling arcs of lightning leap from"+
        " your hand and into "+target->QCN+".%^RESET%^");
    tell_object(target,"%^YELLOW%^Crackling arcs of lightning leap from"+
        " "+caster->QCN+"'s hand"+
        " and into you!%^RESET%^");

    effect = (roll_dice(1 + (clevel),4));

 	if(SAVING_D->saving_throw(target,"spell"))
    {
        effect = effect / 2;
    }
    damage_targ(target,target->return_target_limb(),effect);
    spell_kill(target,caster);
    spell_successful();
    dest_effect();   

}

void dest_effect() 
{
    ::dest_effect();
    TO->remove();
}

int help(string str) 
{
    write(
@HELP
Spell  : Lightning Touch
Level  : 2nd Level
Sphere : Weather
Domain : Storm
Syntax : chant lightning touch on <target>

Wrapping their hand with crackling bolts of lightning, 
with this spell the caster tries to deliever a shocking 
attack onto a foe.  If the caster fails to touch the 
target, the lighting dispurses into a flashy, but 
harmless effect.
HELP
);
    return 1;
}
