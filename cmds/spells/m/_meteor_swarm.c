//Meteor Swarm coded by Bane//
// Extensive damage formula change to hopefully put on par with other spells. Nienne, 03/09.
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;


void create()
{
    ::create();
    set_spell_name("meteor swarm");
    set_spell_level(([ "mage" : 9, "oracle":9 ]));
    set_mystery(({"heavens","apocalypse"}));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS meteor swarm on TARGET");
    set_damage_desc("bludgeoning damage on target on ranged touch attack, fire damage to others.");
    set_description("You call upon a swarm of meteors to slam down on your target, causing bludgeoning damage to them on a successful ranged touch attack. " +
        "The swarm of meteors explodes on contact, causing fire damage to everyone present, reduced by half on a successful reflex save. This spell is affected " +
        "by the master of elements feat.");
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(1);
    set_save("reflex");
    set_target_required(1);
}


void spell_effect(int prof)
{
    object *foes, mycolor, element, mess;
    int i, roll;

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

    element = (string)caster->query("elementalist");

    switch(element)
    {
    case "acid":        mycolor = "%^GREEN%^";      break;
    case "electricity": mycolor = "%^ORANGE%^";     break;
    case "fire":        mycolor = "%^RED%^";        break;
    case "sonic":       mycolor = "%^MAGENTA%^";    break;
    default:            mycolor = "%^RED%^"; element = "fire";  break;
    }
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    if(!roll)
    {
        tell_room(place, "%^YELLOW%^" + target->QCN + " leaps to the side as a hissing meteor slams into the ground, avoiding some of the damage!%^RESET%^", ({ target }));
        tell_object(target, "%^YELLOW%^You leap aside as a hissing meteor slams into the ground, avoiding some of the damage!%^RESET%^");
    }
    else
        target->cause_typed_damage(target, target->return_target_limb(), sdamage, "bludgeoning");

    switch(element)
    {
    case "acid":
        tell_object(caster,"%^BOLD%^%^GREEN%^You finish your chant and the area hisses under an explosion of searing acid!");
        tell_room(place,"%^BOLD%^%^GREEN%^"+caster->QCN+" finishes "+caster->QP+" chant and the area hisses under an explosion of searing acid!",caster);
        roll && tell_object(target,"%^GREEN%^A swarm of hissing meteors slams into you with tremendous force!");
        roll && tell_room(place,"%^GREEN%^A swarm of hissing meteors slams into "+target->QCN+" with tremendous force!",target);
        mycolor = "%^GREEN%^";
        break;
    case "cold":
        tell_object(caster,"%^BOLD%^%^CYAN%^You finish your chant and the area crackles under an explosion of chilling ice!");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" finishes "+caster->QP+" chant and the area crackles under an explosion of chilling ice!",caster);
        roll && tell_object(target,"%^CYAN%^A swarm of frozen meteors slams into you with tremendous force!");
        roll && tell_room(place,"%^CYAN%^A swarm of frozen meteors slams into "+target->QCN+" with tremendous force!",target);
        mycolor = "%^CYAN%^";
        break;
    case "electricity":
        tell_object(caster,"%^YELLOW%^You finish your chant and the area crackles with an explosion of sparks and static!");
        tell_room(place,"%^YELLOW%^"+caster->QCN+" finishes "+caster->QP+" chant and the area crackles with an explosion of sparks and static!",caster);
        roll && tell_object(target,"%^ORANGE%^A swarm of crackling meteors slams into you with tremendous force!");
        roll && tell_room(place,"%^ORANGE%^A swarm of crackling meteors slams into "+target->QCN+" with tremendous force!",target);
        mycolor = "%^ORANGE%^";
        break;
    case "sonic":
        tell_object(caster,"%^BOLD%^%^MAGENTA%^You finish your chant and the area pulses under an explosion of sound!");
        tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" finishes "+caster->QP+" chant and the area pulses under an explosion of sound!",caster);
        roll && tell_object(target,"%^MAGENTA%^A swarm of pulsing meteors slams into you with tremendous force!");
        roll && tell_room(place,"%^MAGENTA%^A swarm of pulsing meteors slams into "+target->QCN+" with tremendous force!",target);
        mycolor = "%^MAGENTA%^";
        break;
    default:
        element = "fire";
        tell_object(caster,"%^BOLD%^%^RED%^You finish your chant and the area bleeds red with an explosion of sparks and fire!");
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" finishes "+caster->QP+" chant and the area bleeds red with an explosion of sparks and fire!",caster);
        roll && tell_object(target,"%^RED%^A swarm of meteors slams into you with tremendous force!");
        roll && tell_room(place,"%^RED%^A swarm of meteors slams into "+target->QCN+" with tremendous force!",target);
        mycolor = "%^RED%^";
        break;
    }

    spell_successful();
    spell_kill(target, caster);

    foes = target_selector();
    foes -= ({ target });
    foes -= ({ caster });

    if(!sizeof(foes))
    {
        dest_effect();
        return;
    }

    foreach(object ob in foes)
    {
        if(!objectp(ob))
            continue;

        if(!do_save(foes[i], 0))
            ob->cause_typed_damage(ob, ob->return_target_limb(), sdamage, element);
        else
        {
            tell_room(place, "%^YELLOW%^" + ob->QCN + " jumps for cover, avoiding some of the damage!%^RESET%^", ({ ob }));
            tell_object(ob, "%^YELLOW%^You jump for cover, avoiding some of the damage!%^RESET%^");
            ob->cause_typed_damage(ob, ob->return_target_limb(), sdamage/2, element);
        }
    }

    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
