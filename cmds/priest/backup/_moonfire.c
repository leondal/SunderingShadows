// Moonfire
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create() 
{
    ::create();
    set_author("ares");
    set_spell_name("moonfire");
    set_spell_level(8);
    set_spell_type("priest");
    set_spell_domain("moon");
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() 
{
	tell_object(caster,"%^BOLD%^As you begin to chant your prayer,"+
		" you raise your hands up to the heavens.");
	tell_room(place,"%^BOLD%^"+caster->QCN+" raises "+
		""+caster->QP+" hands up to the heavens as "+caster->QS+" "+
		"begins to chant.",caster);
    return "display";
}

void spell_effect(int prof) 
{
    object *attackers;
    int i,damage;
    attackers = caster->query_attackers();
    attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
    if(!sizeof(attackers))
    {
        tell_object(caster,"%^BOLD%^The area is lit with a radiant moonlight, but "
            "the spell has no other effect.");
        dest_effect();
        return;
    }
    tell_object(caster,"%^BOLD%^An orb of fiery white moonlight"+
		" forms in your hands.  You toss the orb into the air, "+
		"causing it to burst open, bathing the area in moonlight!");
    tell_room(place,"%^BOLD%^An orb of fiery white moonlight forms in"+
		" "+caster->QCN+"'s hands.  The orb bursts opens as "+caster->QS+""+
		" tosses it into the air, bathing the area in moonlight!");
    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i])) { continue; }
        tell_object(attackers[i],"%^BOLD%^The moonlight burns as it strikes you, seering "
            "your skin!");
        damage = roll_dice(clevel,8);
        if(SAVING_D->saving_throw(attackers[i],"spell",0)) { damage = damage/2; }
        if(!SAVING_D->saving_throw(attackers[i],"breath_weapon",0))
        {
            tell_object(attackers[i],"%^BOLD%^The light stings your eyes, blistering them and "
                "making it impossible to see!");
            attackers[i]->set_temporary_blinded(roll_dice(1,6));
        }
        if(!SAVING_D->saving_throw(attackers[i],"petrification_polymorph",0))
        {
            tell_object(attackers[i],"%^BOLD%^The searing moonlight wrenches your muscles "
                "in place, rendering you unable to move!");
            attackers[i]->set_paralyzed(roll_dice(2,6),"%^BOLD%^%^CYAN%^You are unable to move!");
        }
        spell_kill(attackers[i],caster);
        damage_targ(attackers[i], attackers[i]->return_target_limb(), damage, "divine");
    }
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
Spell  : Moonfire
Level  : 8th Level
Domain : Moon
Syntax : chant moonfire

This spell will blanket the area with a radiant fiery
moonlight.  All enemies caught in the area must save
or risk being blinded or stunned.  Those who pass 
their saves still take a slight amount of damage from
the moonlight.

HELP
);
    return 1;
}
