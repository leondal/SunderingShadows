
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("obsidian flow");
    set_spell_level(([ "druid" : 4, "mage" : 4,"oracle":4]));
    set_spell_sphere("alteration");
    set_mystery(({"dragon", "stone"}));
    set_syntax("cast CLASS obsidian flow");
    set_damage_desc("fire, trips targets");
    set_description("You convert a thin layer of the ground below your enemiesto molten glass that cools quickly. Creatures on the glass that won't jump off in time will be burned and will trip as surface solidifies.");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    splash_spell(3);
}

string query_cast_string()
{
	tell_object(caster,"%^BOLD%^%^MAGENTA%^You can feel heat raising of the ground as you chant.");
	tell_room(place,"%^BOLD%^%^MAGENTA%^You feel heat raising of the ground as"+caster->QS+" chants.",caster);
	return "display";
}

void spell_effect(int prof)
{
    object *attackers;
    int i,dmg;
    attackers = target_selector();

    tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" utters a quick invocation and puddles of liquid obsidian appear under "+caster->QP+" enemies!%^RESET%^");
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
        if(!do_save(attackers[i],-2))
        {

            attackers[i]->set_tripped(roll_dice(1,4));
            tell_object(attackers[i],"%^BOLD%^%^MAGENTA%^You slip and trip on obsidian as it turns solid.%^RESET%^");
            tell_room(attackers[i],"%^BOLD%^%^MAGENTA%^"+attackers[i]->QCN+" slips and trip on obsidian as it turns solid.%^RESET%^",attackers[i]);
            tell_object(attackers[i],"%^BOLD%^Obsidian is so hot it burns you!%^RESET%^");
            damage_targ(attackers[i],attackers[i]->return_target_limb(),dmg,"fire");
        }
        else
        {
            tell_room("%^MAGENTA%^"+attackers[i]->QCN+" jumps off obsidian puddle just in time!");
        }
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
