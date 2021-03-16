//Meteor Swarm Reskin
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("avalanche");
    set_spell_level(([ "mage" : 7, "druid" : 8, "cleric" : 8 ]));
    set_domains("cold");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS avalanche on TARGET");
    set_damage_desc("1/2 cold damage | 1/2 bludgeoning damage in area");
    set_description("When the avalanche spell is cast, a mass of snow and ice crashes into the area, causing cold and bludgeoning "
        "damage to everyone present.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(1);
    set_target_required(1);
}


void spell_effect(int prof)
{
    object *foes, mycolor, element;
    int i;

    if(!objectp(caster) || !objectp(place))
    {
        dest_effect();
        return;
    }

    if(!present(target,place))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    element = "cold";

    tell_object(caster,"%^BOLD%^%^CYAN%^You finish your chant and a torrent of snow and ice slams into the area!");
    tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" finishes "+caster->QP+" chant and the a torrent of snow and ice slams into the area!",caster);
    tell_object(target,"%^CYAN%^Stones, ice and snow slam into you!");
    tell_room(place,"%^CYAN%^A torrent of ice and snow slams into "+target->QCN+" with tremendous force!",target);
    mycolor = "%^CYAN%^BOLD%^";

    spell_successful();
    spell_kill(target, caster);
    damage_targ(target, target->return_target_limb(), sdamage/2, element);
    damage_targ(target, target->return_target_limb(), sdamage/2, "bludgeoning");

    foes = target_selector();
    foes -= ({ target });
    foes -= ({ caster });

    if(!sizeof(foes))
    {
        dest_effect();
        return;
    }

    for (i=0;i<sizeof(foes);i++)
    {
        if(!objectp(foes[i])) { continue; }
        if(!spell_kill(target,caster)) { continue; }

        tell_object(foes[i], ""+mycolor+"An avalanche of ice, stone and snow slams into you!");
        tell_room(place, ""+mycolor+"An avalanche of ice, tone and snow slams into "+foes[i]->QCN+"!", foes[i]);

        damage_targ(foes[i], foes[i]->return_target_limb(), sdamage/2, element);
        damage_targ(foes[i], foes[i]->return_target_limb(), sdamage/2, "bludgeoning");
    }

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
