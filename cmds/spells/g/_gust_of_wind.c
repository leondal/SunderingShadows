// _gust_of_wind.c - 8/05

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_author("cythera");
    set_spell_name("gust of wind");
    set_spell_level(([ "mage" : 2, "monk" : 13, "druid":2, "oracle" : 2, "magus" : 2, "cleric" : 2 ]));
    set_domains("air");
    set_mystery("wind");
    set_spell_sphere("alteration");
    set_monk_way("way of the elements");
    set_syntax("cast CLASS gust of wind on TARGET");
    set_description("Waving a pair of specially prepared feathers in the air, the caster is able to generate a brief but "
        "intense gust of wind.  Using his left hand, the caster directs the damaging winds into their target.  The power of the "
        "gust of wind is dependant on the level of the caster.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([ "mage" : ([ "wing feather" : 2, ]), ]));
    set_immunities( ({ "spell_immunity"}) );
    set_save("reflex");
}


void spell_effect(int prof)
{
    if(!objectp(caster) || !objectp(target))
    {
        dest_effect();
        return;
    }

    place = environment(caster);

    tell_room(place, "%^CYAN%^"+caster->QCN+" holds out "+caster->QP+" "+
        "left hand and summons forth a breeze.",caster);
    tell_object(caster,"%^CYAN%^You hold out your left hand and summon"+
        " a breeze. %^RESET%^");

    if(environment(target) != place)
    {
        tell_object(caster,"%^BOLD%^Your target has left the area!%^RESET%^");
        dest_effect();
        return;
    }

    if(spell_type == "monk") { MAGIC_D->elemental_opportunist(caster, target); }

    spell_successful();

    tell_room(place,"%^CYAN%^A gust of intense winds issues forth "+
        "from "+caster->QCN+"'s left hand and slams into"+
        " "+target->QCN+".%^RESET%^",({caster,target}));
    tell_object(caster,"%^CYAN%^A gust of intense winds issues forth from "+
        "your left hand and slams into "+target->QCN+".%^RESET%^");
    tell_object(target,"%^CYAN%^A gust of intense winds issues forth from"+
        " "+caster->QCN+"'s left hand and slams into you.%^RESET%^");

    if(do_save(target)) { sdamage /= 2; }

    damage_targ(target,target->return_target_limb(),sdamage,"bludgeoning");

    dest_effect();
    return;
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
