#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("animus blast");
    set_spell_level(([ "mage" : 9,]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS animus blast");
    set_damage_desc("cold");
    set_description("This power enables a master of necromancy to unleash a blast of pure negative energy. The power of the blast is such that it can also sap the life energy of those nearby, as well as its main target. In addition, the  blast of negative energy can re-awaken corpses within the vicinity, raising them as the servants of the caster. This spell has no effect upon existing undead creatures. Many faiths and cultures condemn this spell and similar powers as it serves the caster's selfish, often evil, motives. Frequent users of the spell are known to be inherently evil.

To remove undead use %^ORANGE%^<dismiss undead>%^RESET%^
To command undead use %^ORANGE%^<command undead to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost undead to follow use %^ORANGE%^<command undead to follow>%^RESET%^
To check your undead pool size use %^ORANGE%^<poolsize>%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_save("reflex");
    splash_spell(3);
    evil_spell(1);
    set_components(([ "mage" : ([ "drop of blood" : 1, "bit of bone" : 1, ]), ]));
}


string query_cast_string()
{
    tell_room(place,"%^BOLD%^%^CYAN%^The air around you seems to chill suddenly as "+caster->QCN+" raises "+caster->QP+" hands.%^RESET%^",caster);
    tell_object(caster,"%^BOLD%^%^CYAN%^You raise your hands to the heavens, drawing energy from your surroundings as the air takes on a sudden chill.%^RESET%^");
    return "display";
}


void spell_effect(int prof)
{
    object *attackers,*temp,*targs,undead;
    int i,j,num,nummon,flag;
    string undeadtype,myrace;
    object controller;

    attackers = target_selector();

    if(!sizeof(attackers))
    {
        tell_object(caster,"%^BOLD%^%^WHITE%^As the energy reaches its peak, you fling your arms out to unleash its full "
            "force upon your foes! But you realise you're not fighting anyone.%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^The air seems to thicken around "+caster->QCN+"'s hands as "+caster->QS+" flings "
            +caster->QP+" arms out to unleash a shocking blast of chilling energy! It doesn't seem to affect anything.%^RESET%^",caster);
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^%^WHITE%^As the energy reaches its peak, you fling your arms out to unleash its full "
        "force upon your foes!");
    tell_room(place,"%^BOLD%^%^WHITE%^The air seems to thicken around "+caster->QCN+"'s hands as "+caster->QS+" flings "
        +caster->QP+" arms out to unleash a shocking blast of chilling energy!%^RESET%^",caster);

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i])) continue;

        if(do_save(attackers[i]))
        {
            tell_object(attackers[i],"%^BOLD%^You scramble away from the icy blast, but some of the chill still sinks into your bones!%^RESET%^");
            damage_targ(attackers[i],attackers[i]->return_target_limb(),(sdamage/2),"cold");
        }
        else
        {
            tell_object(attackers[i],"%^BOLD%^The biting chill sinks into your bones and saps your life!%^RESET%^");
            damage_targ(attackers[i],attackers[i]->return_target_limb(),sdamage,"cold");
        }
    }

    spell_successful();
    if(present("undead_controller",caster)) {
        controller = present("undead_controller",caster);
    }
    else {
        controller = new("/d/magic/obj/undead_controller");
        controller->set_caster(caster);
        controller->move(caster);
    }
    "/std/magic/raise_undead"->raise_ghosts(clevel, clevel/5, 3/2, caster, controller);
    dest_effect();
    return;
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
