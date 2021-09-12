/*
  _reality_revision.c

  Upgraded version of bend reality for shapers.

  -- Tlaloc -- 4.4.20
*/

#include <std.h>
#include <daemons.h>

#define MAX_PSI 7
#define MAX_DIS 6
#define MAX_WAR 5

#define DELAY 180

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("reality revision");
    set_spell_level(([ "psion" : 9 ]));
    set_spell_sphere("metacreativity");
    set_discipline("shaper");
    set_syntax("cast CLASS reality revision on SPELL_NAME [on SPELL_ARGS]");
    set_description("You use your vast psionic powers to revise reality around you, allowing you to cast any psion power of level 7 or below, any discipline-specific psion power of level 6 or below, OR any psywarrior spell of level 5 or below. Example: <cast psion reality revision on breath of life on corpse>. You must spend your psionic focus to cast this spell.");
    set_arg_needed(1);
    set_silent_casting(1);
}

int preSpell()
{
    int max_level;
    int slevel, psi_level, war_level;
    object spell_to_cast;
    string spl, sargs, disc;
    string splfn, ctype;
    
    /*
    if(caster->cooldown("reality revision"))
    {
        tell_object(caster, "You can't use reality revision yet.");
        return 0;
    }
    */

    if(!stringp(arg))
    {
        tell_object(caster,"You must provide arguments to this spell!");
        return 0;
    }

    if(sscanf(arg, "%s on %s", spl, sargs)!=2)
        spl = arg;

    if(!stringp(spl))
    {
        tell_object(caster,"You must provide another spell to this spell!");
        return 0;
    }

    spl = replace_string(spl, " ", "_");
    splfn = "/cmds/spells/"+spl[0..0]+"/_"+spl+".c";

    if(!file_exists(splfn))
        {
        tell_object(TP,"Either that spell does not exist, or you do not know it!");
        return 0;
    }
    if(!sargs || sargs == "" || !stringp(sargs))
        sargs = "";
    spell_to_cast = new(splfn);

    psi_level = spell_to_cast->query_spell_level("psion");
    war_level = spell_to_cast->query_spell_level("psywarrior");

    //If it's not a spell that exists for psion or psywarrior, error message.
    if(!psi_level && !war_level)
    {
        tell_object(this_player(), "You may only cast psywarrior or psion spells with this power!");
        return 0;
    }

    max_level = MAX_PSI;

    if(spell_to_cast->query_discipline() && spell_to_cast->query_discipline() != "me")
        if(caster->query_discipline() != spell_to_cast->query_discipline())
            max_level = MAX_DIS;

    if(psi_level && psi_level <= max_level)
    {
        ctype = "psion";
        slevel = psi_level;
    }
    else if(war_level && war_level <= MAX_WAR)
    {
        ctype = "psywarrior";
        slevel = war_level;
    }
    else
    {
        tell_object(this_player(),"This spell is too powerful for bend reality!");
        return 0;
    }

    if(!USER_D->spend_pool(caster, 1, "focus"))
    {
        tell_object(caster, "You must spend your focus to cast reality revision.");
        return 0;
    }

    tell_object(caster, "%^BOLD%^%^CYAN%^You c%^RESET%^%^CYAN%^o%^BOLD%^ncentrate d%^RESET%^%^CYAN%^e%^BOLD%^eply and b%^RESET%^%^CYAN%^e%^BOLD%^nd the v%^RESET%^%^CYAN%^e%^BOLD%^ry f%^RESET%^%^CYAN%^a%^BOLD%^bric of r%^RESET%^%^CYAN%^e%^BOLD%^ality a%^RESET%^%^CYAN%^r%^BOLD%^ound y%^RESET%^%^CYAN%^o%^BOLD%^u!%^RESET%^");
    tell_room(place,"%^CYAN%^BOLD%^"+caster->QCN+" %^BOLD%^%^CYAN%^c%^RESET%^%^CYAN%^o%^BOLD%^ncentrates d%^RESET%^%^CYAN%^e%^BOLD%^eply and b%^RESET%^%^CYAN%^e%^BOLD%^nds the v%^RESET%^%^CYAN%^e%^BOLD%^ry f%^RESET%^%^CYAN%^a%^BOLD%^bric of r%^RESET%^%^CYAN%^e%^BOLD%^ality a%^RESET%^%^CYAN%^r%^BOLD%^ound " + caster->query_objective(), ({ caster }));

    spell_successful();

    spell_to_cast->use_spell(TP,sargs,clevel,100,ctype);
    //caster->add_cooldown("reality revision", DELAY);
    return 1;

}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
