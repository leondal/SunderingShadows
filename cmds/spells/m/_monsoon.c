//Monsoon - Istishian fire storm alternative, coded by Nienne, 05/05//
//changed to general priest spell for a fire storm ascetic alternative. Nienne, 05/07
//removed from druids for balance after discussion with Ts and players ~Circe~ 8/5/13

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int time;


void create()
{
    ::create();
    set_spell_name("monsoon");
    set_spell_level(([ "mage" : 8, "monk" : 17]));
    set_spell_sphere("conjuration_summoning");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS monsoon");
    set_description("When the monsoon spell is cast, the surrounding area is engulfed in a raging storm of water.  Any "
        "target in the area of effect takes damage every round while the spell is in effect, but does not damage the caster.  "
        "This spell does not work in conjunction with the fire storm spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
}



void spell_effect(int prof)
{
    tell_object(caster,"%^BOLD%^%^CYAN%^You wave your hands around summoning the fury of a watery storm from the skies above!");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" waves "+caster->QP+" hands around summoning the fury of a watery storm from the skies above!",caster);
    place->set_property("spelled", ({TO}) );
    time = 0;
    addSpellToCaster();
    spell_successful();
    call_out("do_storm",5);
}


void do_storm()
{
    object *foes;
    string target_limb;
    int i,damage;

    if(!objectp(place))
    {
        dest_effect();
        return;
    }

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    foes = target_selector();

    if(time > clevel * 2 || !present(caster,place))
    {
        dest_effect();
        return;
    }

    if(spell_type == "monk" && sizeof(foes)) { MAGIC_D->elemental_opportunist(caster, foes[0]); }

    define_base_damage(0); // lazy re-roll
    damage = sdamage;

    tell_room(place,"%^BOLD%^CYAN%^A raging storm of water and winds roars through the area damaging everything in sight!");
    foes -= ({caster});
    for (i=0;sizeof(foes),i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) continue;
        if(foes[i] == caster) continue;
        if(!present(foes[i],place)) continue;
        if (interactive(foes[i]) && foes[i]->query_level() < 6) continue;

        if(do_save(foes[i],0)) { damage = damage/2; }
        target_limb = foes[i]->return_target_limb();
        damage_targ(foes[i], target_limb, damage,"cold");
        if(present(caster, place))
        {
            if (objectp(foes[i])) spell_kill(foes[i],caster);
        }
    }

    time++;

    if(present(caster,place) && !caster->query_unconscious())
    {
        call_out("do_storm",10);
        return;
    }
    else
    {
        dest_effect();
        return;
    }
}


void dest_effect()
{
    if(objectp(place))
    {
        tell_room(place,"%^BOLD%^%^CYAN%^The monsoon weakens and dissipates.");
        place->remove_property_value("spelled", ({TO}) );
    }
    if(objectp(caster))
    {
        caster->remove_property_value("spelled", ({TO}) );
    }
    remove_call_out("do_storm");
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
