//Fire Storm coded by Bane//
//removed from druids for balance after discussion with Ts and players ~Circe~ 8/5/13

#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int time,first_execute;


void create()
{
    ::create();
    set_spell_name("fire storm");
    set_spell_level(([ "cleric" : 7, "druid" : 7, "monk" : 17, "oracle" : 7, "warlock" : 3 ]));
    set_mystery(({"flame","apocalypse"}));
    set_spell_sphere("invocation_evocation");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS fire storm");
    set_damage_desc("fire");
    set_description("When the fire storm spell is cast, the whole area is shot through with sheets of roaring flame.  Any "
        "target in the area of effect takes damage every round while the spell is in effect, but does not damage the caster.  "
        "This spell does not work in conjunction with the monsoon priest spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    aoe_spell(1);
    set_aoe_message("%^BOLD%^%^RED%^(ablaze with sheets of flame)%^RESET%^");
    set_feats_required(([ "warlock" : "infernal practitioner"]));
}

void spell_effect(int prof)
{
    tell_object(caster,"%^RED%^You wave your hands around summoning the fury of the elemental plane of fire!");
    tell_room(place,"%^RED%^"+caster->QCN+" waves "+caster->QP+" hands around summoning the fury of the elemental plane of fire!",caster);
    place->set_property("spelled", ({TO}) );
    caster->set_property("spelled",({TO}));
    time = 0;
    addSpellToCaster();
    spell_successful();
    execute_attack();
}


void execute_attack()
{
    string target_limb;
    object *foes;
    int i, damage;

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

    if (!first_execute)
    {
        first_execute++;
        ::execute_attack();
        return;
    }

    foes = target_selector();

    if (time > clevel * 2 || !present(caster,place))
    {
        dest_effect();
        return;
    }

    if (!present(caster,place))
    {
        dest_effect();
        return;
    }

    if(spell_type == "monk" && sizeof(foes)) { MAGIC_D->elemental_opportunist(caster, foes[0]); }

    damage = sdamage;

    tell_room(place,"%^BOLD%^RED%^Sheets of flame rage across the area incinerating everything in sight!");

    for(i=0;sizeof(foes),i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) continue;
        if(foes[i] == caster) continue;
        if(!present(foes[i],place)) continue;
        if(interactive(foes[i]) && foes[i]->query_level() < 6) continue;
        if(do_save(foes[i],0))
        {
            damage = damage/2;
        }

        target_limb = foes[i]->return_target_limb();
        damage_targ(foes[i], target_limb, damage,"fire");
        if(present(caster, place))
        {
            if (objectp(foes[i])) spell_kill(foes[i],caster);
        }
    }

    time++;

    if (present(caster,place) && !caster->query_unconscious())
    {
        place->addObjectToCombatCycle(TO,1);
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
        tell_room(place,"%^BOLD%^%^RED%^The fire storm weakens and dissipates.");
        place->remove_property_value("spelled", ({TO}) );
    }
    if(objectp(caster))
    {
        caster->remove_property_value("spelled", ({TO}) );
    }
    remove_call_out("do_storm");
    ::dest_effect();
    if(objectp(TO)) { TO->remove(); }

}
