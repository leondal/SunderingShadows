#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("tar pool");
    set_spell_level(([ "druid" : 6, "mage" : 6 ]));
    set_spell_sphere("alteration");
    set_spell_domain("sun");
    set_syntax("cast CLASS tar pool");
    set_damage_desc("fire, trips targets");
    set_description("You convert a layer of the ground to hot tar. Creatures in the area when the tar appears take fire damage and must succeed at a reflex save or become entangled. Successful save will allow enemies to jump out of the pool before tar becomes viscous, but the heat will still harm them.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    splash_spell(3);
}

string query_cast_string()
{
	tell_object(caster,"%^BOLD%^%^BLACK%^You can feel heat raising of the ground as you chant.");
	tell_room(place,"%^BOLD%^%^BLACK%^You feel heat raising of the ground as"+caster->QS+" chants.",caster);
	return "display";
}

void spell_effect(int prof)
{
    object *attackers;
    int i,dmg;
    attackers = target_selector();

    tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" utters a quick invocation and the ground under "+caster->QP+" enemies converts into hot layer of tar!%^RESET%^");
    if(!sizeof(attackers))
    {
        dest_effect();
        return;
    }
    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i]))
            continue;

        dmg = sdamage;
        tell_object(attackers[i],"%^BOLD%^Heat raising of the tar burns you!%^RESET%^");
        damage_targ(attackers[i],attackers[i]->return_target_limb(),dmg,"fire");
        if(!do_save(attackers[i],0))
        {

            attackers[i]->set_tripped(roll_dice(1,4));
            tell_object(attackers[i],"%^BOLD%^%^BLACK%^You are stuck in the tar.%^RESET%^");
            tell_room(attackers[i],"%^BOLD%^%^BLACK%^"+attackers[i]->QCN+" is stuck in the tar.%^RESET%^",attackers[i]);
        }
        else
        {
            tell_object(attackers[i],"%^BOLD%^%^BLACK%^You jump up in time and avoid being stuck.%^RESET%^");
            tell_room("%^BLACK%^"+attackers[i]->QCN+" jumps up just in time and avoids being stuck in the tar!");
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
