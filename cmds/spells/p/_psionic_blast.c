/*
  _psionic_blast.c

  AOE Stun

  -- Tlaloc -- 3.31.20
*/

#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();

    set_spell_name("psionic blast");
    set_spell_level( ([ "psion" : 3 ]) );
    set_spell_sphere("telepathy");
    mental_spell();
    set_syntax("cast CLASS psionic blast");
    set_description("The air ripples with the force of your mental attack, which blasts the minds of all creatures in range. Psionic blast stuns all affected creatures for 2d4 rounds.");
    set_save("will");
    splash_spell(3);
}

string query_cast_string()
{
    return "%^CYAN" + sprintf("%s concentrates on %s psionic powers.", caster->QCN, caster->query_possessive());
}

void spell_effect(int prof)
{
    object *victims;
    string myname, yourname;

    myname = caster->QCN;

    tell_object(caster, "%^CYAN%^You place your fingers to the side of your head and bring forth a blast of psychic energy!%^RESET%^");
    tell_room(place, "%^CYAN%^" + sprintf("%s places %s fingers to the side of %s head and concentrates!", myname, caster->query_possessive(), caster->query_possessive()) + "%^RESET%^", ({ caster }));

    victims = target_selector();

    if(!sizeof(victims))
    {
        tell_object(caster, "You release a wave of psionic energy, but nothing else happens...");
        this_object()->remove();
        return;
    }

    tell_object(caster, "%^CYAN%^You release a blast of psychic energy into the area!");
    tell_room(place, caster->QCN + " releases a blast of psychic energy into the area!", ({ caster }));

    foreach(object ob in victims)
    {
        if(do_save(ob, 0))
            tell_object(ob, "You manage to shrug off the psionic blast.");
        else
        {
            tell_object(ob, "%^BOLD%^The psionic energy slams into you, leaving you stunned!");
            tell_object(caster, "%^BOLD%^The psionic energy slams into " + ob->QCN + ", leaving them stunned!");
            ob->set_paralyzed(roll_dice(2,4) * 8, "%^BOLD%^You are stunned by the psychic blast!");
        }
        spell_kill(ob,caster);
    }

    spell_successful();
    dest_effect();
}
